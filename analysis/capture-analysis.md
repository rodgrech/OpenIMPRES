# Capture Analysis

## Captures

- `2026-05-24-display-update-001.md`: battery `unknown`, state `unknown`, transactions 9
- `2026-05-24-display-update-002-serial.md`: battery `unknown`, state `unknown`, transactions 9
- `2026-05-24-insert-display-only-003.md`: battery `unknown`, state `unknown`, transactions 9
- `2026-05-24-reseat-display-only-002.md`: battery `unknown`, state `unknown`, transactions 9
- `2026-05-24-reseat-identity-001.md`: battery `unknown`, state `unknown`, transactions 22
- `2026-05-24-v2-insert-timing-001.md`: battery `unknown`, state `unknown`, transactions 15
- `2026-05-24-v3-insert-transactions-001.md`: battery `unknown`, state `unknown`, transactions 14
- `2026-05-24-v3-ready-go-001.md`: battery `UHF`, state `rapid charge`, transactions 25
- `2026-05-24-v3-uhf-compact-001.md`: battery `UHF`, state `conditioning mode`, transactions 17
- `2026-05-24-v3-uhf-rapid-charge-002.md`: battery `UHF`, state `rapid charge`, transactions 35
- `2026-05-24-v3-uhf-rapid-charge-003.md`: battery `UHF`, state `rapid charge`, transactions 49
- `2026-05-24-v3-vhf-compact-001.md`: battery `VHF`, state `unknown`, transactions 12
- `2026-05-24-v3-vhf-compact-002.md`: battery `VHF`, state `fully charged`, transactions 11
- `2026-05-24-v4-uhf-rapid-charge-001.md`: battery `UHF`, state `rapid charge`, transactions 8
- `2026-05-24-v4-uhf-rapid-charge-002.md`: battery `UHF`, state `rapid charge`, transactions 12
- `2026-05-24-v4-vhf-maintenance-discharging-001.md`: battery `VHF`, state `maintenance mode / discharging`, transactions 14
- `2026-05-24-v4-vhf-maintenance-discharging-002.md`: battery `VHF`, state `maintenance mode / discharging`, transactions 12
- `2026-05-24-v4-xts2500-nntn6263a-001.md`: battery `XTS2500`, state `discharge`, transactions 10
- `2026-05-24-v5-xts2500-discharge-rearm-001.md`: battery `XTS2500`, state `discharge`, transactions 12
- `2026-05-24-v5-xts2500-discharge-rearm-002.md`: battery `XTS2500`, state `discharge`, transactions 8
- `2026-05-24-v5-xts2500-discharge-reinsert-001.md`: battery `XTS2500`, state `discharge`, transactions 11
- `2026-05-24-v5-xts2500-discharge-to-rapid-001.md`: battery `XTS2500`, state `discharge to rapid charge transition`, transactions 5
- `2026-05-25-v5-xts2500-charge-complete-001.md`: battery `XTS2500`, state `charge complete`, transactions 17

## First-Byte Families

### UHF

- `55`: 37
- `10`: 32
- `21`: 21
- `F0`: 10
- `41`: 8
- `20`: 6
- `60`: 6
- `30`: 5
- `48`: 5
- `B0`: 3
- `22`: 3
- `24`: 3
- `61`: 2
- `44`: 2
- `A3`: 2
- `A6`: 1

### VHF

- `55`: 21
- `10`: 18
- `F0`: 3
- `A3`: 2
- `A6`: 2
- `28`: 1
- `30`: 1
- `24`: 1

### XTS2500

- `55`: 50
- `A6`: 7
- `A3`: 4
- `FF`: 2

### unknown

- `55`: 45
- `10`: 26
- `30`: 4
- `F0`: 3
- `20`: 2
- `28`: 2
- `29`: 1
- `B0`: 1
- `52`: 1
- `70`: 1
- `21`: 1

## Common Prefixes

### UHF prefix length 6

- `55:A3:7E:72:07:03`: 25
- `55:A6:73:BD:B3:40`: 6
- `10:3C:34:08:00:00`: 4
- `10:3C:14:04:00:40`: 3
- `21:74:58:10:00:00`: 3
- `60:3A:D7:9D:05:02`: 3
- `21:78:68:10:00:00`: 3
- `55:A3:7E:72:83:01`: 3
- `30:F4:50:10:00:00`: 2
- `22:78:28:08:00:00`: 2
- `41:3A:D7:9D:05:02`: 2
- `30:78:28:08:00:00`: 2
- `10:3C:74:10:00:00`: 2
- `24:74:28:08:00:80`: 2
- `10:3C:6C:10:00:80`: 2
- `10:1C:16:04:00:80`: 2
- `10:3A:69:10:00:00`: 2
- `21:78:28:08:00:80`: 2
- `10:3C:14:04:00:80`: 2
- `A3:7E:72:07:03:00`: 2
- `F0:56:E7:7A:CF:22`: 1
- `F0:A3:FD:C9:1D:19`: 1
- `B0:98:B9:09:00:00`: 1
- `F0:54:3F:B9:A3:56`: 1
- `22:38:14:04:00:40`: 1
- `48:3A:D7:9D:05:02`: 1
- `21:38:34:08:00:00`: 1
- `21:78:58:10:00:00`: 1
- `10:39:34:08:00:40`: 1
- `20:9D:EB:CE:02:00`: 1

### VHF prefix length 6

- `55:A3:FC:BC:87:03`: 15
- `55:A6:D5:89:C5:40`: 6
- `10:38:1B:02:00:80`: 4
- `10:38:1B:06:00:00`: 3
- `10:38:1B:02:00:50`: 2
- `10:65:36:0C:00:00`: 2
- `F0:A3:FA:7F:DE:C3`: 2
- `A3:FC:BC:87:03:00`: 2
- `A6:D5:89:C5:40:00`: 2
- `10:38:1B:06:00:20`: 1
- `10:38:1B:06:00:A0`: 1
- `28:70:36:0C:00:00`: 1
- `10:E5:6C:08:00:00`: 1
- `10:78:36:04:00:A0`: 1
- `10:38:3B:0C:00:00`: 1
- `10:E5:6C:18:00:80`: 1
- `30:70:36:0C:00:00`: 1
- `24:70:36:0C:00:20`: 1
- `F0:A6:D5:99:2E:8E`: 1

### XTS2500 prefix length 6

- `55:A3:B4:25:1A:01`: 24
- `55:A6:FB:88:1A:01`: 23
- `A3:B4:25:1A:01:00`: 4
- `A6:FB:88:1A:01:00`: 4
- `55:A6:7B:84:46:00`: 1
- `55:A6:FB:88:1A:00`: 1
- `55:A6:7B:44:8D:00`: 1
- `A6:7B:84:46:00:00`: 1
- `A6:FB:88:1A:00:00`: 1
- `A6:7B:44:8D:00:00`: 1

### unknown prefix length 6

- `55:A6:D5:89:C5:40`: 26
- `55:A3:FC:BC:87:03`: 14
- `10:38:1B:06:00:00`: 4
- `10:38:1B:02:00:80`: 4
- `10:F2:DC:10:00:00`: 2
- `10:72:36:0C:00:00`: 2
- `30:70:36:0C:00:40`: 2
- `10:38:1B:02:00:50`: 2
- `29:D3:EA:C4:62:20`: 1
- `55:43:7E:DE:C3:01`: 1
- `55:A6:D5:89:22:10`: 1
- `55:A3:7C:DE:C3:01`: 1
- `55:A6:D5:89:61:20`: 1
- `10:71:36:0C:00:80`: 1
- `55:51:7E:DE:C3:01`: 1
- `10:78:36:0C:00:00`: 1
- `F0:56:AB:13:8B:81`: 1
- `F0:A3:FC:79:1F:0E`: 1
- `B0:88:41:48:09:24`: 1
- `F0:2A:7E:EE:D2:95`: 1
- `30:E2:DC:21:00:00`: 1
- `10:F2:DC:21:00:00`: 1
- `52:E0:EC:10:00:00`: 1
- `20:62:50:04:00:40`: 1
- `70:8C:3F:77:38:00`: 1
- `10:38:0B:03:00:80`: 1
- `10:E5:6C:08:00:00`: 1
- `20:95:89:30:10:00`: 1
- `28:70:36:0C:00:00`: 1
- `10:38:1B:06:00:A0`: 1

## One-Wire Hints

Hints are based on common 1-Wire commands plus DS2433 (`A3`) and DS2438 (`A6`) family codes observed in Motorola IMPRES gen-2 reader work.

### UHF

- `MATCH_ROM->DS2433_EEPROM`: 29
- `SEARCH_ROM_OR_READ_MEMORY`: 10
- `MATCH_ROM->DS2438_BATTERY_MONITOR`: 8
- `DS2433_EEPROM`: 2
- `DS2438_BATTERY_MONITOR`: 1

### VHF

- `MATCH_ROM->DS2433_EEPROM`: 15
- `MATCH_ROM->DS2438_BATTERY_MONITOR`: 6
- `SEARCH_ROM_OR_READ_MEMORY`: 3
- `DS2433_EEPROM`: 2
- `DS2438_BATTERY_MONITOR`: 2

### XTS2500

- `MATCH_ROM->DS2438_BATTERY_MONITOR`: 26
- `MATCH_ROM->DS2433_EEPROM`: 24
- `DS2438_BATTERY_MONITOR`: 7
- `DS2433_EEPROM`: 4

### unknown

- `MATCH_ROM->DS2438_BATTERY_MONITOR`: 28
- `MATCH_ROM->DS2433_EEPROM`: 15
- `SEARCH_ROM_OR_READ_MEMORY`: 3
- `MATCH_ROM`: 2

## Battery-Unique Prefix Candidates

### UHF unique prefix length 6

- `55:A3:7E:72:07:03`: 25
- `55:A6:73:BD:B3:40`: 6
- `10:3C:34:08:00:00`: 4
- `10:3C:14:04:00:40`: 3
- `21:74:58:10:00:00`: 3
- `60:3A:D7:9D:05:02`: 3
- `21:78:68:10:00:00`: 3
- `55:A3:7E:72:83:01`: 3
- `30:F4:50:10:00:00`: 2
- `22:78:28:08:00:00`: 2
- `41:3A:D7:9D:05:02`: 2
- `30:78:28:08:00:00`: 2
- `10:3C:74:10:00:00`: 2
- `24:74:28:08:00:80`: 2
- `10:3C:6C:10:00:80`: 2
- `10:1C:16:04:00:80`: 2
- `10:3A:69:10:00:00`: 2
- `21:78:28:08:00:80`: 2
- `10:3C:14:04:00:80`: 2
- `A3:7E:72:07:03:00`: 2
- `F0:56:E7:7A:CF:22`: 1
- `F0:A3:FD:C9:1D:19`: 1
- `B0:98:B9:09:00:00`: 1
- `F0:54:3F:B9:A3:56`: 1
- `22:38:14:04:00:40`: 1
- `48:3A:D7:9D:05:02`: 1
- `21:38:34:08:00:00`: 1
- `21:78:58:10:00:00`: 1
- `10:39:34:08:00:40`: 1
- `20:9D:EB:CE:02:00`: 1

### VHF unique prefix length 6

- `10:65:36:0C:00:00`: 2
- `F0:A3:FA:7F:DE:C3`: 2
- `A3:FC:BC:87:03:00`: 2
- `A6:D5:89:C5:40:00`: 2
- `10:38:1B:06:00:20`: 1
- `10:78:36:04:00:A0`: 1
- `10:38:3B:0C:00:00`: 1
- `10:E5:6C:18:00:80`: 1
- `24:70:36:0C:00:20`: 1
- `F0:A6:D5:99:2E:8E`: 1

### XTS2500 unique prefix length 6

- `55:A3:B4:25:1A:01`: 24
- `55:A6:FB:88:1A:01`: 23
- `A3:B4:25:1A:01:00`: 4
- `A6:FB:88:1A:01:00`: 4
- `55:A6:7B:84:46:00`: 1
- `55:A6:FB:88:1A:00`: 1
- `55:A6:7B:44:8D:00`: 1
- `A6:7B:84:46:00:00`: 1
- `A6:FB:88:1A:00:00`: 1
- `A6:7B:44:8D:00:00`: 1

## DS2433 Read-Memory Address Map

Rows include Match ROM transactions with DS2433 family code `A3` and operation `F0`. Addresses are decoded from the two bytes after `F0` as little-endian values.

| Battery | State | DS2433 ROM | Address | Count | Sources | Example Bytes |
| --- | --- | --- | --- | ---: | --- | --- |
| `UHF` | `rapid charge` | `A3:7E:72:07:03:00:50:E3` | `0x0000` | 2 | `2026-05-24-v3-uhf-rapid-charge-003.md`<br>`2026-05-24-v4-uhf-rapid-charge-002.md` | `55:A3:7E:72:07:03:00:50:E3:F0:00:00:FF:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `A3:7E:72:07:03:00:50:E3` | `0x0041` | 2 | `2026-05-24-v3-uhf-rapid-charge-002.md`<br>`2026-05-24-v4-uhf-rapid-charge-002.md` | `55:A3:7E:72:07:03:00:50:E3:F0:41:00:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `A3:7E:72:07:03:00:50:E3` | `0x0048` | 4 | `2026-05-24-v3-uhf-rapid-charge-002.md`<br>`2026-05-24-v3-uhf-rapid-charge-003.md`<br>`2026-05-24-v4-uhf-rapid-charge-001.md`<br>`2026-05-24-v4-uhf-rapid-charge-002.md` | `55:A3:7E:72:07:03:00:50:E3:F0:48:00` |
| `UHF` | `rapid charge` | `A3:7E:72:07:03:00:50:E3` | `0x004C` | 4 | `2026-05-24-v3-uhf-rapid-charge-002.md`<br>`2026-05-24-v3-uhf-rapid-charge-003.md`<br>`2026-05-24-v4-uhf-rapid-charge-001.md`<br>`2026-05-24-v4-uhf-rapid-charge-002.md` | `55:A3:7E:72:07:03:00:50:E3:F0:4C:00` |
| `UHF` | `rapid charge` | `A3:7E:72:07:03:00:50:E3` | `0x0060` | 4 | `2026-05-24-v3-uhf-rapid-charge-002.md`<br>`2026-05-24-v3-uhf-rapid-charge-003.md`<br>`2026-05-24-v4-uhf-rapid-charge-001.md`<br>`2026-05-24-v4-uhf-rapid-charge-002.md` | `55:A3:7E:72:07:03:00:50:E3:F0:60:00` |
| `UHF` | `rapid charge` | `A3:7E:72:07:03:00:50:E3` | `0x0148` | 1 | `2026-05-24-v3-uhf-rapid-charge-002.md` | `55:A3:7E:72:07:03:00:50:E3:F0:48:01:FF` |
| `UHF` | `rapid charge` | `A3:7E:72:07:03:00:50:E3` | `0x01D9` | 3 | `2026-05-24-v3-uhf-rapid-charge-002.md`<br>`2026-05-24-v4-uhf-rapid-charge-001.md`<br>`2026-05-24-v4-uhf-rapid-charge-002.md` | `55:A3:7E:72:07:03:00:50:E3:F0:D9:01` |
| `UHF` | `rapid charge` | `A3:7E:72:07:03:00:50:E3` | `0x01E9` | 4 | `2026-05-24-v3-uhf-rapid-charge-002.md`<br>`2026-05-24-v3-uhf-rapid-charge-003.md`<br>`2026-05-24-v4-uhf-rapid-charge-001.md`<br>`2026-05-24-v4-uhf-rapid-charge-002.md` | `55:A3:7E:72:07:03:00:50:E3:F0:E9:01:FF` |
| `VHF` | `fully charged` | `A3:FC:BC:87:03:00:50:3E` | `0x0041` | 1 | `2026-05-24-v3-vhf-compact-002.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:41:00:FF:FF:FF` |
| `VHF` | `maintenance mode / discharging` | `A3:FC:BC:87:03:00:50:3E` | `0x0000` | 2 | `2026-05-24-v4-vhf-maintenance-discharging-001.md`<br>`2026-05-24-v4-vhf-maintenance-discharging-002.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:00:00:FF:FF:FF:FF:FF` |
| `VHF` | `maintenance mode / discharging` | `A3:FC:BC:87:03:00:50:3E` | `0x0041` | 2 | `2026-05-24-v4-vhf-maintenance-discharging-001.md`<br>`2026-05-24-v4-vhf-maintenance-discharging-002.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:41:00:FF:FF:FF:FF` |
| `VHF` | `maintenance mode / discharging` | `A3:FC:BC:87:03:00:50:3E` | `0x0048` | 2 | `2026-05-24-v4-vhf-maintenance-discharging-001.md`<br>`2026-05-24-v4-vhf-maintenance-discharging-002.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:48:00` |
| `VHF` | `maintenance mode / discharging` | `A3:FC:BC:87:03:00:50:3E` | `0x004C` | 2 | `2026-05-24-v4-vhf-maintenance-discharging-001.md`<br>`2026-05-24-v4-vhf-maintenance-discharging-002.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:4C:00` |
| `VHF` | `maintenance mode / discharging` | `A3:FC:BC:87:03:00:50:3E` | `0x0060` | 2 | `2026-05-24-v4-vhf-maintenance-discharging-001.md`<br>`2026-05-24-v4-vhf-maintenance-discharging-002.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:60:00` |
| `VHF` | `maintenance mode / discharging` | `A3:FC:BC:87:03:00:50:3E` | `0x0148` | 2 | `2026-05-24-v4-vhf-maintenance-discharging-001.md`<br>`2026-05-24-v4-vhf-maintenance-discharging-002.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:48:01:FF` |
| `VHF` | `maintenance mode / discharging` | `A3:FC:BC:87:03:00:50:3E` | `0x01D9` | 1 | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:D9:01` |
| `VHF` | `maintenance mode / discharging` | `A3:FC:BC:87:03:00:50:3E` | `0x01E9` | 1 | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:E9:01:FF` |
| `XTS2500` | `charge complete` | `A3:B4:25:1A:01:00:50:9D` | `0x01B4` | 1 | `2026-05-25-v5-xts2500-charge-complete-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:B4:01:FF:FF:FF` |
| `XTS2500` | `charge complete` | `A3:B4:25:1A:01:00:50:9D` | `0x01CB` | 2 | `2026-05-25-v5-xts2500-charge-complete-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF` |
| `XTS2500` | `charge complete` | `A3:B4:25:1A:01:00:50:9D` | `0x01E6` | 1 | `2026-05-25-v5-xts2500-charge-complete-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01` |
| `XTS2500` | `discharge` | `A3:B4:25:1A:01:00:50:9D` | `0x0000` | 2 | `2026-05-24-v4-xts2500-nntn6263a-001.md`<br>`2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:00:00:FF:FF:FF:FF:FF` |
| `XTS2500` | `discharge` | `A3:B4:25:1A:01:00:50:9D` | `0x0041` | 2 | `2026-05-24-v4-xts2500-nntn6263a-001.md`<br>`2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:41:00:FF:FF:FF:FF:FF` |
| `XTS2500` | `discharge` | `A3:B4:25:1A:01:00:50:9D` | `0x0048` | 2 | `2026-05-24-v4-xts2500-nntn6263a-001.md`<br>`2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:48:00` |
| `XTS2500` | `discharge` | `A3:B4:25:1A:01:00:50:9D` | `0x004C` | 2 | `2026-05-24-v4-xts2500-nntn6263a-001.md`<br>`2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:4C:00` |
| `XTS2500` | `discharge` | `A3:B4:25:1A:01:00:50:9D` | `0x0060` | 1 | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:60:00` |
| `XTS2500` | `discharge` | `A3:B4:25:1A:01:00:50:9D` | `0x0148` | 1 | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:48:01:FF:FF` |
| `XTS2500` | `discharge` | `A3:B4:25:1A:01:00:50:9D` | `0x01CB` | 4 | `2026-05-24-v5-xts2500-discharge-rearm-001.md`<br>`2026-05-24-v5-xts2500-discharge-rearm-002.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF` |
| `XTS2500` | `discharge` | `A3:B4:25:1A:01:00:50:9D` | `0x01E6` | 2 | `2026-05-24-v5-xts2500-discharge-rearm-001.md`<br>`2026-05-24-v5-xts2500-discharge-rearm-002.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01` |
| `XTS2500` | `discharge` | `A3:B4:25:1A:01:00:50:9D` | `0x01E9` | 2 | `2026-05-24-v4-xts2500-nntn6263a-001.md`<br>`2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:E9:01:FF` |
| `XTS2500` | `discharge to rapid charge transition` | `A3:B4:25:1A:01:00:50:9D` | `0x01E6` | 1 | `2026-05-24-v5-xts2500-discharge-to-rapid-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01` |
| `XTS2500` | `discharge to rapid charge transition` | `A3:B4:25:1A:01:00:50:9D` | `0x80E5` | 1 | `2026-05-24-v5-xts2500-discharge-to-rapid-001.md` | `55:A3:B4:25:1A:01:00:50:9D:F0:E5:80:FF:FF` |
| `unknown` | `` | `A3:FC:BC:87:03:00:50:3E` | `0x01C4` | 6 | `2026-05-24-display-update-001.md`<br>`2026-05-24-display-update-002-serial.md`<br>`2026-05-24-insert-display-only-003.md`<br>`2026-05-24-reseat-display-only-002.md`<br>`2026-05-24-reseat-identity-001.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:C4:01` |
| `unknown` | `` | `A3:FC:BC:87:03:00:50:3E` | `0x01E6` | 5 | `2026-05-24-display-update-001.md`<br>`2026-05-24-display-update-002-serial.md`<br>`2026-05-24-insert-display-only-003.md`<br>`2026-05-24-reseat-display-only-002.md`<br>`2026-05-24-reseat-identity-001.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:E6:01` |
| `unknown` | `` | `A3:FC:BC:87:03:00:50:3E` | `0x80C4` | 1 | `2026-05-24-display-update-001.md` | `55:A3:FC:BC:87:03:00:50:3E:F0:C4:80:FF` |

## DS2433 Address Coverage

| Address | `UHF` | `VHF` | `XTS2500` | `unknown` |
| --- | --- | --- | --- | --- |
| `0x0000` | yes | yes | yes |  |
| `0x0041` | yes | yes | yes |  |
| `0x0048` | yes | yes | yes |  |
| `0x004C` | yes | yes | yes |  |
| `0x0060` | yes | yes | yes |  |
| `0x0148` | yes | yes | yes |  |
| `0x01B4` |  |  | yes |  |
| `0x01C4` |  |  |  | yes |
| `0x01CB` |  |  | yes |  |
| `0x01D9` | yes | yes |  |  |
| `0x01E6` |  |  | yes | yes |
| `0x01E9` | yes | yes | yes |  |
| `0x80C4` |  |  |  | yes |
| `0x80E5` |  |  | yes |  |

## DS2438 Match ROM Summary

| Battery | State | DS2438 ROM | Op | Count | Sources | Example Bytes |
| --- | --- | --- | --- | ---: | --- | --- |
| `UHF` | `rapid charge` | `A6:73:BD:53:20:00:A8:93` | `EF` | 1 | `2026-05-24-v4-uhf-rapid-charge-001.md` | `55:A6:73:BD:53:20:00:A8:93:EF:C1` |
| `UHF` | `rapid charge` | `A6:73:BD:B3:40:00:50:67` | `B8` | 3 | `2026-05-24-v3-uhf-rapid-charge-002.md`<br>`2026-05-24-v3-uhf-rapid-charge-003.md`<br>`2026-05-24-v4-uhf-rapid-charge-002.md` | `55:A6:73:BD:B3:40:00:50:67:B8:07` |
| `UHF` | `rapid charge` | `A6:73:BD:B3:40:00:50:67` | `BE` | 3 | `2026-05-24-v3-uhf-rapid-charge-002.md`<br>`2026-05-24-v3-uhf-rapid-charge-003.md`<br>`2026-05-24-v4-uhf-rapid-charge-002.md` | `55:A6:73:BD:B3:40:00:50:67:BE:07` |
| `UHF` | `rapid charge` | `A6:B3:DE:59:20:00:A8:33` | `DC` | 1 | `2026-05-24-v4-uhf-rapid-charge-001.md` | `55:A6:B3:DE:59:20:00:A8:33:DC` |
| `VHF` | `` | `A6:D5:89:C5:40:00:50:B3` | `B8` | 1 | `2026-05-24-v3-vhf-compact-001.md` | `55:A6:D5:89:C5:40:00:50:B3:B8:07` |
| `VHF` | `` | `A6:D5:89:C5:40:00:50:B3` | `BE` | 1 | `2026-05-24-v3-vhf-compact-001.md` | `55:A6:D5:89:C5:40:00:50:B3:BE:07:FF` |
| `VHF` | `maintenance mode / discharging` | `A6:D5:89:C5:40:00:50:B3` | `B8` | 2 | `2026-05-24-v4-vhf-maintenance-discharging-001.md`<br>`2026-05-24-v4-vhf-maintenance-discharging-002.md` | `55:A6:D5:89:C5:40:00:50:B3:B8:07` |
| `VHF` | `maintenance mode / discharging` | `A6:D5:89:C5:40:00:50:B3` | `BE` | 2 | `2026-05-24-v4-vhf-maintenance-discharging-001.md`<br>`2026-05-24-v4-vhf-maintenance-discharging-002.md` | `55:A6:D5:89:C5:40:00:50:B3:BE:07:FF` |
| `XTS2500` | `charge complete` | `A6:7B:44:8D:00:00:28:6D` | `5C` | 1 | `2026-05-25-v5-xts2500-charge-complete-001.md` | `55:A6:7B:44:8D:00:00:28:6D:5C` |
| `XTS2500` | `charge complete` | `A6:7B:84:46:00:00:94:D6` | `37` | 1 | `2026-05-25-v5-xts2500-charge-complete-001.md` | `55:A6:7B:84:46:00:00:94:D6:37:E0:FF` |
| `XTS2500` | `charge complete` | `A6:FB:88:1A:00:00:28:6D` | `5F` | 1 | `2026-05-25-v5-xts2500-charge-complete-001.md` | `55:A6:FB:88:1A:00:00:28:6D:5F:80:FF` |
| `XTS2500` | `charge complete` | `A6:FB:88:1A:01:00:50:DA` | `B4` | 1 | `2026-05-25-v5-xts2500-charge-complete-001.md` | `55:A6:FB:88:1A:01:00:50:DA:B4` |
| `XTS2500` | `charge complete` | `A6:FB:88:1A:01:00:50:DA` | `B8` | 2 | `2026-05-25-v5-xts2500-charge-complete-001.md` | `55:A6:FB:88:1A:01:00:50:DA:B8:01` |
| `XTS2500` | `charge complete` | `A6:FB:88:1A:01:00:50:DA` | `BE` | 2 | `2026-05-25-v5-xts2500-charge-complete-001.md` | `55:A6:FB:88:1A:01:00:50:DA:BE:00:FF` |
| `XTS2500` | `discharge` | `A6:FB:88:1A:01:00:50:DA` | `B4` | 2 | `2026-05-24-v5-xts2500-discharge-rearm-001.md`<br>`2026-05-24-v5-xts2500-discharge-rearm-002.md` | `55:A6:FB:88:1A:01:00:50:DA:B4` |
| `XTS2500` | `discharge` | `A6:FB:88:1A:01:00:50:DA` | `B8` | 6 | `2026-05-24-v4-xts2500-nntn6263a-001.md`<br>`2026-05-24-v5-xts2500-discharge-rearm-001.md`<br>`2026-05-24-v5-xts2500-discharge-rearm-002.md`<br>`2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `55:A6:FB:88:1A:01:00:50:DA:B8:07` |
| `XTS2500` | `discharge` | `A6:FB:88:1A:01:00:50:DA` | `BE` | 7 | `2026-05-24-v4-xts2500-nntn6263a-001.md`<br>`2026-05-24-v5-xts2500-discharge-rearm-001.md`<br>`2026-05-24-v5-xts2500-discharge-rearm-002.md`<br>`2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `55:A6:FB:88:1A:01:00:50:DA:BE:07:FF` |
| `XTS2500` | `discharge to rapid charge transition` | `A6:FB:88:1A:01:00:50:5A` | `DC` | 1 | `2026-05-24-v5-xts2500-discharge-to-rapid-001.md` | `55:A6:FB:88:1A:01:00:50:5A:DC` |
| `XTS2500` | `discharge to rapid charge transition` | `A6:FB:88:1A:01:00:50:DA` | `B8` | 1 | `2026-05-24-v5-xts2500-discharge-to-rapid-001.md` | `55:A6:FB:88:1A:01:00:50:DA:B8:01` |
| `XTS2500` | `discharge to rapid charge transition` | `A6:FB:88:1A:01:00:50:DA` | `BE` | 1 | `2026-05-24-v5-xts2500-discharge-to-rapid-001.md` | `55:A6:FB:88:1A:01:00:50:DA:BE:01:FF:FF` |
| `unknown` | `` | `A6:D5:89:22:10:00:D4:CC` | `37` | 1 | `2026-05-24-display-update-001.md` | `55:A6:D5:89:22:10:00:D4:CC:37:E0` |
| `unknown` | `` | `A6:D5:89:61:20:00:A8:59` | `` | 1 | `2026-05-24-display-update-002-serial.md` | `55:A6:D5:89:61:20:00:A8:59` |
| `unknown` | `` | `A6:D5:89:C5:40:00:50:53` | `5C` | 1 | `2026-05-24-display-update-002-serial.md` | `55:A6:D5:89:C5:40:00:50:53:5C` |
| `unknown` | `` | `A6:D5:89:C5:40:00:50:B3` | `B4` | 3 | `2026-05-24-insert-display-only-003.md`<br>`2026-05-24-reseat-display-only-002.md`<br>`2026-05-24-reseat-identity-001.md` | `55:A6:D5:89:C5:40:00:50:B3:B4` |
| `unknown` | `` | `A6:D5:89:C5:40:00:50:B3` | `B8` | 10 | `2026-05-24-display-update-001.md`<br>`2026-05-24-display-update-002-serial.md`<br>`2026-05-24-insert-display-only-003.md`<br>`2026-05-24-reseat-display-only-002.md`<br>`2026-05-24-reseat-identity-001.md`<br>`2026-05-24-v3-insert-transactions-001.md` | `55:A6:D5:89:C5:40:00:50:B3:B8:01` |
| `unknown` | `` | `A6:D5:89:C5:40:00:50:B3` | `BE` | 12 | `2026-05-24-display-update-001.md`<br>`2026-05-24-display-update-002-serial.md`<br>`2026-05-24-insert-display-only-003.md`<br>`2026-05-24-reseat-display-only-002.md`<br>`2026-05-24-reseat-identity-001.md`<br>`2026-05-24-v3-insert-transactions-001.md` | `55:A6:D5:89:C5:40:00:50:B3:BE:01` |

## Transaction Rows

| Battery | State | Source | Index | Hint | Detail | Bytes |
| --- | --- | --- | --- | --- | --- | --- |
| `unknown` | `` | `2026-05-24-display-update-001.md` | `` | `` | `` | `29:D3:EA:C4:62:20:00:A8:59:DC` |
| `unknown` | `` | `2026-05-24-display-update-001.md` | `` | `MATCH_ROM` | `` | `55:43:7E:DE:C3:01:00:28:1F:78:F3:80` |
| `unknown` | `` | `2026-05-24-display-update-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=80C4` | `55:A3:FC:BC:87:03:00:50:3E:F0:C4:80:FF` |
| `unknown` | `` | `2026-05-24-display-update-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:01` |
| `unknown` | `` | `2026-05-24-display-update-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:BE:01` |
| `unknown` | `` | `2026-05-24-display-update-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:22:10:00:D4:CC` | `55:A6:D5:89:22:10:00:D4:CC:37:E0` |
| `unknown` | `` | `2026-05-24-display-update-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01E6` | `55:A3:FC:BC:87:03:00:50:3E:F0:E6:01` |
| `unknown` | `` | `2026-05-24-display-update-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01C4` | `55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF` |
| `unknown` | `` | `2026-05-24-display-update-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01C4` | `55:A3:FC:BC:87:03:00:50:3E:F0:C4:01` |
| `unknown` | `` | `2026-05-24-display-update-002-serial.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01E6` | `55:A3:FC:BC:87:03:00:50:3E:F0:E6:01` |
| `unknown` | `` | `2026-05-24-display-update-002-serial.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:01` |
| `unknown` | `` | `2026-05-24-display-update-002-serial.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:BE:01` |
| `unknown` | `` | `2026-05-24-display-update-002-serial.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01C4` | `55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF` |
| `unknown` | `` | `2026-05-24-display-update-002-serial.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7C:DE:C3:01:00:28:1F op=78 addr=80E2` | `55:A3:7C:DE:C3:01:00:28:1F:78:E2:80:FF` |
| `unknown` | `` | `2026-05-24-display-update-002-serial.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:61:20:00:A8:59` | `55:A6:D5:89:61:20:00:A8:59` |
| `unknown` | `` | `2026-05-24-display-update-002-serial.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:53` | `55:A6:D5:89:C5:40:00:50:53:5C` |
| `unknown` | `` | `2026-05-24-display-update-002-serial.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3 op=BE addr=FF00` | `55:A6:D5:89:C5:40:00:50:B3:BE:00:FF` |
| `unknown` | `` | `2026-05-24-display-update-002-serial.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:00` |
| `unknown` | `` | `2026-05-24-insert-display-only-003.md` | `` | `` | `` | `10:71:36:0C:00:80` |
| `unknown` | `` | `2026-05-24-insert-display-only-003.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01E6` | `55:A3:FC:BC:87:03:00:50:3E:F0:E6:01` |
| `unknown` | `` | `2026-05-24-insert-display-only-003.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:01` |
| `unknown` | `` | `2026-05-24-insert-display-only-003.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:BE:01` |
| `unknown` | `` | `2026-05-24-insert-display-only-003.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=70 addr=80E2` | `55:A3:FC:BC:87:03:00:50:3E:70:E2:80:FF` |
| `unknown` | `` | `2026-05-24-insert-display-only-003.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01C4` | `55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF` |
| `unknown` | `` | `2026-05-24-insert-display-only-003.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B4` |
| `unknown` | `` | `2026-05-24-insert-display-only-003.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:00` |
| `unknown` | `` | `2026-05-24-insert-display-only-003.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3 op=BE addr=FF00` | `55:A6:D5:89:C5:40:00:50:B3:BE:00:FF` |
| `unknown` | `` | `2026-05-24-reseat-display-only-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01E6` | `55:A3:FC:BC:87:03:00:50:3E:F0:E6:01` |
| `unknown` | `` | `2026-05-24-reseat-display-only-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:01` |
| `unknown` | `` | `2026-05-24-reseat-display-only-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:BE:01` |
| `unknown` | `` | `2026-05-24-reseat-display-only-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01C4` | `55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF` |
| `unknown` | `` | `2026-05-24-reseat-display-only-002.md` | `` | `MATCH_ROM` | `` | `55:51:7E:DE:C3:01:00:28:1F:78:E2:80:FF` |
| `unknown` | `` | `2026-05-24-reseat-display-only-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B4` |
| `unknown` | `` | `2026-05-24-reseat-display-only-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:00` |
| `unknown` | `` | `2026-05-24-reseat-display-only-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:BE:00` |
| `unknown` | `` | `2026-05-24-reseat-display-only-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3 op=BE addr=FF00` | `55:A6:D5:89:C5:40:00:50:B3:BE:00:FF` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `` | `` | `10:F2:DC:10:00:00` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `` | `` | `10:72:36:0C:00:00` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `` | `` | `10:78:36:0C:00:00` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01E6` | `55:A3:FC:BC:87:03:00:50:3E:F0:E6:01` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:01` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:BE:01` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01C4` | `55:A3:FC:BC:87:03:00:50:3E:F0:C4:01:FF` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:1E op=78 addr=80E2` | `55:A3:FC:BC:87:03:00:50:1E:78:E2:80:FF` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B4` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:00` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:BE:00` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3 op=BE addr=FF00` | `55:A6:D5:89:C5:40:00:50:B3:BE:00:FF` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `` | `F0:56:AB:13:8B:81:08:40:9D` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `family=DS2433_EEPROM candidate=A3:FC:79:1F:0E:02:80:F2` | `F0:A3:FC:79:1F:0E:02:80:F2` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `` | `` | `B0:88:41:48:09:24:C0` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `` | `F0:2A:7E:EE:D2:95:52:0A:A1` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `` | `` | `30:E2:DC:21:00:00:38:30:00:F0:FF:FF:FF:FF` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `` | `` | `10:F2:DC:10:00:00:1C:38:00:F0:FF:FF:FF:FF` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `` | `` | `10:F2:DC:21:00:00:31:30:00:C0:FF:FF:FF:FF:FF` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `` | `` | `10:72:36:0C:00:00:06:8E:01:FF` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `` | `` | `52:E0:EC:10:00:00:1C:18:0C:F8:FF` |
| `unknown` | `` | `2026-05-24-reseat-identity-001.md` | `` | `` | `` | `20:62:50:04:00:40:12:0A` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `70:8C:3F:77:38:00:00:F8` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `10:38:0B:03:00:80:03:03:00:FF:FF:FF:FF:FF` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `10:E5:6C:08:00:00:06:06:00:F8:FF:FF:FF:FF` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `30:70:36:0C:00:40:19:18:04:FC` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `20:95:89:30:10:00:54:6A:01:FF` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `28:70:36:0C:00:00:0E:1C:00:FF` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `10:38:1B:06:00:00:07:4E:03` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `10:38:1B:06:00:A0:0C:FA` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `10:38:1B:02:00:50:06:4E:03` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `10:78:1A:02:00:80:03:13:01:FF` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `10:38:1B:06:00:00:03:87:80` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `28:70:76:18:00:00:1C:38:0A:F8` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `10:38:1B` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `10:38:1B:02:00:50` |
| `unknown` | `` | `2026-05-24-v2-insert-timing-001.md` | `` | `` | `` | `10:38:1B:02:00:80` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `9` | `` | `` | `10:38:1B:02:00:80:81:01:00:FE:FF:FF:FF:FF` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `36` | `` | `` | `10:38:1B:02:00:80:81:FF` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `8` | `` | `` | `30:70:36:0C:00:40:0C:1C:00:F8:FF:FF:FF:FF` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `11` | `` | `` | `21:CA:D9:30:00:00:18:38:06:FC` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `12` | `` | `` | `10:E5:6C:18:00:00:0C:0C:02:FE` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `19` | `` | `` | `30:70:36:0C:00:00:0E:1C:00:FF` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `22` | `` | `` | `10:38:1B:06:00:00:03:47:01` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `29` | `` | `` | `10:38:1B:06:00:00:03:D3:80` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `31` | `` | `` | `10:E5:DC:10:00:00:0C:FC` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `35` | `` | `` | `10:78:76:08:00:40:9C:81:06:0C:60:04:00:00:04` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `39` | `` | `` | `10:78:36:04:00:00:07:06:03:FE` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `41` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:07` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `42` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3 op=BE addr=FF07` | `55:A6:D5:89:C5:40:00:50:B3:BE:07:FF` |
| `unknown` | `` | `2026-05-24-v3-insert-transactions-001.md` | `` | `` | `` | `10:38:1B:02:00:80` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `` | `F0:56:E7:7A:CF:22:46:00:EA` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `family=DS2433_EEPROM candidate=A3:FD:C9:1D:19:00:80:1A` | `F0:A3:FD:C9:1D:19:00:80:1A` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `B0:98:B9:09:00:00:9C` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `` | `F0:54:3F:B9:A3:56:88:28:52:D3` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `30:F4:50:10:00:00:45:38:00:F0:FF:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `22:78:28:08:00:00:23:1C:00:E0:FF:FF:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `10:3C:34:08:00:00:23:9C:06:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `22:38:14:04:00:40:11:06:01:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `48:3A:D7:9D:05:02:80:64:2E:E0:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `41:3A:D7:9D:05:02:00:32:27:F8` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `21:38:34:08:00:00:23:2C:03` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `21:78:58:10:00:00:46:18:04:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `30:78:28:08:00:00:23:4C:01` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `30:F4:50:10:00:00:45:F8:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `10:39:34:08:00:40:A2:A0:80` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `10:3C:14:04:00:40:11:4E:03` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `10:3C:74:10:00:00:C5:81:02:06:30:12:00:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `21:74:58:10:00:00:C6:40:03` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `20:9D:EB:CE:02:00:40:13:0A` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `60:3A:D7:9D:05:02:00:32:17:F0:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `21:78:68:10:00:00:62:18:04:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `24:74:28:08:00:80:E2:01:04:08:00:02:00:00:00:00:00:00:40:00:00:00:00:00:00:00:00:00:C0:40` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `10:3C:14:04:00:40:11:FE` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `60:3A:D7:9D:05:00:40:32:6C` |
| `UHF` | `rapid charge` | `2026-05-24-v3-ready-go-001.md` | `` | `` | `` | `20:9D:BA:B3:40:00:50:99:0D` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `7` | `` | `` | `10:3C:6C:10:00:80:8A:30:00:F0:FF:FF:FF:FF` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `9` | `` | `` | `10:9C:14:04:00:80:08:03:00:FC:FF:FF:FF:FF` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `12` | `` | `` | `10:75:D8:20:00:00:15:61:10:F0:FF` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `19` | `` | `` | `10:75:58:10:00:80:44:18:0C:F8:FF` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `20` | `` | `` | `10:1C:36:08:00:00:11:96:01` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `26` | `` | `` | `10:3C:6C:10:00:80:8A:87:34:20:80:91:00:00:00` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `28` | `` | `` | `10:1C:16:04:00:80:18:D2:80` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `32` | `` | `` | `10:9C:14:04:00:A0:C6:F0` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `33` | `` | `` | `10:F5:A4:20:00:00:C4:90:02` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `45` | `` | `` | `10:3C:34:08:00:00:11:0E:80` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `` | `` | `` | `10:38:1B` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `` | `` | `` | `21:38:29:08:00:40:45:38:06:FC` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `` | `` | `` | `21:38:14:04:00:A0:E2:01:06:00` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `` | `` | `` | `21:38:6C:10:00:80:8A:30:18:F0:FF` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:83:01:00:A8:71 op=F8 addr=8020` | `55:A3:7E:72:83:01:00:A8:71:F8:20:80:FF:FF:FF` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `` | `` | `` | `10:3C:6C` |
| `UHF` | `conditioning mode` | `2026-05-24-v3-uhf-compact-001.md` | `` | `` | `` | `10:9C:14` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `` | `F0:4E:E7:F6:CE:02:81:08:75` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `family=DS2433_EEPROM candidate=A3:FE:C9:3D:18:20:00:35` | `F0:A3:FE:C9:3D:18:20:00:35` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `B0:63:CD:9B:08:41:00:4E` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `` | `F0:A8:5F:B9:91:A9:42:A0:B4:D3` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `10:3A:69:10:00:00:46:38:08:E0:FF:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `10:1C:0A:02:00:A0:08:03:00:FC:FF:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `21:78:28:08:00:80:22:0C:06:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `60:3A:D7:9D:05:02:00:92:05:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `41:64:BD:59:00:00:D4:19:12` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `41:9C:EB:CE:02:01:40:9D:59:C1` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `10:3C:74:10:00:00:22:9C:06` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `61:F0:B0:20:00:00:8C:07:1A:10:C0:48:00:01:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `24:74:28:08:00:80:22:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `10:3C:14:04:00:80:11:4E:03` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `21:F4:50:10:00:00:62:48:01` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `30:78:28:08:00:00:23:0C:06:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0041` | `55:A3:7E:72:07:03:00:50:E3:F0:41:00:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `30:74:28:08:00:80:22:3C:01:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `20:72:DD:59:00:00:D4:99:0D` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `21:72:68:10:00:80:44:38:01` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `41:3A:EB:4D:40:00:50:67:16:F0` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `48:CA:75:67:81:00:80:33:13:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `41:3A:D7:66:81:00:20:33:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `21:78:52:10:00:00:46:38:07:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:73:BD:B3:40:00:50:67` | `55:A6:73:BD:B3:40:00:50:67:B8:07` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:73:BD:B3:40:00:50:67` | `55:A6:73:BD:B3:40:00:50:67:BE:07` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `` | `` | `10:3C:34:08:00:00:11:0E:01` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=004C` | `55:A3:7E:72:07:03:00:50:E3:F0:4C:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=01D9` | `55:A3:7E:72:07:03:00:50:E3:F0:D9:01` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0048` | `55:A3:7E:72:07:03:00:50:E3:F0:48:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:83:01:00:A8:71 op=78 addr=8024` | `55:A3:7E:72:83:01:00:A8:71:78:24:80` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=01E9` | `55:A3:7E:72:07:03:00:50:E3:F0:E9:01:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0060` | `55:A3:7E:72:07:03:00:50:E3:F0:60:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:83:01:00:A8:71` | `55:A3:7E:72:83:01:00:A8:71:78:30` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0148` | `55:A3:7E:72:07:03:00:50:E3:F0:48:01:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `family=DS2438_BATTERY_MONITOR candidate=A6:73:DD:D9:C0:00:A0:AE` | `F0:A6:73:DD:D9:C0:00:A0:AE` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `family=DS2433_EEPROM candidate=A3:7E:E6:3D:18:00:80:36` | `F0:A3:7E:E6:3D:18:00:80:36` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `B0:D3:5A:37:15:09:08:E4` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `` | `F0:C8:27:EF:C4:41:51:08:35` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `21:78:28:08:00:00:23:1C:04:F0:FF:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `21:38:14:04:00:80:11:0E:00:FC:FF:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `10:1C:16:04:00:80:08:C7:01:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `20:CE:F5:CE:02:00:40:67:16:F0` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `41:3A:D7:CD:02:01:40:9D:39:C1` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `21:78:B2:60:00:00:14:E1:34:E0` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `21:38:2C:08:00:00:F1:40:01:03:18:09:00:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `21:78:28:08:00:80:22:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `10:3C:34:08:00:00:63:48:03` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `21:78:28:08:00:40:22:4C:03` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `21:74:58:10:00:00:C5:43:1A:30:80:11:00:01:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `10:3A:69:10:00:00:45:F8` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `10:3C:14:04:00:40:23:0C:02:FE` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `44:9C:EB:4E:40:00:50:67:D8` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `48:CC:75:67:01:00:50:93:0D` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `10:3A:34:08:00:40:46:78:08:F8` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `22:78:28:08:00:00:23:1C:00:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `48:3A:D7:9D:05:00:40:65:48` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `44:64:BD:59:20:00:A8:33:27:F8` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `60:3A:D7:9D:05:02:80:64:4E:F0` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `20:B2:DE:14:08:00:EA:0C:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `21:74:58:10:00:00:45:38:03:FE` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:01:00:A8:71 op=F8 addr=8020` | `55:A3:7E:72:07:01:00:A8:71:F8:20:80:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `10:3A:14:04:00:40:11:0E:01` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:73:BD:B3:40:00:50:67` | `55:A6:73:BD:B3:40:00:50:67:B8:07` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:73:BD:B3:40:00:50:67` | `55:A6:73:BD:B3:40:00:50:67:BE:07` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `60:3A:D7:CD:02:01:40:65:6E:F0` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `21:78:68:10:00:00:46:38:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `61:70:68:10:00:00:22:1C:02:FE` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `24:74:D8:20:00:00:44:B8:00:F8` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `10:3C:14:04:00:80:F1:30:07:40` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `10:3C:34:08:00:80:22` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `10:7C:D8:20:00:00:8C:03:1C:10` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `21:78:68:10:00:00:22` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `48:CC:75:67:81:00:80:0C:05` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `60:9A:75:59:00:00:64:E6:02:FE` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `41:9C:EB:9D:05:02:80:3A:73:82` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `41:3A:D7:9D:05:02:80:64:92:00:00:C0:01:02:10:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `` | `` | `20:72:DD:2C:10:00:D4:99:13:FC` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=004C` | `55:A3:7E:72:07:03:00:50:E3:F0:4C:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:71 op=F8 addr=80EC` | `55:A3:7E:72:07:03:00:50:71:F8:EC:80` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0048` | `55:A3:7E:72:07:03:00:50:E3:F0:48:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=01E9` | `55:A3:7E:72:07:03:00:50:E3:F0:E9:01:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0060` | `55:A3:7E:72:07:03:00:50:E3:F0:60:00` |
| `UHF` | `rapid charge` | `2026-05-24-v3-uhf-rapid-charge-003.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0000` | `55:A3:7E:72:07:03:00:50:E3:F0:00:00:FF:FF:FF:FF:FF` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `8` | `` | `` | `10:38:1B:06:00:00:03:07:00:FE:FF:FF:FF:FF` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `11` | `` | `` | `10:38:1B:02:00:50:06:8E:01` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `12` | `` | `` | `10:38:1B:06:00:20:0E:0C:06:FC` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `30` | `` | `` | `10:38:1B:06:00:A0:CC:40:01:01:8C:04:04:00` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `` | `` | `` | `10:38:1B:02:00:80` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `` | `` | `` | `28:70:36:0C:00:00:0E:0C:00:FC:FF:FF:FF:FF` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `` | `` | `` | `10:E5:6C:08:00:00:06:06:00:F8:FF:FF:FF:FF` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `` | `` | `` | `10:78:36:04:00:A0:0C:4C:01` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `` | `` | `` | `10:65:36:0C:00:00:66:48:03:06:30:12:10:00:08` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:07` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3 op=BE addr=FF07` | `55:A6:D5:89:C5:40:00:50:B3:BE:07:FF` |
| `VHF` | `` | `2026-05-24-v3-vhf-compact-001.md` | `` | `` | `` | `10:38:1B:02:00:50` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `22` | `` | `` | `10:38:1B:02:00:80:03:07:C0` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `28` | `` | `` | `10:38:1B:02:00:80:81:CF:80:FF` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `8` | `` | `` | `10:38:1B:06:00:00:03:83:00:FE:FF:FF:FF:FF` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `17` | `` | `` | `10:38:3B:0C:00:00:06:96:01` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `40` | `` | `` | `10:38:1B:06:00:00:07:06:03:FE` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `` | `` | `` | `10:38:1B:02:00:80` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `` | `` | `` | `10:65:36:0C:00:00:06:06:00:F8:FF:FF:FF:FF` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `` | `` | `` | `10:E5:6C:18:00:80:38:30:18:F0` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `` | `` | `` | `30:70:36:0C:00:00:06:8E:01` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `` | `` | `` | `24:70:36:0C:00:20:66:A0:01:03:18:09:00:00` |
| `VHF` | `fully charged` | `2026-05-24-v3-vhf-compact-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0041` | `55:A3:FC:BC:87:03:00:50:3E:F0:41:00:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=004C` | `55:A3:7E:72:07:03:00:50:E3:F0:4C:00` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=01D9` | `55:A3:7E:72:07:03:00:50:E3:F0:D9:01` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0048` | `55:A3:7E:72:07:03:00:50:E3:F0:48:00` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=01E9` | `55:A3:7E:72:07:03:00:50:E3:F0:E9:01:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0060` | `55:A3:7E:72:07:03:00:50:E3:F0:60:00` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:B3:DE:59:20:00:A8:33` | `55:A6:B3:DE:59:20:00:A8:33:DC` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:73:BD:53:20:00:A8:93` | `55:A6:73:BD:53:20:00:A8:93:EF:C1` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-001.md` | `` | `DS2433_EEPROM` | `` | `A3:7E:72:07:03:00:50:E3` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0041` | `55:A3:7E:72:07:03:00:50:E3:F0:41:00:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:73:BD:B3:40:00:50:67` | `55:A6:73:BD:B3:40:00:50:67:B8:07` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=004C` | `55:A3:7E:72:07:03:00:50:E3:F0:4C:00` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0000` | `55:A3:7E:72:07:03:00:50:E3:F0:00:00:FF:FF:FF:FF:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `family=DS2438_BATTERY_MONITOR candidate=A6:73:BD:B3:40:A2:08:75` | `F0:A6:73:BD:B3:40:A2:08:75` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:73:BD:B3:40:00:50:67` | `55:A6:73:BD:B3:40:00:50:67:BE:83` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=01D9` | `55:A3:7E:72:07:03:00:50:E3:F0:D9:01` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0048` | `55:A3:7E:72:07:03:00:50:E3:F0:48:00` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=01E9` | `55:A3:7E:72:07:03:00:50:E3:F0:E9:01:FF` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:7E:72:07:03:00:50:E3 op=F0 addr=0060` | `55:A3:7E:72:07:03:00:50:E3:F0:60:00` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `DS2433_EEPROM` | `` | `A3:7E:72:07:03:00:50:E3` |
| `UHF` | `rapid charge` | `2026-05-24-v4-uhf-rapid-charge-002.md` | `` | `DS2438_BATTERY_MONITOR` | `` | `A6:73:BD:B3:40:00:50:67` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0041` | `55:A3:FC:BC:87:03:00:50:3E:F0:41:00:FF:FF:FF:FF` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:07` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=004C` | `55:A3:FC:BC:87:03:00:50:3E:F0:4C:00` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0060` | `55:A3:FC:BC:87:03:00:50:3E:F0:60:00` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0000` | `55:A3:FC:BC:87:03:00:50:3E:F0:00:00:FF:FF:FF:FF:FF` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `` | `` | `10:38:1B` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `family=DS2438_BATTERY_MONITOR candidate=A6:D5:99:2E:8E:48:04:A8` | `F0:A6:D5:99:2E:8E:48:04:A8:B3` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `family=DS2433_EEPROM candidate=A3:FA:7F:DE:C3:0F:00:40` | `F0:A3:FA:7F:DE:C3:0F:00:40:F9` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3 op=BE addr=FF07` | `55:A6:D5:89:C5:40:00:50:B3:BE:07:FF` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0048` | `55:A3:FC:BC:87:03:00:50:3E:F0:48:00` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01E9` | `55:A3:FC:BC:87:03:00:50:3E:F0:E9:01:FF` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0148` | `55:A3:FC:BC:87:03:00:50:3E:F0:48:01:FF` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `DS2433_EEPROM` | `` | `A3:FC:BC:87:03:00:50:3E` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-001.md` | `` | `DS2438_BATTERY_MONITOR` | `` | `A6:D5:89:C5:40:00:50:B3` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0041` | `55:A3:FC:BC:87:03:00:50:3E:F0:41:00:FF:FF:FF:FF` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3` | `55:A6:D5:89:C5:40:00:50:B3:B8:07` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=004C` | `55:A3:FC:BC:87:03:00:50:3E:F0:4C:00` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=01D9` | `55:A3:FC:BC:87:03:00:50:3E:F0:D9:01` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0000` | `55:A3:FC:BC:87:03:00:50:3E:F0:00:00:FF:FF:FF:FF:FF` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `SEARCH_ROM_OR_READ_MEMORY` | `family=DS2433_EEPROM candidate=A3:FA:7F:DE:C3:0F:00:40` | `F0:A3:FA:7F:DE:C3:0F:00:40:F9` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:D5:89:C5:40:00:50:B3 op=BE addr=FF07` | `55:A6:D5:89:C5:40:00:50:B3:BE:07:FF` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0048` | `55:A3:FC:BC:87:03:00:50:3E:F0:48:00` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0060` | `55:A3:FC:BC:87:03:00:50:3E:F0:60:00` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:FC:BC:87:03:00:50:3E op=F0 addr=0148` | `55:A3:FC:BC:87:03:00:50:3E:F0:48:01:FF` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `DS2433_EEPROM` | `` | `A3:FC:BC:87:03:00:50:3E` |
| `VHF` | `maintenance mode / discharging` | `2026-05-24-v4-vhf-maintenance-discharging-002.md` | `` | `DS2438_BATTERY_MONITOR` | `` | `A6:D5:89:C5:40:00:50:B3` |
| `XTS2500` | `discharge` | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=0041` | `55:A3:B4:25:1A:01:00:50:9D:F0:41:00:FF:FF:FF:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B8:07` |
| `XTS2500` | `discharge` | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=004C` | `55:A3:B4:25:1A:01:00:50:9D:F0:4C:00` |
| `XTS2500` | `discharge` | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01E9` | `55:A3:B4:25:1A:01:00:50:9D:F0:E9:01:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=0000` | `55:A3:B4:25:1A:01:00:50:9D:F0:00:00:FF:FF:FF:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `` | `DS2433_EEPROM` | `` | `A3:B4:25:1A:01:00:50:9D` |
| `XTS2500` | `discharge` | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `` | `DS2438_BATTERY_MONITOR` | `` | `A6:FB:88:1A:01:00:50:DA` |
| `XTS2500` | `discharge` | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA op=BE addr=FF07` | `55:A6:FB:88:1A:01:00:50:DA:BE:07:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=0048` | `55:A3:B4:25:1A:01:00:50:9D:F0:48:00` |
| `XTS2500` | `discharge` | `2026-05-24-v4-xts2500-nntn6263a-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=0060` | `55:A3:B4:25:1A:01:00:50:9D:F0:60:00` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01E6` | `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01CB` | `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B8:01` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA op=BE addr=FF01` | `55:A6:FB:88:1A:01:00:50:DA:BE:01:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01CB` | `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA op=BE addr=FF01` | `55:A6:FB:88:1A:01:00:50:DA:BE:01:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B4` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B8:00` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA op=BE addr=FF00` | `55:A6:FB:88:1A:01:00:50:DA:BE:00:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `DS2433_EEPROM` | `` | `A3:B4:25:1A:01:00:50:9D` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `` | `` | `FF:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-001.md` | `` | `DS2438_BATTERY_MONITOR` | `` | `A6:FB:88:1A:01:00:50:DA` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01E6` | `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01CB` | `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-002.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01CB` | `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B8:01` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA op=BE addr=FF01` | `55:A6:FB:88:1A:01:00:50:DA:BE:01:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B4` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B8:00` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-rearm-002.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA op=BE addr=FF00` | `55:A6:FB:88:1A:01:00:50:DA:BE:00:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=0041` | `55:A3:B4:25:1A:01:00:50:9D:F0:41:00:FF:FF:FF:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=004C` | `55:A3:B4:25:1A:01:00:50:9D:F0:4C:00` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=0048` | `55:A3:B4:25:1A:01:00:50:9D:F0:48:00` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01E9` | `55:A3:B4:25:1A:01:00:50:9D:F0:E9:01:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=0148` | `55:A3:B4:25:1A:01:00:50:9D:F0:48:01:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=0000` | `55:A3:B4:25:1A:01:00:50:9D:F0:00:00:FF:FF:FF:FF:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B8:07` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA op=BE addr=FF07` | `55:A6:FB:88:1A:01:00:50:DA:BE:07:FF` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `DS2433_EEPROM` | `` | `A3:B4:25:1A:01:00:50:9D` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `DS2438_BATTERY_MONITOR` | `` | `A6:FB:88:1A:01:00:50:DA` |
| `XTS2500` | `discharge` | `2026-05-24-v5-xts2500-discharge-reinsert-001.md` | `` | `` | `` | `FF:FF:FF:FF:FF` |
| `XTS2500` | `discharge to rapid charge transition` | `2026-05-24-v5-xts2500-discharge-to-rapid-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01E6` | `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01` |
| `XTS2500` | `discharge to rapid charge transition` | `2026-05-24-v5-xts2500-discharge-to-rapid-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=80E5` | `55:A3:B4:25:1A:01:00:50:9D:F0:E5:80:FF:FF` |
| `XTS2500` | `discharge to rapid charge transition` | `2026-05-24-v5-xts2500-discharge-to-rapid-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B8:01` |
| `XTS2500` | `discharge to rapid charge transition` | `2026-05-24-v5-xts2500-discharge-to-rapid-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA op=BE addr=FF01` | `55:A6:FB:88:1A:01:00:50:DA:BE:01:FF:FF` |
| `XTS2500` | `discharge to rapid charge transition` | `2026-05-24-v5-xts2500-discharge-to-rapid-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:5A` | `55:A6:FB:88:1A:01:00:50:5A:DC` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01E6` | `55:A3:B4:25:1A:01:00:50:9D:F0:E6:01` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01CB` | `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01CB` | `55:A3:B4:25:1A:01:00:50:9D:F0:CB:01:FF:FF:FF` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B8:01` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA op=BE addr=FF01` | `55:A6:FB:88:1A:01:00:50:DA:BE:01:FF:FF` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B8:00` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA op=BE addr=FF00` | `55:A6:FB:88:1A:01:00:50:DA:BE:00:FF` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2433_EEPROM` | `rom=A3:B4:25:1A:01:00:50:9D op=F0 addr=01B4` | `55:A3:B4:25:1A:01:00:50:9D:F0:B4:01:FF:FF:FF` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:01:00:50:DA` | `55:A6:FB:88:1A:01:00:50:DA:B4` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:7B:84:46:00:00:94:D6 op=37 addr=FFE0` | `55:A6:7B:84:46:00:00:94:D6:37:E0:FF` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:FB:88:1A:00:00:28:6D op=5F addr=FF80` | `55:A6:FB:88:1A:00:00:28:6D:5F:80:FF` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `MATCH_ROM->DS2438_BATTERY_MONITOR` | `rom=A6:7B:44:8D:00:00:28:6D` | `55:A6:7B:44:8D:00:00:28:6D:5C` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `DS2438_BATTERY_MONITOR` | `` | `A6:FB:88:1A:01:00:50:DA` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `DS2433_EEPROM` | `` | `A3:B4:25:1A:01:00:50:9D` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `DS2438_BATTERY_MONITOR` | `` | `A6:7B:84:46:00:00:94:D6` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `DS2438_BATTERY_MONITOR` | `` | `A6:FB:88:1A:00:00:28:6D` |
| `XTS2500` | `charge complete` | `2026-05-25-v5-xts2500-charge-complete-001.md` | `` | `DS2438_BATTERY_MONITOR` | `` | `A6:7B:44:8D:00:00:28:6D` |
