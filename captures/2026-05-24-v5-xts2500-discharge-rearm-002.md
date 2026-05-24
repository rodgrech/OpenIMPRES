# 2026-05-24 V5 XTS2500 Discharge Rearm 002

- Bench label: XTS2500
- Model: NNTN6263A
- Serial: 5000011A25B4
- Chemistry: NiMH
- Charger/display state: discharge
- Display/amped speaker connected: unknown
- Sketch: `OpenIMPRES_V5_DS2433_Read_Map`
- Notes: Battery stayed inserted; reader was rearmed without removing the pack.
  This is another short steady-state discharge polling burst.

## Summary

```json
{
  "sketch": "OpenIMPRES_V5_DS2433_Read_Map",
  "pulse_count": 1551,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 18000,
  "max_transactions": 128,
  "reset_like_count": 21,
  "presence_like_count": 21,
  "transaction_count": 21,
  "ds2433_read_count": 5,
  "ds2438_match_count": 7,
  "print_transactions": false
}
```

## Key Transactions

- DS2433 `0x01E6`:
  `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01`
- DS2433 `0x01E6` repeat:
  `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01`
- DS2433 `0x01CB`:
  `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF`
- DS2433 `0x01CB` repeat:
  `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF`
- DS2433 `0x01CB` partial tail:
  `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF`
- DS2438 page-like operations:
  `55:A6:FB:88:1A:01:00:50:DA:B8:01`
  `55:A6:FB:88:1A:01:00:50:DA:BE:01:FF`
  `55:A6:FB:88:1A:01:00:50:DA:B4`
  `55:A6:FB:88:1A:01:00:50:DA:B8:00`
  `55:A6:FB:88:1A:01:00:50:DA:BE:00:FF`

