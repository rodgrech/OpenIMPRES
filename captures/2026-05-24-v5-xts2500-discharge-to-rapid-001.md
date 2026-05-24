# 2026-05-24 V5 XTS2500 Discharge To Rapid 001

- Bench label: XTS2500
- Model: NNTN6263A
- Serial: 5000011A25B4
- Chemistry: NiMH
- Charger/display state: discharge to rapid charge transition
- Display/amped speaker connected: unknown
- Sketch: `OpenIMPRES_V5_DS2433_Read_Map`
- Notes: User observed the charger state change from discharge to rapid charge
  on this pass. This burst keeps the steady-state `0x01E6` polling and shows a
  suspect DS2438-like row with ROM byte `5A` instead of the stable `DA`; treat
  that as a decode wobble unless repeated.

## Summary

```json
{
  "sketch": "OpenIMPRES_V5_DS2433_Read_Map",
  "pulse_count": 4130,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 18000,
  "max_transactions": 128,
  "reset_like_count": 41,
  "presence_like_count": 41,
  "transaction_count": 41,
  "ds2433_read_count": 3,
  "ds2438_match_count": 2,
  "print_transactions": false
}
```

## Key Transactions

- DS2433 `0x01E6`:
  `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01`
- DS2433 `0x01E6` repeat:
  `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01`
- DS2433 suspect/partial high address `0x80E5`:
  `55:A3:B4:25:1A:01:00:50:9D:F0:E5:80:FF:FF`
- DS2438 stable page-like operations:
  `55:A6:FB:88:1A:01:00:50:DA:B8:01`
  `55:A6:FB:88:1A:01:00:50:DA:BE:01:FF:FF`
- Suspect DS2438-like decode wobble:
  `55:A6:FB:88:1A:01:00:50:5A:DC`

