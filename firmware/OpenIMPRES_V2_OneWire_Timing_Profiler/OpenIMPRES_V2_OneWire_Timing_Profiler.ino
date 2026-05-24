/*
  OpenIMPRES V2 One-Wire Timing Profiler

  READ ONLY / PASSIVE SNIFFER

  Current bench wiring:
    Charger/display GND  -> ESP GND
    Charger/display DATA -> 10k resistor -> ESP GPIO4
    Charger/display +5V  -> not connected to ESP
    ESP powered via USB-C

  This sketch is for reverse-engineering timing, not polished decoding.

  It:
    - arms on serial input
    - waits for bus activity
    - captures low/high pulse widths
    - prints timing histograms
    - prints reset/presence/slot-like counts
    - decodes rough LSB-first bytes using the current thresholds
    - prints a bounded raw pulse sample so we can tune thresholds from evidence
*/

#include <Arduino.h>

#define DATA_PIN 4

#define MAX_PULSES 5000
#define MAX_FRAME_BYTES 40
#define MAX_FRAMES 80
#define RAW_SAMPLE_PULSES 160

#define ACTIVITY_TIMEOUT_MS 60000
#define CAPTURE_MS 5000
#define IDLE_BREAK_US 1200

struct Pulse {
  uint16_t low;
  uint16_t high;
};

struct Frame {
  uint8_t bytes[MAX_FRAME_BYTES];
  uint8_t len;
  bool partial;
  uint8_t partialBits;
};

Pulse pulses[MAX_PULSES];
Frame frames[MAX_FRAMES];

uint16_t pulseCount = 0;
uint8_t frameCount = 0;

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

int classifyBitOrBreak(uint16_t low) {
  if (low > 300) return 2;
  if (low <= 15) return 1;
  if (low >= 45 && low <= 95) return 0;
  return -1;
}

void resetFrames() {
  frameCount = 0;
  for (uint8_t i = 0; i < MAX_FRAMES; i++) {
    frames[i].len = 0;
    frames[i].partial = false;
    frames[i].partialBits = 0;
  }
}

void finishPartialFrame(uint8_t bitPos) {
  if (frameCount >= MAX_FRAMES) return;
  if (bitPos > 0 || frames[frameCount].len > 0) {
    frames[frameCount].partial = bitPos > 0;
    frames[frameCount].partialBits = bitPos;
    if (frameCount < MAX_FRAMES - 1) frameCount++;
  }
}

void decodeToFrames() {
  resetFrames();

  uint8_t currentByte = 0;
  uint8_t bitPos = 0;
  frameCount = 0;

  for (uint16_t i = 0; i < pulseCount; i++) {
    int c = classifyBitOrBreak(pulses[i].low);

    if (c == 2) {
      finishPartialFrame(bitPos);
      currentByte = 0;
      bitPos = 0;
      continue;
    }

    if (c < 0) continue;

    if (c == 1) currentByte |= (1 << bitPos);
    bitPos++;

    if (bitPos == 8) {
      if (frameCount < MAX_FRAMES && frames[frameCount].len < MAX_FRAME_BYTES) {
        frames[frameCount].bytes[frames[frameCount].len++] = currentByte;
      }

      currentByte = 0;
      bitPos = 0;
    }
  }

  finishPartialFrame(bitPos);
}

String hexByte(uint8_t b) {
  char buf[3];
  snprintf(buf, sizeof(buf), "%02X", b);
  return String(buf);
}

String frameToString(const Frame &f) {
  String s = "";

  for (uint8_t i = 0; i < f.len; i++) {
    if (i > 0) s += ":";
    s += hexByte(f.bytes[i]);
  }

  return s;
}

void countTiming(uint16_t &slotOne, uint16_t &slotZero, uint16_t &resetLike,
                 uint16_t &presenceLike, uint16_t &ambiguous) {
  slotOne = 0;
  slotZero = 0;
  resetLike = 0;
  presenceLike = 0;
  ambiguous = 0;

  for (uint16_t i = 0; i < pulseCount; i++) {
    uint16_t low = pulses[i].low;

    if (low > 300) resetLike++;
    else if (low >= 90 && low <= 300) presenceLike++;
    else if (low <= 15) slotOne++;
    else if (low >= 45 && low <= 95) slotZero++;
    else ambiguous++;
  }
}

uint16_t countFirstByte(uint8_t firstByte) {
  uint16_t count = 0;
  for (uint8_t i = 0; i < frameCount; i++) {
    if (frames[i].len > 0 && frames[i].bytes[0] == firstByte) count++;
  }
  return count;
}

void printHistogram(const char *name, bool lowSide) {
  uint16_t bins[9] = {0};

  for (uint16_t i = 0; i < pulseCount; i++) {
    uint16_t v = lowSide ? pulses[i].low : pulses[i].high;

    if (v <= 15) bins[0]++;
    else if (v <= 30) bins[1]++;
    else if (v <= 60) bins[2]++;
    else if (v <= 90) bins[3]++;
    else if (v <= 150) bins[4]++;
    else if (v <= 300) bins[5]++;
    else if (v <= 600) bins[6]++;
    else if (v <= 1200) bins[7]++;
    else bins[8]++;
  }

  Serial.print("  \"");
  Serial.print(name);
  Serial.println("\": {");
  Serial.print("    \"0_15\": "); Serial.print(bins[0]); Serial.println(",");
  Serial.print("    \"16_30\": "); Serial.print(bins[1]); Serial.println(",");
  Serial.print("    \"31_60\": "); Serial.print(bins[2]); Serial.println(",");
  Serial.print("    \"61_90\": "); Serial.print(bins[3]); Serial.println(",");
  Serial.print("    \"91_150\": "); Serial.print(bins[4]); Serial.println(",");
  Serial.print("    \"151_300\": "); Serial.print(bins[5]); Serial.println(",");
  Serial.print("    \"301_600\": "); Serial.print(bins[6]); Serial.println(",");
  Serial.print("    \"601_1200\": "); Serial.print(bins[7]); Serial.println(",");
  Serial.print("    \"gt_1200\": "); Serial.println(bins[8]);
  Serial.print("  }");
}

void printJson() {
  decodeToFrames();

  uint16_t slotOne;
  uint16_t slotZero;
  uint16_t resetLike;
  uint16_t presenceLike;
  uint16_t ambiguous;
  countTiming(slotOne, slotZero, resetLike, presenceLike, ambiguous);

  Serial.println("{");
  Serial.println("  \"sketch\": \"OpenIMPRES_V2_OneWire_Timing_Profiler\",");
  Serial.print("  \"pulse_count\": ");
  Serial.print(pulseCount);
  Serial.println(",");
  Serial.print("  \"capture_saturated\": ");
  Serial.print(pulseCount >= MAX_PULSES ? "true" : "false");
  Serial.println(",");
  Serial.print("  \"capture_ms\": ");
  Serial.print(CAPTURE_MS);
  Serial.println(",");
  Serial.println("  \"timing_counts\": {");
  Serial.print("    \"slot_1_low_le_15us\": "); Serial.print(slotOne); Serial.println(",");
  Serial.print("    \"slot_0_low_45_95us\": "); Serial.print(slotZero); Serial.println(",");
  Serial.print("    \"presence_like_low_90_300us\": "); Serial.print(presenceLike); Serial.println(",");
  Serial.print("    \"reset_like_low_gt_300us\": "); Serial.print(resetLike); Serial.println(",");
  Serial.print("    \"ambiguous_low\": "); Serial.println(ambiguous);
  Serial.println("  },");
  printHistogram("low_hist_us", true);
  Serial.println(",");
  printHistogram("high_hist_us", false);
  Serial.println(",");
  Serial.print("  \"frame_count\": ");
  Serial.print(frameCount);
  Serial.println(",");
  Serial.println("  \"family_counts\": {");
  Serial.print("    \"55_display\": "); Serial.print(countFirstByte(0x55)); Serial.println(",");
  Serial.print("    \"10_identity_or_status\": "); Serial.print(countFirstByte(0x10)); Serial.println(",");
  Serial.print("    \"20_status\": "); Serial.print(countFirstByte(0x20)); Serial.println(",");
  Serial.print("    \"70_status\": "); Serial.println(countFirstByte(0x70));
  Serial.println("  },");
  Serial.println("  \"frames\": [");

  bool firstFrame = true;
  for (uint8_t i = 0; i < frameCount; i++) {
    if (frames[i].len == 0 && !frames[i].partial) continue;

    if (!firstFrame) Serial.println(",");
    firstFrame = false;

    Serial.print("    {\"bytes\":\"");
    Serial.print(frameToString(frames[i]));
    Serial.print("\",\"partial\":");
    Serial.print(frames[i].partial ? "true" : "false");
    Serial.print(",\"partial_bits\":");
    Serial.print(frames[i].partialBits);
    Serial.print("}");
  }

  Serial.println();
  Serial.println("  ],");
  Serial.println("  \"raw_pulses_sample\": [");

  uint16_t sampleCount = pulseCount < RAW_SAMPLE_PULSES ? pulseCount : RAW_SAMPLE_PULSES;
  for (uint16_t i = 0; i < sampleCount; i++) {
    if (i > 0) Serial.println(",");
    Serial.print("    {\"low\":");
    Serial.print(pulses[i].low);
    Serial.print(",\"high\":");
    Serial.print(pulses[i].high);
    Serial.print("}");
  }

  Serial.println();
  Serial.println("  ]");
  Serial.println("}");
}

void printTimeoutJson() {
  Serial.println("{");
  Serial.println("  \"sketch\": \"OpenIMPRES_V2_OneWire_Timing_Profiler\",");
  Serial.println("  \"event\": \"timeout\",");
  Serial.println("  \"pulse_count\": 0");
  Serial.println("}");
}

void setup() {
  Serial.begin(115200);
  delay(1500);

  pinMode(DATA_PIN, INPUT);

  Serial.println();
  Serial.println("OpenIMPRES V2 One-Wire Timing Profiler");
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
