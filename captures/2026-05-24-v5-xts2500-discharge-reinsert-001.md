# 2026-05-24 V5 XTS2500 Discharge Reinsert 001

- Bench label: XTS2500
- Model: NNTN6263A
- Serial: 5000011A25B4
- Chemistry: NiMH
- Charger/display state: discharge
- Display/amped speaker connected: unknown
- Sketch: `OpenIMPRES_V5_DS2433_Read_Map`
- Notes: XTS2500 battery was removed and re-added before this capture. ESP32-C3
  was powered from USB. Capture did not saturate. V5 confirmed the same DS2433
  and DS2438 ROMs as the earlier V4 XTS2500 discharge sample and added a clean
  DS2433 read at `0x0148`.

## Summary

```json
{
  "sketch": "OpenIMPRES_V5_DS2433_Read_Map",
  "pulse_count": 11297,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 18000,
  "max_transactions": 128,
  "reset_like_count": 105,
  "presence_like_count": 106,
  "transaction_count": 105,
  "ds2433_read_count": 8,
  "ds2438_match_count": 2,
  "print_transactions": false
}
```

## Key Findings

- DS2433 ROM:
  `A3:B4:25:1A:01:00:50:9D`
- DS2438 ROM:
  `A6:FB:88:1A:01:00:50:DA`
- DS2433 read addresses observed:
  `0x0000`, `0x0041`, `0x0048`, `0x004C`, `0x0148`, `0x01E9`
- DS2438 operations observed:
  `B8`, `BE`

## DS2433 Reads

```json
[
  {
    "index": 85,
    "reset_pulse_index": 9243,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "op": "F0",
    "op_name": "SEARCH_OR_READ_MEMORY",
    "address_le": "0x0041",
    "tail_byte_count": 5,
    "tail_bytes": "FF:FF:FF:FF:FF",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:41:00:FF:FF:FF:FF:FF"
  },
  {
    "index": 91,
    "reset_pulse_index": 9823,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "op": "F0",
    "op_name": "SEARCH_OR_READ_MEMORY",
    "address_le": "0x004C",
    "tail_byte_count": 0,
    "tail_bytes": "",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:4C:00"
  },
  {
    "index": 94,
    "reset_pulse_index": 10063,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "op": "F0",
    "op_name": "SEARCH_OR_READ_MEMORY",
    "address_le": "0x0048",
    "tail_byte_count": 0,
    "tail_bytes": "",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:48:00"
  },
  {
    "index": 95,
    "reset_pulse_index": 10173,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "op": "F0",
    "op_name": "SEARCH_OR_READ_MEMORY",
    "address_le": "0x0048",
    "tail_byte_count": 0,
    "tail_bytes": "",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:48:00"
  },
  {
    "index": 96,
    "reset_pulse_index": 10285,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "op": "F0",
    "op_name": "SEARCH_OR_READ_MEMORY",
    "address_le": "0x01E9",
    "tail_byte_count": 1,
    "tail_bytes": "FF",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:E9:01:FF"
  },
  {
    "index": 98,
    "reset_pulse_index": 10461,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "op": "F0",
    "op_name": "SEARCH_OR_READ_MEMORY",
    "address_le": "0x01E9",
    "tail_byte_count": 1,
    "tail_bytes": "FF",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:E9:01:FF"
  },
  {
    "index": 102,
    "reset_pulse_index": 10862,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "op": "F0",
    "op_name": "SEARCH_OR_READ_MEMORY",
    "address_le": "0x0148",
    "tail_byte_count": 2,
    "tail_bytes": "FF:FF",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:48:01:FF:FF"
  },
  {
    "index": 104,
    "reset_pulse_index": 11030,
    "rom": "A3:B4:25:1A:01:00:50:9D",
    "op": "F0",
    "op_name": "SEARCH_OR_READ_MEMORY",
    "address_le": "0x0000",
    "tail_byte_count": 5,
    "tail_bytes": "FF:FF:FF:FF:FF",
    "bytes": "55:A3:B4:25:1A:01:00:50:9D:F0:00:00:FF:FF:FF:FF:FF"
  }
]
```

## DS2438 Matches

```json
[
  {
    "index": 87,
    "reset_pulse_index": 9477,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "B8",
    "op_name": "",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:B8:07"
  },
  {
    "index": 88,
    "reset_pulse_index": 9567,
    "rom": "A6:FB:88:1A:01:00:50:DA",
    "op": "BE",
    "op_name": "",
    "bytes": "55:A6:FB:88:1A:01:00:50:DA:BE:07:FF"
  }
]
```
