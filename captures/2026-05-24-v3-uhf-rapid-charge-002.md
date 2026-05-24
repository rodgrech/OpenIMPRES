# 2026-05-24 V3 UHF Rapid Charge 002

- Bench label: UHF
- Model: PMNN4807A
- Serial: unknown
- Chemistry: Li-Ion
- Charger/display state: rapid charge
- Display/amped speaker connected: unknown
- Sketch: `OpenIMPRES_V3_Reset_Transaction_Profiler`
- Notes: Follow-up capture after raising V3 `MAX_PULSES` to 10000. Capture did
  not saturate the pulse buffer, but it reached the 64-transaction storage
  limit. It includes direct Match ROM evidence for DS2433 and DS2438.

## Key Transactions

- DS2433 search/read-memory-looking evidence:
  `F0:A3:FE:C9:3D:18:20:00:35`
- DS2433 Match ROM examples:
  `55:A3:7E:72:07:03:00:50:E3:F0:41:00:FF:FF:FF:FF`
  `55:A3:7E:72:07:03:00:50:E3:F0:4C:00`
  `55:A3:7E:72:07:03:00:50:E3:F0:D9:01`
- DS2438 Match ROM examples:
  `55:A6:73:BD:B3:40:00:50:67:B8:07`
  `55:A6:73:BD:B3:40:00:50:67:BE:07`

## Raw JSON

```json
{
  "sketch": "OpenIMPRES_V3_Reset_Transaction_Profiler",
  "pulse_count": 7238,
  "capture_saturated": false,
  "capture_ms": 2500,
  "reset_like_count": 66,
  "presence_like_count": 67,
  "transaction_count": 64,
  "printed_transaction_count": 36,
  "print_interesting_only": true,
  "transactions": [
    {"index":1,"one_wire_hint":"SEARCH_ROM_OR_READ_MEMORY","bytes":"F0:4E:E7:F6:CE:02:81:08:75"},
    {"index":2,"one_wire_hint":"SEARCH_ROM_OR_READ_MEMORY","bytes":"F0:A3:FE:C9:3D:18:20:00:35"},
    {"index":4,"one_wire_hint":"","bytes":"B0:63:CD:9B:08:41:00:4E"},
    {"index":5,"one_wire_hint":"SEARCH_ROM_OR_READ_MEMORY","bytes":"F0:A8:5F:B9:91:A9:42:A0:B4:D3"},
    {"index":7,"one_wire_hint":"","bytes":"10:3A:69:10:00:00:46:38:08:E0:FF:FF:FF:FF:FF"},
    {"index":9,"one_wire_hint":"","bytes":"10:1C:0A:02:00:A0:08:03:00:FC:FF:FF:FF:FF:FF"},
    {"index":12,"one_wire_hint":"","bytes":"21:78:28:08:00:80:22:0C:06:FC"},
    {"index":14,"one_wire_hint":"","bytes":"60:3A:D7:9D:05:02:00:92:05:FC"},
    {"index":15,"one_wire_hint":"","bytes":"41:64:BD:59:00:00:D4:19:12"},
    {"index":16,"one_wire_hint":"","bytes":"41:9C:EB:CE:02:01:40:9D:59:C1"},
    {"index":18,"one_wire_hint":"","bytes":"10:3C:74:10:00:00:22:9C:06"},
    {"index":19,"one_wire_hint":"","bytes":"61:F0:B0:20:00:00:8C:07:1A:10:C0:48:00:01:00"},
    {"index":20,"one_wire_hint":"","bytes":"24:74:28:08:00:80:22:FC"},
    {"index":23,"one_wire_hint":"","bytes":"10:3C:14:04:00:80:11:4E:03"},
    {"index":26,"one_wire_hint":"","bytes":"21:F4:50:10:00:00:62:48:01"},
    {"index":28,"one_wire_hint":"","bytes":"30:78:28:08:00:00:23:0C:06:FC"},
    {"index":30,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:41:00:FF:FF:FF:FF"},
    {"index":32,"one_wire_hint":"","bytes":"30:74:28:08:00:80:22:3C:01:FC"},
    {"index":34,"one_wire_hint":"","bytes":"20:72:DD:59:00:00:D4:99:0D"},
    {"index":38,"one_wire_hint":"","bytes":"21:72:68:10:00:80:44:38:01"},
    {"index":40,"one_wire_hint":"","bytes":"41:3A:EB:4D:40:00:50:67:16:F0"},
    {"index":42,"one_wire_hint":"","bytes":"48:CA:75:67:81:00:80:33:13:FC"},
    {"index":45,"one_wire_hint":"","bytes":"41:3A:D7:66:81:00:20:33:00"},
    {"index":46,"one_wire_hint":"","bytes":"21:78:52:10:00:00:46:38:07:FC"},
    {"index":48,"one_wire_hint":"MATCH_ROM->DS2438_BATTERY_MONITOR","bytes":"55:A6:73:BD:B3:40:00:50:67:B8:07"},
    {"index":49,"one_wire_hint":"MATCH_ROM->DS2438_BATTERY_MONITOR","bytes":"55:A6:73:BD:B3:40:00:50:67:BE:07"},
    {"index":51,"one_wire_hint":"","bytes":"10:3C:34:08:00:00:11:0E:01"},
    {"index":53,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:4C:00"},
    {"index":54,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:4C:00"},
    {"index":55,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:D9:01"},
    {"index":57,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:48:00"},
    {"index":58,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:83:01:00:A8:71:78:24:80"},
    {"index":59,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:E9:01:FF"},
    {"index":61,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:60:00"},
    {"index":62,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:83:01:00:A8:71:78:30"},
    {"index":63,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:48:01:FF"}
  ]
}
```
