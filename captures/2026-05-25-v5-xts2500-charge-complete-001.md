# 2026-05-25 V5 XTS2500 Charge Complete 001

- Bench label: XTS2500
- Model: NNTN6263A
- Serial: 5000011A25B4
- Chemistry: NiMH
- Charger/display state: charge complete
- Display reading: 29% rated capacity, 598 mAh, 8.2 V
- Display/amped speaker connected: unknown
- Sketch: `OpenIMPRES_V5_DS2433_Read_Map`
- Notes: These passes were taken after the charger moved from discharge through
  rapid charge into charge complete. The earlier full insertion sweep and the
  discharge rearm bursts repeated existing 2026-05-24 captures and are omitted
  here to avoid double-counting. The stable charge-complete traffic is a short
  DS2433 poll around `0x01E6`, `0x01CB`, and newly observed `0x01B4`, plus
  DS2438 page-like traffic on stable ROM `A6:FB:88:1A:01:00:50:DA`.
  Occasional non-stable `A6:*` ROM rows are kept as suspect decode wobbles.

## Rapid/Complete Poll Burst

```json
{
  "sketch": "OpenIMPRES_V5_DS2433_Read_Map",
  "pulse_count": 1787,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 18000,
  "max_transactions": 128,
  "reset_like_count": 23,
  "presence_like_count": 23,
  "transaction_count": 23,
  "ds2433_read_count": 4,
  "ds2438_match_count": 8,
  "print_transactions": false
}
```

```json
[
  {
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01E6",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:E6:01"
  },
  {
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01CB",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF"
  },
  {
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01CB",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B8",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B8:01"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "BE",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:BE:01:FF:FF"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B8",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B8:00"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "BE",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:BE:00:FF"
  }
]
```

## Charge Complete Poll Burst A

```json
{
  "sketch": "OpenIMPRES_V5_DS2433_Read_Map",
  "pulse_count": 1090,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 18000,
  "max_transactions": 128,
  "reset_like_count": 14,
  "presence_like_count": 14,
  "transaction_count": 14,
  "ds2433_read_count": 3,
  "ds2438_match_count": 2,
  "print_transactions": false
}
```

```json
[
  {
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01E6",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:E6:01"
  },
  {
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01CB",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF"
  },
  {
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01B4",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:B4:01:FF:FF:FF"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B8",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B8:01"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "BE",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:BE:01:FF:FF"
  }
]
```

## Charge Complete Poll Burst B

```json
{
  "sketch": "OpenIMPRES_V5_DS2433_Read_Map",
  "pulse_count": 1550,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 18000,
  "max_transactions": 128,
  "reset_like_count": 21,
  "presence_like_count": 21,
  "transaction_count": 21,
  "ds2433_read_count": 5,
  "ds2438_match_count": 6,
  "print_transactions": false
}
```

```json
[
  {
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01E6",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:E6:01"
  },
  {
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "address_le": "0x01CB",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B4",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B4"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B8",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B8:00"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "BE",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:BE:00:FF"
  },
  {
    "rom": "A6:7B:84:46:00:00:94:D6",
    "op": "37",
    "suspect": true,
    "bytes": "55:A6:7B:84:46:00:00:94:D6:37:E0:FF"
  }
]
```

## DS2438 Only Complete Burst

```json
{
  "sketch": "OpenIMPRES_V5_DS2433_Read_Map",
  "pulse_count": 609,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 18000,
  "max_transactions": 128,
  "reset_like_count": 8,
  "presence_like_count": 8,
  "transaction_count": 8,
  "ds2433_read_count": 0,
  "ds2438_match_count": 5,
  "print_transactions": false
}
```

```json
[
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B4",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B4"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B8",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B8:00"
  },
  {
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "BE",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:BE:00:FF"
  },
  {
    "rom": "A6:FB:88:1A:00:00:28:6D",
    "op": "5F",
    "suspect": true,
    "bytes": "55:A6:FB:88:1A:00:00:28:6D:5F:80:FF"
  },
  {
    "rom": "A6:7B:44:8D:00:00:28:6D",
    "op": "5C",
    "suspect": true,
    "bytes": "55:A6:7B:44:8D:00:00:28:6D:5C"
  }
]
```
