# 2026-05-24 V3 UHF Rapid Charge 003

- Bench label: UHF
- Model: PMNN4807A
- Serial: unknown
- Chemistry: Li-Ion
- Charger/display state: rapid charge
- Display/amped speaker connected: unknown
- Sketch: `OpenIMPRES_V3_Reset_Transaction_Profiler`
- Notes: Follow-up capture with V3 `MAX_PULSES` 10000 and
  `MAX_TRANSACTIONS` 128. Capture did not saturate either limit. It includes
  DS2438 search evidence, DS2433 search evidence, and repeated direct Match ROM
  reads from DS2433.

## Key Transactions

- DS2438 search/read-memory-looking evidence:
  `F0:A6:73:DD:D9:C0:00:A0:AE`
- DS2433 search/read-memory-looking evidence:
  `F0:A3:7E:E6:3D:18:00:80:36`
- DS2438 Match ROM examples:
  `55:A6:73:BD:B3:40:00:50:67:B8:07`
  `55:A6:73:BD:B3:40:00:50:67:BE:07`
- DS2433 Match ROM/read examples:
  `55:A3:7E:72:07:01:00:A8:71:F8:20:80:FF:FF:FF:FF`
  `55:A3:7E:72:07:03:00:50:E3:F0:4C:00`
  `55:A3:7E:72:07:03:00:50:E3:F0:48:00`
  `55:A3:7E:72:07:03:00:50:E3:F0:E9:01:FF`
  `55:A3:7E:72:07:03:00:50:E3:F0:60:00`
  `55:A3:7E:72:07:03:00:50:E3:F0:00:00:FF:FF:FF:FF:FF`

## Raw JSON

```json
{
  "sketch": "OpenIMPRES_V3_Reset_Transaction_Profiler",
  "pulse_count": 9872,
  "capture_saturated": false,
  "capture_ms": 2500,
  "reset_like_count": 95,
  "presence_like_count": 96,
  "transaction_count": 95,
  "printed_transaction_count": 52,
  "print_interesting_only": true,
  "transactions": [
    {"index":1,"one_wire_hint":"SEARCH_ROM_OR_READ_MEMORY","bytes":"F0:A6:73:DD:D9:C0:00:A0:AE"},
    {"index":2,"one_wire_hint":"SEARCH_ROM_OR_READ_MEMORY","bytes":"F0:A3:7E:E6:3D:18:00:80:36"},
    {"index":4,"one_wire_hint":"","bytes":"B0:D3:5A:37:15:09:08:E4"},
    {"index":5,"one_wire_hint":"SEARCH_ROM_OR_READ_MEMORY","bytes":"F0:C8:27:EF:C4:41:51:08:35"},
    {"index":7,"one_wire_hint":"","bytes":"21:78:28:08:00:00:23:1C:04:F0:FF:FF:FF:FF:FF"},
    {"index":8,"one_wire_hint":"","bytes":"21:38:14:04:00:80:11:0E:00:FC:FF:FF:FF:FF:FF"},
    {"index":11,"one_wire_hint":"","bytes":"10:1C:16:04:00:80:08:C7:01:FF"},
    {"index":14,"one_wire_hint":"","bytes":"20:CE:F5:CE:02:00:40:67:16:F0"},
    {"index":16,"one_wire_hint":"","bytes":"41:3A:D7:CD:02:01:40:9D:39:C1"},
    {"index":18,"one_wire_hint":"","bytes":"21:78:B2:60:00:00:14:E1:34:E0"},
    {"index":19,"one_wire_hint":"","bytes":"21:38:2C:08:00:00:F1:40:01:03:18:09:00:00"},
    {"index":20,"one_wire_hint":"","bytes":"21:78:28:08:00:80:22:FC"},
    {"index":21,"one_wire_hint":"","bytes":"10:3C:34:08:00:00:63:48:03"},
    {"index":23,"one_wire_hint":"","bytes":"21:78:28:08:00:40:22:4C:03"},
    {"index":24,"one_wire_hint":"","bytes":"21:74:58:10:00:00:C5:43:1A:30:80:11:00:01:00"},
    {"index":25,"one_wire_hint":"","bytes":"10:3A:69:10:00:00:45:F8"},
    {"index":28,"one_wire_hint":"","bytes":"10:3C:14:04:00:40:23:0C:02:FE"},
    {"index":31,"one_wire_hint":"","bytes":"44:9C:EB:4E:40:00:50:67:D8"},
    {"index":32,"one_wire_hint":"","bytes":"48:CC:75:67:01:00:50:93:0D"},
    {"index":33,"one_wire_hint":"","bytes":"10:3A:34:08:00:40:46:78:08:F8"},
    {"index":36,"one_wire_hint":"","bytes":"22:78:28:08:00:00:23:1C:00:FF"},
    {"index":39,"one_wire_hint":"","bytes":"48:3A:D7:9D:05:00:40:65:48"},
    {"index":40,"one_wire_hint":"","bytes":"44:64:BD:59:20:00:A8:33:27:F8"},
    {"index":42,"one_wire_hint":"","bytes":"60:3A:D7:9D:05:02:80:64:4E:F0"},
    {"index":43,"one_wire_hint":"","bytes":"20:B2:DE:14:08:00:EA:0C:00"},
    {"index":44,"one_wire_hint":"","bytes":"21:74:58:10:00:00:45:38:03:FE"},
    {"index":46,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:01:00:A8:71:F8:20:80:FF:FF:FF:FF"},
    {"index":48,"one_wire_hint":"","bytes":"10:3A:14:04:00:40:11:0E:01"},
    {"index":50,"one_wire_hint":"MATCH_ROM->DS2438_BATTERY_MONITOR","bytes":"55:A6:73:BD:B3:40:00:50:67:B8:07"},
    {"index":51,"one_wire_hint":"MATCH_ROM->DS2438_BATTERY_MONITOR","bytes":"55:A6:73:BD:B3:40:00:50:67:BE:07"},
    {"index":54,"one_wire_hint":"","bytes":"60:3A:D7:CD:02:01:40:65:6E:F0"},
    {"index":55,"one_wire_hint":"","bytes":"21:78:68:10:00:00:46:38:00"},
    {"index":58,"one_wire_hint":"","bytes":"61:70:68:10:00:00:22:1C:02:FE"},
    {"index":59,"one_wire_hint":"","bytes":"24:74:D8:20:00:00:44:B8:00:F8"},
    {"index":60,"one_wire_hint":"","bytes":"10:3C:14:04:00:80:F1:30:07:40"},
    {"index":66,"one_wire_hint":"","bytes":"10:3C:34:08:00:80:22"},
    {"index":70,"one_wire_hint":"","bytes":"10:7C:D8:20:00:00:8C:03:1C:10"},
    {"index":71,"one_wire_hint":"","bytes":"21:78:68:10:00:00:22"},
    {"index":74,"one_wire_hint":"","bytes":"48:CC:75:67:81:00:80:0C:05"},
    {"index":75,"one_wire_hint":"","bytes":"60:9A:75:59:00:00:64:E6:02:FE"},
    {"index":77,"one_wire_hint":"","bytes":"41:9C:EB:9D:05:02:80:3A:73:82"},
    {"index":78,"one_wire_hint":"","bytes":"41:3A:D7:9D:05:02:80:64:92:00:00:C0:01:02:10:00"},
    {"index":79,"one_wire_hint":"","bytes":"20:72:DD:2C:10:00:D4:99:13:FC"},
    {"index":82,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:4C:00"},
    {"index":83,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:4C:00"},
    {"index":84,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:71:F8:EC:80"},
    {"index":86,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:48:00"},
    {"index":87,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:48:00"},
    {"index":88,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:E9:01:FF"},
    {"index":90,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:60:00"},
    {"index":91,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:60:00"},
    {"index":94,"one_wire_hint":"MATCH_ROM->DS2433_EEPROM","bytes":"55:A3:7E:72:07:03:00:50:E3:F0:00:00:FF:FF:FF:FF:FF"}
  ]
}
```
