# OpenIMPRES

OpenIMPRES is an early reverse-engineering workspace for Motorola IMPRES
charger, battery, and display traffic.

The current focus is passive sniffing only. Do not drive the data line from the
microcontroller while the charger, display, or battery are connected.

## Current Bench Setup

- Charger/display GND to ESP GND
- Charger/display DATA to ESP GPIO4 through a 10k resistor
- Charger/display +5V not connected to the ESP
- ESP powered from USB

## Firmware

Sketches live in `firmware/`:

- `firmware/OpenIMPRES_V1_Passive_Family_Classifier/OpenIMPRES_V1_Passive_Family_Classifier.ino`
- `firmware/OpenIMPRES_V2_OneWire_Timing_Profiler/OpenIMPRES_V2_OneWire_Timing_Profiler.ino`
- `firmware/OpenIMPRES_V3_Reset_Transaction_Profiler/OpenIMPRES_V3_Reset_Transaction_Profiler.ino`

V1 waits for a serial character, arms for bus activity, captures a burst, decodes
rough pulse-width frames, classifies message families, and prints JSON.

V2 focuses on 1-Wire timing evidence: reset-like pulses, presence-like pulses,
timing histograms, decoded frames, and a bounded raw pulse sample.

V3 segments captures around reset-like pulses so each possible 1-Wire
transaction can be inspected independently. It also labels obvious 1-Wire
command/family hints, including likely Match ROM traffic for DS2433 (`A3`) and
DS2438 (`A6`) chips seen in gen-2 IMPRES battery work.

Known early frame families:

- `55:*` display/update or 1-Wire Match ROM traffic
- `10:*` battery identity/status candidates
- `20/21/22/24/28/40/42/44/45/48/49/51/52/60/70/91/F0:*` charger or battery
  status candidates

Known bench batteries:

| Model | Serial | Fingerprint |
| --- | --- | --- |
| NNTN6263A | 5000011A25B4 | `10:50:40:00:00:00` |
| PMNN4807A | 50000387BCFC | `10:38:1B:02:00:80` |

## Capture Notes

For each capture, record:

- Battery model and serial if known
- Whether the display was connected
- Charger LED state
- Exact display text
- Raw JSON output from the sketch

Capture notes live in `captures/`.

The next useful milestone is building a repeatable lookup table:

```text
frame pattern -> observed charger/display meaning
```

See `docs/current-context.md` for the latest handoff notes.

Known bench batteries are tracked in `docs/batteries.md`.

Capture analysis can be regenerated with:

```powershell
python tools\analyze_captures.py
```

The generated report is `analysis/capture-analysis.md`.
