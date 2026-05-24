# Capture 2026-05-24 Display Update 001

Source: Arduino IDE serial monitor output from `OpenIMPRES V1 Passive Family Classifier`.

## Observations

- Capture armed successfully and detected bus activity.
- `pulse_count` reached `1800`, which was the sketch's configured `MAX_PULSES`.
- The capture likely saturated before the full 8 second window completed.
- The decoded traffic is dominated by `55:*` display/update frames.
- No `10:*` battery fingerprint appeared in this burst, so the sketch correctly
  could not infer the battery yet.
- Frame `29:D3:EA:C4:62:20:00:A8:59:DC` may be a bit-slip/partial decode from
  display traffic, not necessarily a separate family yet.

## Raw Output

```json
{
  "present": false,
  "message_family": "display",
  "poll_type": "display_update",
  "fingerprint": "",
  "known_model": "unknown",
  "known_serial": "unknown",
  "current_capture_had_fingerprint": false,
  "used_last_known_battery": false,
  "pulse_count": 1800,
  "frame_count": 23,
  "frames": [
    "55:43:7E:DE:C3:01:00:28:1F:78:F3:80",
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:80:FF",
    "55:A6:D5:89:C5:40:00:50:B3:B8:01",
    "55:A6:D5:89:C5:40:00:50:B3:BE:01",
    "55:A6:D5:89:C5:40:00:50:B3:B8:01",
    "55:A6:D5:89:22:10:00:D4:CC:37:E0",
    "29:D3:EA:C4:62:20:00:A8:59:DC",
    "55:A6:D5:89:C5:40:00:50:B3:BE:01",
    "55:A3:FC:BC:87:03:00:50:3E:F0:E6:01",
    "55:A3:FC:BC:87:03:00:50:3E:F0:E6:01",
    "55:A6:D5:89:C5:40:00:50:B3:B8:01",
    "55:A6:D5:89:C5:40:00:50:B3:BE:01",
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF",
    "55:A3:FC:BC:87:03:00:50:3E:F0:C4:01"
  ]
}
```

## Next Capture Request

Repeat with the exact display text recorded beside the serial output. Then take a
second capture by arming the sketch and immediately re-seating/inserting the
battery so the initial `10:*` identity traffic has a better chance of appearing
before display chatter fills the buffer.
