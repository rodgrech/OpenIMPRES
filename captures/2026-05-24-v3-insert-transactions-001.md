# Capture 2026-05-24 V3 Insert Transactions 001

Source: Serial capture from `COM11` at `115200`.

## Setup

- Firmware: `OpenIMPRES_V3_Reset_Transaction_Profiler`
- Battery was inserted after arming.
- Display was connected.

## Key Result

V3 successfully segmented the capture into reset-delimited transactions and
confirmed the known PMMN battery fingerprint appears cleanly in individual
transactions.

Known `VHF` battery:

```text
Model: PMNN4807A
Serial: 50000387BCFC
Chemistry: Li-Ion
```

Known `VHF` fingerprint:

```text
10:38:1B:02:00:80
```

Confirmed transactions:

```text
index 9  bytes: 10:38:1B:02:00:80:81:01:00:FE:FF:FF:FF:FF
index 36 bytes: 10:38:1B:02:00:80:81:FF
```

This confirms the passive decoder can recover the known fingerprint when traffic
is segmented around reset-like pulses.

## Capture Summary

```json
{
  "pulse_count": 5000,
  "capture_saturated": true,
  "capture_ms": 2500,
  "reset_like_count": 47,
  "presence_like_count": 48,
  "transaction_count": 47
}
```

## Other Interesting Transactions

```text
index 8  bytes: 30:70:36:0C:00:40:0C:1C:00:F8:FF:FF:FF:FF
index 11 bytes: 21:CA:D9:30:00:00:18:38:06:FC
index 12 bytes: 10:E5:6C:18:00:00:0C:0C:02:FE
index 19 bytes: 30:70:36:0C:00:00:0E:1C:00:FF
index 22 bytes: 10:38:1B:06:00:00:03:47:01
index 29 bytes: 10:38:1B:06:00:00:03:D3:80
index 31 bytes: 10:E5:DC:10:00:00:0C:FC
index 35 bytes: 10:78:76:08:00:40:9C:81:06:0C:60:04:00:00:04
index 39 bytes: 10:78:36:04:00:00:07:06:03:FE
```

Display transactions also appeared later:

```text
index 41 bytes: 55:A6:D5:89:C5:40:00:50:B3:B8:07
index 42 bytes: 55:A6:D5:89:C5:40:00:50:B3:BE:07:FF
```

## Notes

- Serial output was very long. Future firmware should print a compact summary
  and only include interesting transactions by default.
- The capture still saturated, so the complete insertion sequence is longer than
  the current 5000-pulse buffer.
