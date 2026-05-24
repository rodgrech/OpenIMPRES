# 2026-05-24 V4 VHF Maintenance Discharging 002

- Bench label: VHF
- Model: PMNN4807A
- Serial: 50000387BCFC
- Chemistry: Li-Ion
- Charger/display state: maintenance mode / discharging
- Display/amped speaker connected: unknown
- Sketch: `OpenIMPRES_V4_OneWire_Detail_Decoder`
- Notes: Second V4 maintenance/discharging capture. Capture did not saturate and
  repeated the VHF DS2433/DS2438 ROM selections with structured read addresses.

## Summary

```json
{
  "sketch": "OpenIMPRES_V4_OneWire_Detail_Decoder",
  "pulse_count": 10413,
  "capture_saturated": false,
  "capture_ms": 2500,
  "max_pulses": 16000,
  "max_transactions": 128,
  "reset_like_count": 100,
  "presence_like_count": 101,
  "transaction_count": 100,
  "printed_transaction_count": 80,
  "print_interesting_only": true
}
```

## Key Transactions

- DS2433 candidate/search evidence:
  `F0:A3:FA:7F:DE:C3:0F:00:40:F9`
- DS2433 read at `0x0041`:
  `55:A3:FC:BC:87:03:00:50:3E:F0:41:00:FF:FF:FF:FF`
- DS2438 selections:
  `55:A6:D5:89:C5:40:00:50:B3:B8:07`
  `55:A6:D5:89:C5:40:00:50:B3:BE:07:FF`
- DS2433 read at `0x004C`:
  `55:A3:FC:BC:87:03:00:50:3E:F0:4C:00`
- DS2433 read at `0x01D9`:
  `55:A3:FC:BC:87:03:00:50:3E:F0:D9:01`
- DS2433 read at `0x0048`:
  `55:A3:FC:BC:87:03:00:50:3E:F0:48:00`
- DS2433 read at `0x0060`:
  `55:A3:FC:BC:87:03:00:50:3E:F0:60:00`
- DS2433 read at `0x0148`:
  `55:A3:FC:BC:87:03:00:50:3E:F0:48:01:FF`
- DS2433 read at `0x0000`:
  `55:A3:FC:BC:87:03:00:50:3E:F0:00:00:FF:FF:FF:FF:FF`

## Structured Detail Examples

```json
[
  {
    "index": 82,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:FC:BC:87:03:00:50:3E",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x0041",
      "likely_read_memory": true
    },
    "bytes": "55:A3:FC:BC:87:03:00:50:3E:F0:41:00:FF:FF:FF:FF"
  },
  {
    "index": 84,
    "one_wire_hint": "MATCH_ROM->DS2438_BATTERY_MONITOR",
    "one_wire_detail": {
      "selected_family": "DS2438_BATTERY_MONITOR",
      "selected_rom": "A6:D5:89:C5:40:00:50:B3",
      "op": "B8",
      "op_name": ""
    },
    "bytes": "55:A6:D5:89:C5:40:00:50:B3:B8:07"
  },
  {
    "index": 87,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:FC:BC:87:03:00:50:3E",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x004C",
      "likely_read_memory": true
    },
    "bytes": "55:A3:FC:BC:87:03:00:50:3E:F0:4C:00"
  },
  {
    "index": 89,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:FC:BC:87:03:00:50:3E",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x01D9",
      "likely_read_memory": true
    },
    "bytes": "55:A3:FC:BC:87:03:00:50:3E:F0:D9:01"
  },
  {
    "index": 99,
    "one_wire_hint": "MATCH_ROM->DS2433_EEPROM",
    "one_wire_detail": {
      "selected_family": "DS2433_EEPROM",
      "selected_rom": "A3:FC:BC:87:03:00:50:3E",
      "op": "F0",
      "op_name": "SEARCH_OR_READ_MEMORY",
      "address_le": "0x0000",
      "likely_read_memory": true
    },
    "bytes": "55:A3:FC:BC:87:03:00:50:3E:F0:00:00:FF:FF:FF:FF:FF"
  }
]
```
