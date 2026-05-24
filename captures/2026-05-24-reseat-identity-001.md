# Capture 2026-05-24 Reseat Identity 001

Source: Serial capture from `COM11` at `115200`.

## Observations

- The board was read successfully with `DTR=false`, `RTS=true`.
- The capture was taken while the battery was re-seated.
- The updated sketch was running and reported `capture_saturated` plus
  `family_counts`.
- `pulse_count` reached `3600`, so the capture still saturated.
- The capture contains:
  - 14 display frames starting with `55`
  - 3 identity/status candidates starting with `10`
  - 1 status candidate starting with `20`
- The sketch selected the first `10:*` prefix as the fingerprint:
  `10:F2:DC:10:00:00`
- A later candidate, `10:72:36:0C:00:00`, looks important because previous
  handoff notes mentioned a similar display-connected candidate:
  `10:78:36:0C:00:00`

## Raw Output

```json
{
  "present": true,
  "message_family": "display",
  "poll_type": "display_update",
  "fingerprint": "10:F2:DC:10:00:00",
  "known_model": "unknown",
  "known_serial": "unknown",
  "current_capture_had_fingerprint": true,
  "used_last_known_battery": false,
  "pulse_count": 3600,
  "capture_saturated": true,
  "frame_count": 45,
  "family_counts": {
    "55_display": 14,
    "10_identity_or_status": 3,
    "20_status": 1,
    "70_status": 0
  },
  "frames": [
    "55:A3:FC:BC:87:03:00:50:3E:F0:E6:01",
    "55:A3:FC:BC:87:03:00:50:3E:F0:E6:01",
    "55:A6:D5:89:C5:40:00:50:B3:B8:01",
    "55:A6:D5:89:C5:40:00:50:B3:BE:01",
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF",
    "55:A3:FC:BC:87:03:00:50:1E:78:E2:80:FF",
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF",
    "55:A6:D5:89:C5:40:00:50:B3:B4",
    "55:A6:D5:89:C5:40:00:50:B3:B8:00",
    "55:A6:D5:89:C5:40:00:50:B3:BE:00",
    "55:A6:D5:89:C5:40:00:50:B3:B8:00",
    "55:A6:D5:89:C5:40:00:50:B3:BE:00:FF",
    "55:A6:D5:89:C5:40:00:50:B3:B8:00",
    "55:A6:D5:89:C5:40:00:50:B3:BE:00",
    "F0:56:AB:13:8B:81:08:40:9D",
    "F0:A3:FC:79:1F:0E:02:80:F2",
    "B0:88:41:48:09:24:C0",
    "F0:2A:7E:EE:D2:95:52:0A:A1",
    "30:E2:DC:21:00:00:38:30:00:F0:FF:FF:FF:FF",
    "10:F2:DC:10:00:00:1C:38:00:F0:FF:FF:FF:FF",
    "10:F2:DC:21:00:00:31:30:00:C0:FF:FF:FF:FF:FF",
    "10:72:36:0C:00:00:06:8E:01:FF",
    "52:E0:EC:10:00:00:1C:18:0C:F8:FF",
    "20:62:50:04:00:40:12:0A"
  ]
}
```

## Follow-Up

Update the firmware to print all six-byte `10:*` candidates so future captures do
not hide later, more plausible fingerprints behind the first `10:*` frame.
