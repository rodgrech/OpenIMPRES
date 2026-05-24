# Capture 2026-05-24 Insert Display Only 003

Source: Serial capture from `COM11` at `115200`.

## Observations

- The port was kept open for the whole arm/read cycle.
- Battery was inserted after arming.
- The capture did not saturate: `pulse_count` was `1544` and
  `capture_saturated` was `false`.
- The current burst had no fresh `10:*` candidates:
  - `current_capture_had_fingerprint` was `false`
  - `fingerprint_candidates` was empty
  - `10_identity_or_status` count was `0`
- The reported `fingerprint` was retained from prior sketch memory because
  `used_last_known_battery` was `true`.
- Future firmware should split current and remembered fingerprints to avoid
  confusing these cases.

## Raw Output

```json
{
  "present": true,
  "message_family": "display",
  "poll_type": "display_update",
  "fingerprint": "10:71:36:0C:00:80",
  "fingerprint_candidates": [

  ],
  "known_model": "unknown",
  "known_serial": "unknown",
  "current_capture_had_fingerprint": false,
  "used_last_known_battery": true,
  "pulse_count": 1544,
  "capture_saturated": false,
  "frame_count": 22,
  "family_counts": {
    "55_display": 12,
    "10_identity_or_status": 0,
    "20_status": 0,
    "70_status": 0
  },
  "frames": [
    "55:A3:FC:BC:87:03:00:50:3E:F0:E6:01",
    "55:A3:FC:BC:87:03:00:50:3E:F0:E6:01",
    "55:A6:D5:89:C5:40:00:50:B3:B8:01",
    "55:A6:D5:89:C5:40:00:50:B3:BE:01",
    "55:A3:FC:BC:87:03:00:50:3E:70:E2:80:FF",
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF",
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF",
    "55:A6:D5:89:C5:40:00:50:B3:B4",
    "55:A6:D5:89:C5:40:00:50:B3:B8:00",
    "55:A6:D5:89:C5:40:00:50:B3:BE:00:FF",
    "55:A6:D5:89:C5:40:00:50:B3:B8:00",
    "55:A6:D5:89:C5:40:00:50:B3:BE:00:FF"
  ]
}
```
