# 2026-05-24 V4 UHF Rapid Charge 002

- Bench label: UHF
- Model: PMNN4807A
- Serial: unknown
- Chemistry: Li-Ion
- Charger/display state: rapid charge
- Display/amped speaker connected: unknown
- Sketch: `OpenIMPRES_V4_OneWire_Detail_Decoder`
- Notes: V4 capture after raising `MAX_PULSES` to 16000. Capture did not
  saturate. It repeated the DS2433 read-address sequence and DS2438 selections
  with structured `one_wire_detail` fields.

## Summary

```json
{
  "sketch": "OpenIMPRES_V4_OneWire_Detail_Decoder",
  "pulse_count": 7141,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 16000,
  "max_transactions": 128,
  "reset_like_count": 66,
  "presence_like_count": 67,
  "transaction_count": 66,
  "printed_transaction_count": 47,
  "print_interesting_only": true
}
```

## Key Transactions

- DS2438 candidate/search evidence:
  `F0:A6:73:BD:B3:40:A2:08:75`
- DS2438 selections:
  `55:A6:73:BD:B3:40:00:50:67:B8:07`
  `55:A6:73:BD:B3:40:00:50:67:BE:83`
- DS2433 read at `0x0041`:
  `55:A3:7E:72:07:03:00:50:E3:F0:41:00:FF:FF:FF:FF`
- DS2433 read at `0x004C`:
  `55:A3:7E:72:07:03:00:50:E3:F0:4C:00`
- DS2433 read at `0x01D9`:
  `55:A3:7E:72:07:03:00:50:E3:F0:D9:01`
- DS2433 read at `0x0048`:
  `55:A3:7E:72:07:03:00:50:E3:F0:48:00`
- DS2433 read at `0x01E9`:
  `55:A3:7E:72:07:03:00:50:E3:F0:E9:01:FF`
- DS2433 read at `0x0060`:
  `55:A3:7E:72:07:03:00:50:E3:F0:60:00`
- DS2433 read at `0x0000`:
  `55:A3:7E:72:07:03:00:50:E3:F0:00:00:FF:FF:FF:FF:FF`

## Structured Detail Examples

```json
[
  {
    "index": 30,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:7E:72:07:03:00:50:E3",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x0041",
      "likely_read_memory": true
    },
    "bytes": "55:A3:7E:72:07:03:00:50:E3:F0:41:00:FF:FF:FF:FF"
  },
  {
    "index": 48,
    "one_wire_hint": "MATCH_ROM->DS2438_BATTERY_MONITOR",
    "one_wire_detail": {
      "selected_family": "DS2438_BATTERY_MONITOR",
      "selected_rom": "A6:73:BD:B3:40:00:50:67",
      "op": "B8",
      "op_name": ""
    },
    "bytes": "55:A6:73:BD:B3:40:00:50:67:B8:07"
  },
  {
    "index": 53,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:7E:72:07:03:00:50:E3",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x004C",
      "likely_read_memory": true
    },
    "bytes": "55:A3:7E:72:07:03:00:50:E3:F0:4C:00"
  },
  {
    "index": 65,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:7E:72:07:03:00:50:E3",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x0000",
      "likely_read_memory": true
    },
    "bytes": "55:A3:7E:72:07:03:00:50:E3:F0:00:00:FF:FF:FF:FF:FF"
  }
]
```
