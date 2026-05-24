/*
  OpenIMPRES V1 Passive Family Classifier

  READ ONLY / PASSIVE SNIFFER

  Current bench wiring:
    Charger/display GND  -> ESP GND
    Charger/display DATA -> 10k resistor -> ESP GPIO4
    Charger/display +5V  -> not connected to ESP
    ESP powered via USB-C

  What this sketch does:
    - Arms on serial input
    - Waits for bus activity up to 60 seconds
    - Captures a burst
    - Decodes rough 1-Wire-ish pulse frames
    - Classifies message families:
        display_update   = frames starting 55
        battery_identity = known 10:xx fingerprints
        battery_data     = 20/21/22/24/28/40/42/44/45/48/49/51/52/60/70/etc
        noise            = tiny pulse counts / no useful frames
    - Remembers last known battery, so status-only/display-only bursts still show known battery

  Known bench batteries:
    NNTN6263A  SN 5000011A25B4  fingerprint 10:50:40:00:00:00
    PMMN4807A  SN 50000387BCFC  fingerprint 10:38:1B:02:00:80

  Notes:
    This is still a rough passive decoder. Treat unknown frames as research data.
*/

#include <Arduino.h>

#define DATA_PIN 4

#define MAX_PULSES 3600
#define MAX_FRAME_BYTES 32
#define MAX_FRAMES 60

#define ACTIVITY_TIMEOUT_MS 60000
#define CAPTURE_MS 8000

struct Pulse {
  uint16_t low;
  uint16_t high;
};

struct Frame {
  uint8_t bytes[MAX_FRAME_BYTES];
  uint8_t len;
};

Pulse pulses[MAX_PULSES];
Frame frames[MAX_FRAMES];

uint16_t pulseCount = 0;
uint8_t frameCount = 0;

String lastFingerprint = "";
String lastModel = "unknown";
String lastSerial = "unknown";
bool lastBatteryKnown = false;

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
      if (micros() - lowEnd > 1200) break;
    }

    uint32_t highEnd = micros();

    pulses[pulseCount].low = lowEnd - lowStart;
    pulses[pulseCount].high = highEnd - lowEnd;
    pulseCount++;
  }
}

int classify(uint16_t low) {
  if (low > 300) return 2;
  if (low <= 12) return 1;
  if (low >= 50 && low <= 85) return 0;
  return -1;
}

void resetFrames() {
  frameCount = 0;
  for (uint8_t i = 0; i < MAX_FRAMES; i++) {
    frames[i].len = 0;
  }
}

void decodeToFrames() {
  resetFrames();

  uint8_t currentByte = 0;
  uint8_t bitPos = 0;
  frameCount = 0;

  for (uint16_t i = 0; i < pulseCount; i++) {
    int c = classify(pulses[i].low);

    if (c == 2) {
      if (frameCount < MAX_FRAMES - 1) frameCount++;
      currentByte = 0;
      bitPos = 0;
      continue;
    }

    if (c < 0) continue;

    if (c == 1) currentByte |= (1 << bitPos);
    bitPos++;

    if (bitPos == 8) {
      if (frames[frameCount].len < MAX_FRAME_BYTES) {
        frames[frameCount].bytes[frames[frameCount].len++] = currentByte;
      }

      currentByte = 0;
      bitPos = 0;
    }
  }

  if (frameCount < MAX_FRAMES) frameCount++;
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

bool startsWithBytes(const Frame &f, const uint8_t *prefix, uint8_t len) {
  if (f.len < len) return false;

  for (uint8_t i = 0; i < len; i++) {
    if (f.bytes[i] != prefix[i]) return false;
  }

  return true;
}

bool hasPrefix(const uint8_t *prefix, uint8_t len) {
  for (uint8_t i = 0; i < frameCount; i++) {
    if (startsWithBytes(frames[i], prefix, len)) return true;
  }
  return false;
}

bool hasFrameStartingWith(uint8_t firstByte) {
  for (uint8_t i = 0; i < frameCount; i++) {
    if (frames[i].len > 0 && frames[i].bytes[0] == firstByte) return true;
  }
  return false;
}

uint8_t countFramesStartingWith(uint8_t firstByte) {
  uint8_t count = 0;

  for (uint8_t i = 0; i < frameCount; i++) {
    if (frames[i].len > 0 && frames[i].bytes[0] == firstByte) count++;
  }

  return count;
}

bool hasAnyUsefulFrame() {
  for (uint8_t i = 0; i < frameCount; i++) {
    if (frames[i].len >= 4) return true;
  }
  return false;
}

String extractPrefix6(const Frame &f) {
  if (f.len < 6) return "";

  String fp = "";
  for (uint8_t j = 0; j < 6; j++) {
    if (j > 0) fp += ":";
    fp += hexByte(f.bytes[j]);
  }

  return fp;
}

bool isKnownFingerprint(const String &fp) {
  if (fp == "10:50:40:00:00:00") return true;
  if (fp == "10:38:1B:02:00:80") return true;
  if (fp == "10:78:36:0C:00:00") return true;
  if (fp == "10:72:36:0C:00:00") return true;
  return false;
}

String knownModel(const String &fp) {
  if (fp == "10:50:40:00:00:00") return "NNTN6263A";
  if (fp == "10:38:1B:02:00:80") return "PMMN4807A";
  return "unknown";
}

String knownSerial(const String &fp) {
  if (fp == "10:50:40:00:00:00") return "5000011A25B4";
  if (fp == "10:38:1B:02:00:80") return "50000387BCFC";
  return "unknown";
}

String findFingerprint() {
  for (uint8_t i = 0; i < frameCount; i++) {
    if (frames[i].len >= 6 && frames[i].bytes[0] == 0x10) {
      String fp = extractPrefix6(frames[i]);
      if (isKnownFingerprint(fp)) return fp;
    }
  }

  for (uint8_t i = 0; i < frameCount; i++) {
    if (frames[i].len >= 6 && frames[i].bytes[0] == 0x10) {
      return extractPrefix6(frames[i]);
    }
  }

  return "";
}

void updateLastKnownBattery(const String &fp) {
  if (fp.length() == 0) return;

  lastFingerprint = fp;
  lastModel = knownModel(fp);
  lastSerial = knownSerial(fp);
  lastBatteryKnown = true;
}

uint8_t countFingerprintCandidates() {
  uint8_t count = 0;

  for (uint8_t i = 0; i < frameCount; i++) {
    if (frames[i].len >= 6 && frames[i].bytes[0] == 0x10) count++;
  }

  return count;
}

String detectPollType() {
  const uint8_t initialA[] = {0xB0, 0xD8, 0x03, 0x09};
  const uint8_t initialB[] = {0x70, 0x88, 0x02, 0x22};

  const uint8_t statusA1[] = {0xB0, 0xB1, 0x07, 0x12};
  const uint8_t statusA2[] = {0xF0, 0x40, 0x2B, 0x28};

  const uint8_t statusB1[] = {0xB0, 0xD4, 0x03, 0x89};
  const uint8_t statusB2[] = {0x70, 0x40, 0x05, 0x05};

  const uint8_t statusC1[] = {0xB0, 0xD8, 0x23, 0x12};
  const uint8_t statusC2[] = {0x70, 0x44, 0x0B, 0x14};

  const uint8_t statusD1[] = {0xB0, 0xB4, 0x47, 0x28};
  const uint8_t statusD2[] = {0x70, 0x40, 0x11, 0x02};

  const uint8_t statusE1[] = {0xB0, 0xD8, 0x07, 0x08};
  const uint8_t statusE2[] = {0x70, 0x84, 0x0A, 0x8C};

  const uint8_t statusF1[] = {0xB0, 0xB4, 0x07, 0x08};
  const uint8_t statusF2[] = {0x70, 0x88, 0x22, 0x04};

  if (pulseCount == 0) return "none";

  if (hasFrameStartingWith(0x55)) return "display_update";

  if (hasPrefix(initialA, 4) || hasPrefix(initialB, 4)) return "initial_id";
  if (hasPrefix(statusA1, 4) || hasPrefix(statusA2, 4)) return "status_a";
  if (hasPrefix(statusB1, 4) || hasPrefix(statusB2, 4)) return "status_b";
  if (hasPrefix(statusC1, 4) || hasPrefix(statusC2, 4)) return "status_c";
  if (hasPrefix(statusD1, 4) || hasPrefix(statusD2, 4)) return "status_d";
  if (hasPrefix(statusE1, 4) || hasPrefix(statusE2, 4)) return "status_e";
  if (hasPrefix(statusF1, 4) || hasPrefix(statusF2, 4)) return "status_f";

  if (hasFrameStartingWith(0x20) || hasFrameStartingWith(0x21) ||
      hasFrameStartingWith(0x22) || hasFrameStartingWith(0x24) ||
      hasFrameStartingWith(0x28) || hasFrameStartingWith(0x40) ||
      hasFrameStartingWith(0x42) || hasFrameStartingWith(0x44) ||
      hasFrameStartingWith(0x45) || hasFrameStartingWith(0x48) ||
      hasFrameStartingWith(0x49) || hasFrameStartingWith(0x51) ||
      hasFrameStartingWith(0x52) || hasFrameStartingWith(0x60) ||
      hasFrameStartingWith(0x70) || hasFrameStartingWith(0x91) ||
      hasFrameStartingWith(0xF0)) {
    return "status_only";
  }

  if (!hasAnyUsefulFrame()) return "noise";

  return "unknown";
}

String detectMessageFamily() {
  if (pulseCount == 0) return "none";
  if (!hasAnyUsefulFrame()) return "noise";
  if (hasFrameStartingWith(0x55)) return "display";
  if (findFingerprint().length() > 0) return "battery_identity_or_status";
  if (hasFrameStartingWith(0x20) || hasFrameStartingWith(0x21) ||
      hasFrameStartingWith(0x22) || hasFrameStartingWith(0x24) ||
      hasFrameStartingWith(0x28) || hasFrameStartingWith(0x40) ||
      hasFrameStartingWith(0x42) || hasFrameStartingWith(0x44) ||
      hasFrameStartingWith(0x45) || hasFrameStartingWith(0x48) ||
      hasFrameStartingWith(0x49) || hasFrameStartingWith(0x51) ||
      hasFrameStartingWith(0x52) || hasFrameStartingWith(0x60) ||
      hasFrameStartingWith(0x70) || hasFrameStartingWith(0x91) ||
      hasFrameStartingWith(0xF0)) {
    return "battery_status_or_charger_status";
  }
  return "unknown";
}

void printJson() {
  String fp = findFingerprint();
  if (fp.length() > 0) updateLastKnownBattery(fp);

  String pollType = detectPollType();
  String family = detectMessageFamily();

  bool hasCurrentFingerprint = fp.length() > 0;
  bool statusLike = (family == "display" || family == "battery_status_or_charger_status" || pollType == "status_only");
  bool present = hasCurrentFingerprint || (lastBatteryKnown && statusLike);

  String effectiveFingerprint = hasCurrentFingerprint ? fp : lastFingerprint;
  String effectiveModel = hasCurrentFingerprint ? knownModel(fp) : lastModel;
  String effectiveSerial = hasCurrentFingerprint ? knownSerial(fp) : lastSerial;

  Serial.println("{");

  Serial.print("  \"present\": ");
  Serial.print(present ? "true" : "false");
  Serial.println(",");

  Serial.print("  \"message_family\": \"");
  Serial.print(family);
  Serial.println("\",");

  Serial.print("  \"poll_type\": \"");
  Serial.print(pollType);
  Serial.println("\",");

  Serial.print("  \"fingerprint\": \"");
  Serial.print(effectiveFingerprint);
  Serial.println("\",");

  Serial.print("  \"current_fingerprint\": \"");
  Serial.print(fp);
  Serial.println("\",");

  Serial.print("  \"remembered_fingerprint\": \"");
  Serial.print(lastFingerprint);
  Serial.println("\",");

  Serial.println("  \"fingerprint_candidates\": [");
  bool firstFingerprintCandidate = true;
  for (uint8_t i = 0; i < frameCount; i++) {
    if (frames[i].len < 6 || frames[i].bytes[0] != 0x10) continue;

    if (!firstFingerprintCandidate) Serial.println(",");
    firstFingerprintCandidate = false;

    Serial.print("    \"");
    Serial.print(extractPrefix6(frames[i]));
    Serial.print("\"");
  }
  Serial.println();
  Serial.println("  ],");

  Serial.print("  \"known_model\": \"");
  Serial.print(effectiveModel);
  Serial.println("\",");

  Serial.print("  \"known_serial\": \"");
  Serial.print(effectiveSerial);
  Serial.println("\",");

  Serial.print("  \"current_capture_had_fingerprint\": ");
  Serial.print(hasCurrentFingerprint ? "true" : "false");
  Serial.println(",");

  Serial.print("  \"used_last_known_battery\": ");
  Serial.print((!hasCurrentFingerprint && lastBatteryKnown && statusLike) ? "true" : "false");
  Serial.println(",");

  Serial.print("  \"pulse_count\": ");
  Serial.print(pulseCount);
  Serial.println(",");

  Serial.print("  \"capture_saturated\": ");
  Serial.print(pulseCount >= MAX_PULSES ? "true" : "false");
  Serial.println(",");

  Serial.print("  \"frame_count\": ");
  Serial.print(frameCount);
  Serial.println(",");

  Serial.println("  \"family_counts\": {");
  Serial.print("    \"55_display\": ");
  Serial.print(countFramesStartingWith(0x55));
  Serial.println(",");
  Serial.print("    \"10_identity_or_status\": ");
  Serial.print(countFramesStartingWith(0x10));
  Serial.println(",");
  Serial.print("    \"20_status\": ");
  Serial.print(countFramesStartingWith(0x20));
  Serial.println(",");
  Serial.print("    \"70_status\": ");
  Serial.print(countFramesStartingWith(0x70));
  Serial.println();
  Serial.println("  },");

  Serial.println("  \"frames\": [");

  bool first = true;
  for (uint8_t i = 0; i < frameCount; i++) {
    if (frames[i].len == 0) continue;

    if (!first) Serial.println(",");
    first = false;

    Serial.print("    \"");
    Serial.print(frameToString(frames[i]));
    Serial.print("\"");
  }

  Serial.println();
  Serial.println("  ]");
  Serial.println("}");
}

void printTimeoutJson() {
  Serial.println("{");
  Serial.println("  \"present\": false,");
  Serial.println("  \"message_family\": \"none\",");
  Serial.println("  \"poll_type\": \"timeout\",");
  Serial.println("  \"fingerprint\": \"\",");
  Serial.println("  \"known_model\": \"unknown\",");
  Serial.println("  \"known_serial\": \"unknown\",");
  Serial.println("  \"current_capture_had_fingerprint\": false,");
  Serial.println("  \"used_last_known_battery\": false,");
  Serial.println("  \"pulse_count\": 0,");
  Serial.println("  \"frame_count\": 0,");
  Serial.println("  \"frames\": []");
  Serial.println("}");
}

void setup() {
  Serial.begin(115200);
  delay(1500);

  pinMode(DATA_PIN, INPUT);

  Serial.println();
  Serial.println("OpenIMPRES V1 Passive Family Classifier");
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
    decodeToFrames();
    printJson();
  }
}
