# Capture 2026-05-24 Display Update 002 Serial

Source: Serial capture from `COM11` at `115200`.

## Observations

- The host can open and read the Arduino/ESP serial port directly.
- The board identified as an ESP32-C3 from the ROM banner.
- The sketch armed successfully after `x` was sent.
- This capture again shows display/update traffic dominated by `55:*`.
- This output does not include `capture_saturated` or `family_counts`, which means
  the board was still running the older uploaded sketch at the time of capture.

## Raw Output

```text
ESP-ROM:esp32c3-api1-20210207

OpenIMPRES V1 Passive Family Classifier
Send x to arm. It will wait up to 60 seconds for bus activity.
armed_waiting_for_activity
activity_detected
{
  "present": false,
  "message_family": "display",
  "poll_type": "display_update",
  "fingerprint": "",
  "known_model": "unknown",
  "known_serial": "unknown",
  "current_capture_had_fingerprint": false,
  "used_last_known_battery": false,
  "pulse_count": 1541,
  "frame_count": 22,
  "frames": [
    "55:A3:FC:BC:87:03:00:50:3E:F0:E6:01",
    "55:A3:FC:BC:87:03:00:50:3E:F0:E6:01",
    "55:A6:D5:89:C5:40:00:50:B3:B8:01",
    "55:A6:D5:89:C5:40:00:50:B3:BE:01",
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF",
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF",
    "55:A3:7C:DE:C3:01:00:28:1F:78:E2:80:FF",
    "55:A6:D5:89:61:20:00:A8:59",
    "55:A6:D5:89:C5:40:00:50:53:5C",
    "55:A6:D5:89:C5:40:00:50:B3:BE:00:FF",
    "55:A6:D5:89:C5:40:00:50:B3:B8:00",
    "55:A6:D5:89:C5:40:00:50:B3:BE:00:FF"
  ]
}
```
