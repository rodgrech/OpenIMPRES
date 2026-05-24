# Capture 2026-05-24 V2 Insert Timing 001

Source: Serial capture from `COM11` at `115200`.

## Setup

- Firmware: `OpenIMPRES_V2_OneWire_Timing_Profiler`
- Battery was fully removed before arming.
- Battery was inserted after the sketch printed `armed_waiting_for_activity`.
- Display was connected.

## Key Result

This is the strongest capture so far. It shows a battery-insertion burst with
many non-display frames and timing evidence consistent with a 1-Wire-like bus.

## Timing Summary

```json
{
  "pulse_count": 5000,
  "capture_saturated": true,
  "capture_ms": 5000,
  "timing_counts": {
    "slot_1_low_le_15us": 1002,
    "slot_0_low_45_95us": 2056,
    "presence_like_low_90_300us": 47,
    "reset_like_low_gt_300us": 46,
    "ambiguous_low": 1849
  },
  "low_hist_us": {
    "0_15": 1002,
    "16_30": 1403,
    "31_60": 460,
    "61_90": 2042,
    "91_150": 47,
    "151_300": 0,
    "301_600": 46,
    "601_1200": 0,
    "gt_1200": 0
  },
  "high_hist_us": {
    "0_15": 0,
    "16_30": 1028,
    "31_60": 2700,
    "61_90": 846,
    "91_150": 337,
    "151_300": 30,
    "301_600": 41,
    "601_1200": 4,
    "gt_1200": 14
  }
}
```

## Frame Summary

```json
{
  "frame_count": 38,
  "family_counts": {
    "55_display": 0,
    "10_identity_or_status": 9,
    "20_status": 9,
    "70_status": 1
  }
}
```

Interesting decoded frames:

```text
70:8C:3F:77:38:00:00:F8
10:38:0B:03:00:80:03:03:00:FF:FF:FF:FF:FF
10:E5:6C:08:00:00:06:06:00:F8:FF:FF:FF:FF
30:70:36:0C:00:40:19:18:04:FC
20:95:89:30:10:00:54:6A:01:FF
28:70:36:0C:00:00:0E:1C:00:FF
10:38:1B:06:00:00:07:4E:03
10:38:1B:06:00:A0:0C:FA
10:38:1B:02:00:50:06:4E:03
10:78:1A:02:00:80:03:13:01:FF
10:38:1B:06:00:00:03:87:80
28:70:76:18:00:00:1C:38:0A:F8
```

## Interpretation

- The 500-ish low pulses are strong reset-like candidates.
- The 90-150 us low pulses are plausible presence-like candidates.
- The 60-ish low bucket matches classic write-zero-ish 1-Wire timing.
- The 0-15 us low bucket matches classic write-one-ish timing.
- The large 16-30 us bucket is important. It may be read-slot initiation,
  host timing variation, or a threshold problem in the current decoder.
- The known PMMN battery fingerprint family is showing up nearby:
  `10:38:1B:*`.
- The decoded prefix `10:38:1B:02:00:50` is close to the previously known
  `10:38:1B:02:00:80`, suggesting current decoding is close but not perfect.

## Next Firmware Direction

Create a V3 decoder that reports 1-Wire transactions around each reset-like
pulse, rather than treating all pulses as one stream. V3 should keep timing
histograms but also segment captures into reset-delimited transactions.
