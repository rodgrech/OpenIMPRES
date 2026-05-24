# 2026-05-24 V4 UHF Rapid Charge 001

- Bench label: UHF
- Model: PMNN4807A
- Serial: unknown
- Chemistry: Li-Ion
- Charger/display state: rapid charge
- Display/amped speaker connected: unknown
- Sketch: `OpenIMPRES_V4_OneWire_Detail_Decoder`
- Notes: First V4 capture. The structured `one_wire_detail` output confirmed
  useful DS2433 EEPROM read-memory annotations, but the pulse buffer saturated
  at 12000 pulses.

## Key Transactions

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
- DS2438 selections:
  `55:A6:B3:DE:59:20:00:A8:33:DC`
  `55:A6:73:BD:53:20:00:A8:93:EF:C1`

## Summary

```json
{
  "sketch": "OpenIMPRES_V4_OneWire_Detail_Decoder",
  "pulse_count": 12000,
  "capture_saturated": true,
  "capture_ms": 2500,
  "max_pulses": 12000,
  "max_transactions": 128,
  "reset_like_count": 120,
  "presence_like_count": 121,
  "transaction_count": 120,
  "printed_transaction_count": 91,
  "print_interesting_only": true
}
```

## Structured Detail Examples

```json
[
  {
    "index": 99,
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
    "index": 101,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:7E:72:07:03:00:50:E3",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x01D9",
      "likely_read_memory": true
    },
    "bytes": "55:A3:7E:72:07:03:00:50:E3:F0:D9:01"
  },
  {
    "index": 109,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:7E:72:07:03:00:50:E3",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x0048",
      "likely_read_memory": true
    },
    "bytes": "55:A3:7E:72:07:03:00:50:E3:F0:48:00"
  },
  {
    "index": 110,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:7E:72:07:03:00:50:E3",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x01E9",
      "likely_read_memory": true
    },
    "bytes": "55:A3:7E:72:07:03:00:50:E3:F0:E9:01:FF"
  },
  {
    "index": 113,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:7E:72:07:03:00:50:E3",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x0060",
      "likely_read_memory": true
    },
    "bytes": "55:A3:7E:72:07:03:00:50:E3:F0:60:00"
  }
]
```
