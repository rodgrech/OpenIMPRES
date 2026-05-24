# 2026-05-24 V5 XTS2500 Discharge Rearm 001

- Bench label: XTS2500
- Model: NNTN6263A
- Serial: 5000011A25B4
- Chemistry: NiMH
- Charger/display state: discharge
- Display/amped speaker connected: unknown
- Sketch: `OpenIMPRES_V5_DS2433_Read_Map`
- Notes: Battery stayed inserted; reader was rearmed without removing the pack.
  One arm saw only four reset-like pulses and no decoded device traffic. A later
  arm repeated the full insert-like read sweep already captured in
  `2026-05-24-v5-xts2500-discharge-reinsert-001.md`; this note records the
  shorter follow-up polling bursts so the generated analysis highlights the
  additional addresses without double-counting the repeated full sweep.

## Empty Rearm Summary

```json
{
  "sketch": "OpenIMPRES_V5_DS2433_Read_Map",
  "pulse_count": 4,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 18000,
  "max_transactions": 128,
  "reset_like_count": 4,
  "presence_like_count": 0,
  "transaction_count": 4,
  "ds2433_read_count": 0,
  "ds2438_match_count": 0,
  "print_transactions": false
}
```

## Short Poll Burst A

```json
{
  "sketch": "OpenIMPRES_V5_DS2433_Read_Map",
  "pulse_count": 864,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 18000,
  "max_transactions": 128,
  "reset_like_count": 11,
  "presence_like_count": 11,
  "transaction_count": 11,
  "ds2433_read_count": 3,
  "ds2438_match_count": 2,
  "print_transactions": false
}
```

```json
[
  {
    "index": 1,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01E6",
    "tail_byte_count": 0,
    "tail_bytes": "",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:E6:01"
  },
  {
    "index": 3,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01CB",
    "tail_byte_count": 3,
    "tail_bytes": "FF:FF:FF",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF"
  },
  {
    "index": 8,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01CB",
    "tail_byte_count": 3,
    "tail_bytes": "FF:FF:FF",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF"
  },
  {
    "index": 5,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B8",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B8:01"
  },
  {
    "index": 6,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "BE",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:BE:01:FF:FF"
  }
]
```

## Short Poll Burst B

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

```json
[
  {
    "index": 1,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01E6",
    "tail_byte_count": 0,
    "tail_bytes": "",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:E6:01"
  },
  {
    "index": 3,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01E6",
    "tail_byte_count": 0,
    "tail_bytes": "",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:E6:01"
  },
  {
    "index": 8,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01CB",
    "tail_byte_count": 3,
    "tail_bytes": "FF:FF:FF",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF"
  },
  {
    "index": 10,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01CB",
    "tail_byte_count": 3,
    "tail_bytes": "FF:FF:FF",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF"
  },
  {
    "index": 12,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01CB",
    "tail_byte_count": 2,
    "tail_bytes": "FF:FF",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF"
  },
  {
    "index": 5,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B8",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B8:01"
  },
  {
    "index": 6,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "BE",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:BE:01:FF"
  },
  {
    "index": 14,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B4",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B4"
  },
  {
    "index": 16,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B8",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B8:00"
  },
  {
    "index": 17,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "BE",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:BE:00:FF"
  },
  {
    "index": 19,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B8",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B8:00"
  },
  {
    "index": 20,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "BE",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:BE:00:FF"
  }
]
```
