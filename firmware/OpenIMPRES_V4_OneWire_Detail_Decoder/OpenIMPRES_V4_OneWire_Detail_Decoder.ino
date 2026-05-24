/*
  OpenIMPRES V4 One-Wire Detail Decoder

  READ ONLY / PASSIVE SNIFFER

  V4 keeps the V3 reset-delimited passive capture flow, then adds structured
  annotations for common 1-Wire operations seen in IMPRES captures:
    - Match ROM to DS2433 EEPROM and DS2438 battery monitor devices
    - likely read-memory opcode/address bytes after Match ROM
    - search/read-memory-looking family candidates
*/

#include <Arduino.h>

#define DATA_PIN 4

#define MAX_PULSES 16000
#define MAX_TRANSACTIONS 128
#define MAX_TX_BYTES 40
#define PRINT_INTERESTING_ONLY true

#define ACTIVITY_TIMEOUT_MS 60000
#define CAPTURE_MS 2500
#define IDLE_BREAK_US 1200

#define ONEWIRE_MATCH_ROM 0x55
#define ONEWIRE_SEARCH_OR_READ_MEMORY 0xF0
#define ONEWIRE_READ_ROM 0x33
#define ONEWIRE_SKIP_ROM 0xCC

#define DS2433_FAMILY 0xA3
#define DS2438_FAMILY 0xA6

struct Pulse {
  uint16_t low;
  uint16_t high;
};

struct Transaction {
  uint16_t resetPulseIndex;
  uint16_t startPulseIndex;
  uint16_t endPulseIndex;
  uint16_t pulseCount;
  uint16_t slotOneCount;
  uint16_t slotZeroCount;
  uint16_t readInitCount;
  uint16_t ambiguousCount;
  uint8_t bytes[MAX_TX_BYTES];
  uint8_t byteCount;
  uint8_t partialBits;
};

Pulse pulses[MAX_PULSES];
Transaction transactions[MAX_TRANSACTIONS];

uint16_t pulseCount = 0;
uint16_t transactionCount = 0;

bool waitForActivity(uint32_t timeoutMs) {
  uint32_t start = millis();
  int last = digitalRead(DATA_PIN);

  while (millis() - start < timeoutMs) {
    int now = digitalRead(DATA_PIN);
    if (now != last) return true;
    last = now;
  }

  return false;
}

void capture(uint32_t ms) {
  pulseCount = 0;
  uint32_t endAt = millis() + ms;

  while (millis() < endAt && pulseCount < MAX_PULSES) {
    while (digitalRead(DATA_PIN) == HIGH) {
      if (millis() >= endAt) return;
    }

    uint32_t lowStart = micros();

    while (digitalRead(DATA_PIN) == LOW) {
      if (millis() >= endAt) return;
    }

    uint32_t lowEnd = micros();

    while (digitalRead(DATA_PIN) == HIGH) {
      if (millis() >= endAt) break;
      if (micros() - lowEnd > IDLE_BREAK_US) break;
    }

    uint32_t highEnd = micros();
    uint32_t low = lowEnd - lowStart;
    uint32_t high = highEnd - lowEnd;

    pulses[pulseCount].low = low > 65535 ? 65535 : low;
    pulses[pulseCount].high = high > 65535 ? 65535 : high;
    pulseCount++;
  }
}

bool isResetLike(uint16_t low) {
  return low > 300;
}

bool isPresenceLike(uint16_t low) {
  return low >= 90 && low <= 300;
}

int classifySlot(uint16_t low) {
  if (low <= 15) return 1;
  if (low >= 45 && low <= 95) return 0;
  return -1;
}

void resetTransactions() {
  transactionCount = 0;

  for (uint16_t i = 0; i < MAX_TRANSACTIONS; i++) {
    transactions[i].resetPulseIndex = 0;
    transactions[i].startPulseIndex = 0;
    transactions[i].endPulseIndex = 0;
    transactions[i].pulseCount = 0;
    transactions[i].slotOneCount = 0;
    transactions[i].slotZeroCount = 0;
    transactions[i].readInitCount = 0;
    transactions[i].ambiguousCount = 0;
    transactions[i].byteCount = 0;
    transactions[i].partialBits = 0;
  }
}

void decodeTransaction(Transaction &tx) {
  uint8_t currentByte = 0;
  uint8_t bitPos = 0;

  for (uint16_t i = tx.startPulseIndex; i <= tx.endPulseIndex && i < pulseCount; i++) {
    uint16_t low = pulses[i].low;

    if (isResetLike(low)) continue;
    if (isPresenceLike(low)) continue;

    if (low >= 16 && low <= 44) {
      tx.readInitCount++;
      continue;
    }

    int bit = classifySlot(low);
    if (bit < 0) {
      tx.ambiguousCount++;
      continue;
    }

    if (bit == 1) {
      tx.slotOneCount++;
      currentByte |= (1 << bitPos);
    } else {
      tx.slotZeroCount++;
    }

    bitPos++;

    if (bitPos == 8) {
      if (tx.byteCount < MAX_TX_BYTES) {
        tx.bytes[tx.byteCount++] = currentByte;
      }
      currentByte = 0;
      bitPos = 0;
    }
  }

  tx.partialBits = bitPos;
}

void buildTransactions() {
  resetTransactions();

  int current = -1;

  for (uint16_t i = 0; i < pulseCount; i++) {
    if (isResetLike(pulses[i].low)) {
      if (current >= 0 && transactions[current].endPulseIndex < transactions[current].startPulseIndex) {
        transactions[current].endPulseIndex = i > 0 ? i - 1 : i;
      }

      if (transactionCount >= MAX_TRANSACTIONS) {
        current = -1;
        continue;
      }

      current = transactionCount++;
      transactions[current].resetPulseIndex = i;
      transactions[current].startPulseIndex = i + 1;
      transactions[current].endPulseIndex = i;
      continue;
    }

    if (current >= 0) {
      transactions[current].endPulseIndex = i;
    }
  }

  for (uint16_t i = 0; i < transactionCount; i++) {
    Transaction &tx = transactions[i];
    if (tx.endPulseIndex >= tx.startPulseIndex) {
      tx.pulseCount = tx.endPulseIndex - tx.startPulseIndex + 1;
      decodeTransaction(tx);
    }
  }
}

String hexByte(uint8_t b) {
  char buf[3];
  snprintf(buf, sizeof(buf), "%02X", b);
  return String(buf);
}

void printBytes(const Transaction &tx) {
  for (uint8_t i = 0; i < tx.byteCount; i++) {
    if (i > 0) Serial.print(":");
    Serial.print(hexByte(tx.bytes[i]));
  }
}

void printRomFrom(const Transaction &tx, uint8_t start) {
  for (uint8_t i = 0; i < 8 && start + i < tx.byteCount; i++) {
    if (i > 0) Serial.print(":");
    Serial.print(hexByte(tx.bytes[start + i]));
  }
}

const char *familyName(uint8_t family) {
  if (family == DS2433_FAMILY) return "DS2433_EEPROM";
  if (family == DS2438_FAMILY) return "DS2438_BATTERY_MONITOR";
  return "";
}

const char *opName(uint8_t op) {
  if (op == ONEWIRE_MATCH_ROM) return "MATCH_ROM";
  if (op == ONEWIRE_SEARCH_OR_READ_MEMORY) return "SEARCH_OR_READ_MEMORY";
  if (op == ONEWIRE_READ_ROM) return "READ_ROM";
  if (op == ONEWIRE_SKIP_ROM) return "SKIP_ROM";
  return "";
}

const char *oneWireHint(const Transaction &tx) {
  if (tx.byteCount == 0) return "";

  if (tx.bytes[0] == ONEWIRE_MATCH_ROM && tx.byteCount > 1) {
    if (tx.bytes[1] == DS2433_FAMILY) return "MATCH_ROM->DS2433_EEPROM";
    if (tx.bytes[1] == DS2438_FAMILY) return "MATCH_ROM->DS2438_BATTERY_MONITOR";
    return "MATCH_ROM";
  }

  if (tx.bytes[0] == ONEWIRE_SEARCH_OR_READ_MEMORY) return "SEARCH_ROM_OR_READ_MEMORY";
  if (tx.bytes[0] == ONEWIRE_READ_ROM) return "READ_ROM";
  if (tx.bytes[0] == ONEWIRE_SKIP_ROM) return "SKIP_ROM";
  if (tx.bytes[0] == DS2433_FAMILY) return "DS2433_EEPROM";
  if (tx.bytes[0] == DS2438_FAMILY) return "DS2438_BATTERY_MONITOR";

  return "";
}

bool isInterestingTransaction(const Transaction &tx) {
  if (!PRINT_INTERESTING_ONLY) return true;
  if (tx.byteCount == 0) return false;

  uint8_t first = tx.bytes[0];
  return first == 0x10 || first == 0x20 || first == 0x21 || first == 0x22 ||
         first == 0x24 || first == 0x28 || first == 0x30 || first == 0x40 ||
         first == 0x41 || first == 0x42 || first == 0x44 || first == 0x45 ||
         first == 0x48 || first == 0x52 || first == 0x55 || first == 0x60 ||
         first == 0x61 || first == 0x70 || first == 0xB0 || first == 0xF0;
}

uint16_t countInterestingTransactions() {
  uint16_t count = 0;

  for (uint16_t i = 0; i < transactionCount; i++) {
    if (isInterestingTransaction(transactions[i])) count++;
  }

  return count;
}

void printOneWireDetail(const Transaction &tx) {
  Serial.print("{");

  bool wrote = false;

  if (tx.byteCount >= 9 && tx.bytes[0] == ONEWIRE_MATCH_ROM) {
    Serial.print("\"selected_family\":\"");
    Serial.print(familyName(tx.bytes[1]));
    Serial.print("\",\"selected_rom\":\"");
    printRomFrom(tx, 1);
    Serial.print("\"");
    wrote = true;

    if (tx.byteCount >= 10) {
      Serial.print(",\"op\":\"");
      Serial.print(hexByte(tx.bytes[9]));
      Serial.print("\",\"op_name\":\"");
      Serial.print(opName(tx.bytes[9]));
      Serial.print("\"");
    }

    if (tx.byteCount >= 12) {
      uint16_t address = ((uint16_t)tx.bytes[11] << 8) | tx.bytes[10];
      Serial.print(",\"address_le\":\"0x");
      if (address < 0x1000) Serial.print("0");
      if (address < 0x0100) Serial.print("0");
      if (address < 0x0010) Serial.print("0");
      Serial.print(address, HEX);
      Serial.print("\"");
      Serial.print(",\"likely_read_memory\":");
      Serial.print(tx.bytes[9] == ONEWIRE_SEARCH_OR_READ_MEMORY ? "true" : "false");
    }
  }

  if (tx.byteCount >= 9 && tx.bytes[0] == ONEWIRE_SEARCH_OR_READ_MEMORY && familyName(tx.bytes[1])[0] != '\0') {
    if (wrote) Serial.print(",");
    Serial.print("\"candidate_family\":\"");
    Serial.print(familyName(tx.bytes[1]));
    Serial.print("\",\"candidate_rom\":\"");
    printRomFrom(tx, 1);
    Serial.print("\"");
  }

  Serial.print("}");
}

void printJson() {
  buildTransactions();

  uint16_t resetLike = 0;
  uint16_t presenceLike = 0;
  for (uint16_t i = 0; i < pulseCount; i++) {
    if (isResetLike(pulses[i].low)) resetLike++;
    else if (isPresenceLike(pulses[i].low)) presenceLike++;
  }

  Serial.println("{");
  Serial.println("  \"sketch\": \"OpenIMPRES_V4_OneWire_Detail_Decoder\",");
  Serial.print("  \"pulse_count\": "); Serial.print(pulseCount); Serial.println(",");
  Serial.print("  \"capture_saturated\": ");
  Serial.print(pulseCount >= MAX_PULSES ? "true" : "false");
  Serial.println(",");
  Serial.print("  \"capture_ms\": "); Serial.print(CAPTURE_MS); Serial.println(",");
  Serial.print("  \"max_pulses\": "); Serial.print(MAX_PULSES); Serial.println(",");
  Serial.print("  \"max_transactions\": "); Serial.print(MAX_TRANSACTIONS); Serial.println(",");
  Serial.print("  \"reset_like_count\": "); Serial.print(resetLike); Serial.println(",");
  Serial.print("  \"presence_like_count\": "); Serial.print(presenceLike); Serial.println(",");
  Serial.print("  \"transaction_count\": "); Serial.print(transactionCount); Serial.println(",");
  Serial.print("  \"printed_transaction_count\": "); Serial.print(countInterestingTransactions()); Serial.println(",");
  Serial.print("  \"print_interesting_only\": ");
  Serial.print(PRINT_INTERESTING_ONLY ? "true" : "false");
  Serial.println(",");
  Serial.println("  \"transactions\": [");

  bool firstPrinted = true;
  for (uint16_t i = 0; i < transactionCount; i++) {
    Transaction &tx = transactions[i];
    if (!isInterestingTransaction(tx)) continue;

    if (!firstPrinted) Serial.println(",");
    firstPrinted = false;

    Serial.println("    {");
    Serial.print("      \"index\": "); Serial.print(i); Serial.println(",");
    Serial.print("      \"reset_pulse_index\": "); Serial.print(tx.resetPulseIndex); Serial.println(",");
    Serial.print("      \"reset_low_us\": "); Serial.print(pulses[tx.resetPulseIndex].low); Serial.println(",");
    Serial.print("      \"after_reset_high_us\": "); Serial.print(pulses[tx.resetPulseIndex].high); Serial.println(",");
    Serial.print("      \"pulse_count\": "); Serial.print(tx.pulseCount); Serial.println(",");
    Serial.print("      \"slot_1_count\": "); Serial.print(tx.slotOneCount); Serial.println(",");
    Serial.print("      \"slot_0_count\": "); Serial.print(tx.slotZeroCount); Serial.println(",");
    Serial.print("      \"read_init_or_mid_low_count\": "); Serial.print(tx.readInitCount); Serial.println(",");
    Serial.print("      \"ambiguous_count\": "); Serial.print(tx.ambiguousCount); Serial.println(",");
    Serial.print("      \"byte_count\": "); Serial.print(tx.byteCount); Serial.println(",");
    Serial.print("      \"partial_bits\": "); Serial.print(tx.partialBits); Serial.println(",");
    Serial.print("      \"one_wire_hint\": \""); Serial.print(oneWireHint(tx)); Serial.println("\",");
    Serial.print("      \"one_wire_detail\": "); printOneWireDetail(tx); Serial.println(",");
    Serial.print("      \"bytes\": \""); printBytes(tx); Serial.println("\"");
    Serial.print("    }");
  }

  Serial.println();
  Serial.println("  ]");
  Serial.println("}");
}

void printTimeoutJson() {
  Serial.println("{");
  Serial.println("  \"sketch\": \"OpenIMPRES_V4_OneWire_Detail_Decoder\",");
  Serial.println("  \"event\": \"timeout\",");
  Serial.println("  \"pulse_count\": 0");
  Serial.println("}");
}

void setup() {
  Serial.begin(115200);
  delay(1500);

  pinMode(DATA_PIN, INPUT);

  Serial.println();
  Serial.println("OpenIMPRES V4 One-Wire Detail Decoder");
  Serial.println("Send x to arm. It will wait up to 60 seconds for bus activity.");
}

void loop() {
  if (Serial.available()) {
    while (Serial.available()) Serial.read();

    Serial.println("armed_waiting_for_activity");

    if (!waitForActivity(ACTIVITY_TIMEOUT_MS)) {
      printTimeoutJson();
      return;
    }

    Serial.println("activity_detected");

    capture(CAPTURE_MS);
    printJson();
  }
}
