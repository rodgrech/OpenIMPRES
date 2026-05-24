# Capture 2026-05-24 Reseat Display Only 002

Source: Serial capture from `COM11` at `115200`.

## Observations

- The updated firmware was running and emitted `fingerprint_candidates`.
- `fingerprint_candidates` was empty in this run.
- The capture did not saturate: `pulse_count` was `1556` and
  `capture_saturated` was `false`.
- The capture was display-only:
  - 12 frames starting with `55`
  - 0 frames starting with `10`
  - 0 frames starting with `20`
  - 0 frames starting with `70`

## Raw Output

```json
{
  "present": false,
  "message_family": "display",
  "poll_type": "display_update",
  "fingerprint": "",
  "fingerprint_candidates": [

  ],
  "known_model": "unknown",
  "known_serial": "unknown",
  "current_capture_had_fingerprint": false,
  "used_last_known_battery": false,
  "pulse_count": 1556,
  "capture_saturated": false,
  "frame_count": 26,
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
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF",
    "55:51:7E:DE:C3:01:00:28:1F:78:E2:80:FF",
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF",
    "55:A6:D5:89:C5:40:00:50:B3:B4",
    "55:A6:D5:89:C5:40:00:50:B3:B8:00",
    "55:A6:D5:89:C5:40:00:50:B3:BE:00",
    "55:A6:D5:89:C5:40:00:50:B3:B8:00",
    "55:A6:D5:89:C5:40:00:50:B3:BE:00:FF"
  ]
}
```
