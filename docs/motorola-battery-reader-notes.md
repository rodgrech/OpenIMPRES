# Motorola IMPRES Battery Reader Notes

Source folder inspected:

```text
C:\Program Files (x86)\Motorola Solutions\IMPRES Battery Reader
```

## Files Of Interest

- `BatteryReader.exe`
- `BatteryReader.hxf`
- `DS2490.inf`
- `DS2490.sys`
- `ib90usb.dll`
- `ib97e32.dll`
- `ib97u32.dll`
- `ibfs32.dll`
- `Drivers\x64\motusbvcom_x64.inf`
- `Drivers\x86\necelusbvcom.inf`

## Open Reference Project Evidence

The public `rick51231/motorola-battery-reader` project describes gen-2 Motorola
IMPRES batteries as exposing two 1-Wire chips:

- `DS2433` EEPROM, family code `0xA3`
- `DS2438` battery monitor, family code `0xA6`

Its firmware searches the 1-Wire bus for both ROM families, reads all eight
DS2438 pages with CRC checks, then reads and verifies the full 512-byte DS2433
EEPROM. Its README also lists a 1-Wire bypass mode for the original Motorola
Battery Reader software as a future goal, which aligns with the TMEX shim route
in this workspace.

## Driver Evidence

`DS2490.inf` identifies a Dallas/Maxim 1-Wire USB host adapter:

```text
USB\VID_04FA&PID_2490
DeviceDesc="USB Host Adapter for 1-Wire Network"
SvcDesc="DS2490 (USB Host for 1-Wire Network)"
```

Motorola virtual COM driver INFs identify these USB devices:

```text
USB\VID_0CAD&PID_1602 = Motorola IMPRES Battery Data Reader
USB\VID_0CAD&PID_1603 = Motorola IMPRES Charger Interface Unit
USB\VID_0CAD&PID_1604 = Motorola IMPRES Gen2 Mackinaw DUC Charger
```

The x64 driver names it:

```text
disk1.desc="Motorola IMPRES Charger Interface Unit driver install disk"
MOTVCOM_FILTER.SvcDesc="Virtual COM Port for MOTOROLA USB"
```

The x86 driver names it:

```text
disk1.desc="Motorola IMPRES device driver install disk"
NECELVCOM_FILTER.SvcDesc="Virtual COM Port for NECEL USB"
```

## Application Evidence

Printable strings in `BatteryReader.exe` include:

```text
TMExtendedStartSession
TMEndSession
TMSetup
TMFirst
TMNext
TMRom
TMTouchReset
TMTouchByte
TMAutoOverDrive
TMAccess
TMBlockStream
CreateFileW
PurgeComm
ReadFile
WriteFile
C:\Software\L677_Reader\Code\LMPS_677_READER_PC_V1.05.14\Release\BatteryReader.pdb
```

This strongly suggests the application uses Dallas/Maxim TMEX/iButton APIs for
1-Wire battery access, with ordinary Windows serial/file APIs also present.

## TMEX DLL Evidence

Printable strings in `ibfs32.dll`, `ib90usb.dll`, `ib97e32.dll`, and
`ib97u32.dll` include common TMEX/iButton calls:

```text
TMSetup
TMExtendedStartSession
TMEndSession
TMTouchReset
TMTouchBit
TMTouchByte
TMBlockIO
TMBlockStream
TMReadPacket
TMWritePacket
TMExtendedReadPage
TMProgramBlock
TMProgramPulse
TMFirst
TMNext
TMSearch
TMRom
TMFamilySearchSetup
TMSkipFamily
TMReadDefaultPort
TMGetAdapterSpec
TMGetFamilySpec
```

`ib90usb.dll` also contains:

```text
\\.\DS2490-%d
DS9490R/B, DS2490-USB
DS1608,,Battery Pack Clock
```

## Working Interpretation

The official reader path appears to be based on Dallas/Maxim 1-Wire, likely via
TMEX and a DS2490/DS9490-style USB host adapter. The Motorola reader/charger
hardware then presents either:

- a direct DS2490-style 1-Wire interface, or
- a Motorola virtual COM device that bridges commands to the IMPRES battery bus.

This supports treating the charger/battery traffic as 1-Wire-like rather than a
completely custom pulse protocol.

## Implications For OpenIMPRES

Next firmware work should focus on better 1-Wire framing:

- log reset/presence pulses separately
- classify short and long slots more conservatively
- capture the complete ROM/search/access sequence after battery insertion
- annotate `0x55 0xA3...` and `0x55 0xA6...` transactions as likely Match ROM
  accesses to DS2433 and DS2438 chips
- report raw slot timing histograms alongside decoded bytes
- avoid trusting the first `10:*` frame as identity without checking all
  candidates

Next PC-side work should look for a connected Motorola reader/charger USB device
with one of:

```text
VID_04FA PID_2490
VID_0CAD PID_1602
VID_0CAD PID_1603
VID_0CAD PID_1604
```

Without official hardware, the most practical emulator target is the TMEX DLL
boundary. See `docs/tmex-emulation-plan.md`.
