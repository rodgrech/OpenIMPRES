# Bench Batteries

## XTS2500

- Bench label: `XTS2500`
- Model number: `NNTN6263A`
- Serial number: `5000011A25B4`
- Chemistry: `NiMH`
- Notes:
  - Earlier notes called this `Battery A`.
  - V4 discharge capture on 2026-05-24 identified DS2433 ROM
    `A3:B4:25:1A:01:00:50:9D` and DS2438 ROM
    `A6:FB:88:1A:01:00:50:DA`.
  - The same capture showed DS2433 reads at `0x0000`, `0x0041`, `0x0048`,
    `0x004C`, `0x0060`, and `0x01E9`.
  - V5 discharge reinsert capture repeated the same DS2433/DS2438 ROMs and
    added a clean `0x0148` DS2433 read.
  - V5 rearm-without-removal captures showed shorter follow-up polling at
    DS2433 addresses `0x01E6` and `0x01CB`, plus DS2438 `B8`/`BE` operations
    with page-like trailing bytes `0x01` and `0x00`.
  - During the discharge-to-rapid-charge transition, V5 still showed DS2433
    `0x01E6` polling plus stable DS2438 `B8`/`BE` operations on the same
    `A6:FB:88:1A:01:00:50:DA` ROM.
  - The NiMH pack uses the same broad DS2433/DS2438 structure as the PMNN4807A
    Li-Ion packs, making it a useful chemistry comparison sample.

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
  - V4 maintenance/discharging capture on 2026-05-24 identified DS2433 ROM
    `A3:FC:BC:87:03:00:50:3E` and DS2438 ROM
    `A6:D5:89:C5:40:00:50:B3`, with DS2433 reads at `0x0000`, `0x0041`,
    `0x0048`, `0x004C`, `0x0060`, `0x0148`, and `0x01E9`.
  - Second V4 maintenance/discharging capture repeated the same DS2433/DS2438
    ROMs and added a clean `0x01D9` DS2433 read.

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
  - First V4 rapid-charge capture on 2026-05-24 confirmed structured DS2433
    read annotations at `0x004C`, `0x0048`, `0x0060`, `0x01D9`, and `0x01E9`.
  - Second V4 rapid-charge capture on 2026-05-24 did not saturate and repeated
    DS2433 reads at `0x0000`, `0x0041`, `0x0048`, `0x004C`, `0x0060`,
    `0x01D9`, and `0x01E9`.
