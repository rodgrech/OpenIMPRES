# Current Context

This captures the current reverse-engineering context for the OpenIMPRES
workspace.

## Hardware Under Test

- Motorola IMPRES charger/battery/display ecosystem
- Passive tap on the charger/display data line
- Display/amped speaker connected during later captures
- ESP listens on GPIO4 through a 10k resistor

## Important Working Assumption

Treat the observed traffic as one shared data line with multiple message types.

The display being connected changes what appears on the line and possibly how the
charger behaves. Do not model this as two separate buses unless later captures
prove it.

Observed family split:

- `55:*` display/update traffic
- `10:*` battery identity or battery status candidate traffic
- `20/21/22/24/28:*` battery or charger status candidate traffic
- short/tiny pulse captures are likely noise or partial frames

## Known Captures And Batteries

- Battery `XTS2500`: `NNTN6263A`, serial `5000011A25B4`, NiMH
  - Earlier notes called this `Battery A`.
  - V4 discharge capture on 2026-05-24 identified DS2433 ROM
    `A3:B4:25:1A:01:00:50:9D` and DS2438 ROM
    `A6:FB:88:1A:01:00:50:DA`.
- Battery `VHF`: `PMNN4807A`, serial `50000387BCFC`, Li-Ion
  - Current fingerprint: `10:38:1B:02:00:80`
  - Confirmed in reset-delimited V3 transactions on 2026-05-24
  - Earlier notes used `PMMN4807A`; treat this as a typo/alias unless a label
    proves otherwise.
- Battery `UHF`: `PMNN4807A`, serial `50000307727E`, Li-Ion
  - V4 rapid-charge captures identified DS2433 ROM
    `A3:7E:72:07:03:00:50:E3` and DS2438 ROM
    `A6:73:BD:B3:40:00:50:67`.
- Unknown/display-connected fingerprint seen:
  - `10:78:36:0C:00:00`
  - `10:72:36:0C:00:00`

Example display-connected snippet from the prior session:

```text
Frame 2: B0 D8 23 08 00 00 A0  [partial 2 bits]
Frame 3: 70 40 01 01 00 00 3A
Frame 5: 10 50 00 00 00 80 C0 00 C0 FF FF FF  [partial 5 bits]
Frame 6: 10 50 40 00 00 00 81 01 80 FF FF FF FF
Frame 7: 10 50 40 00 00 00 81 01 00 FE FF FF  [partial 5 bits]
Frame 9: 10 50 40 00 00 00 81 31
```

## Current Firmware Goal

The V1 drop-in sketch is a passive family classifier. It should:

- wait for a serial character to arm
- wait for activity
- capture one burst
- decode rough pulse-width frames
- classify frames into display, battery identity/status, charger status, noise,
  or unknown
- remember the last known battery so display-only/status-only traffic can still
  be associated with the current pack
- print JSON suitable for later analysis

V2 proved the insertion burst has strong 1-Wire-like timing. V3 segments
captures around reset-like pulses so each possible 1-Wire transaction can be
inspected independently.

The current recommended sketch is V4:

```text
firmware/OpenIMPRES_V4_OneWire_Detail_Decoder/OpenIMPRES_V4_OneWire_Detail_Decoder.ino
```

V4 keeps the same passive flow and adds structured fields for DS2433/DS2438 ROM
selection, likely read-memory opcodes, and little-endian memory addresses.

## Next Captures To Take

Keep the display connected and capture repeatable sets with exact bench notes.

For each run, record:

- battery model and serial
- charger LED state
- exact display text
- whether the display/amped speaker was connected
- raw JSON emitted by the sketch

The next research step is a lookup table:

```text
frame prefix/pattern -> observed display or charger meaning
```

Motorola's installed IMPRES Battery Reader software includes Dallas/Maxim
DS2490 and TMEX/iButton components. See `docs/motorola-battery-reader-notes.md`.
