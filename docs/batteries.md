# Bench Batteries

## VHF

- Bench label: `VHF`
- Model number: `PMNN4807A`
- Serial number: `50000387BCFC`
- Chemistry: `Li-Ion`
- Notes:
  - Earlier notes used `PMMN4807A`; treat that as a typo/alias unless the pack
    label proves otherwise.
  - Confirmed reset-delimited fingerprint prefix:
    `10:38:1B:02:00:80`
  - Reconfirmed in compact V3 A/B/A capture on 2026-05-24.

## UHF

- Bench label: `UHF`
- Model number: `PMNN4807A`
- Serial number: `50000307727E`
- Chemistry: `Li-Ion`
- Notes:
  - Same model class as `VHF`; useful for finding serial-specific fields.
  - First compact V3 insertion capture showed distinct `10:*` families:
    `10:3C:6C:*`, `10:9C:14:*`, `10:75:*`, and `10:1C:*`.
  - First capture was taken while the charger/display reported conditioning mode.
  - Rapid-charge V3 capture on 2026-05-24 showed DS2433 search evidence
    `F0:A3:FD:C9:1D:19:00:80:1A` plus `10:3C:*`, `21:74:*`, `22:38:*`,
    `24:74:*`, and `30:F4:*` traffic.
  - Second rapid-charge V3 capture on 2026-05-24 captured direct Match ROM
    traffic for DS2433 (`55:A3:7E:72:07:03:00:50:*`) and DS2438
    (`55:A6:73:BD:B3:40:00:50:*`).
  - Third rapid-charge V3 capture on 2026-05-24 repeated DS2438 selection and
    DS2433 reads at likely little-endian addresses `0x004C`, `0x0048`,
    `0x0060`, `0x01E9`, and `0x0000`.
