# TMEX Emulation Plan

The installed Motorola IMPRES Battery Reader software appears to use
Dallas/Maxim TMEX/iButton APIs (`TMSetup`, `TMRom`, `TMTouchReset`,
`TMTouchByte`, `TMBlockStream`, etc.). Without official Motorola reader hardware,
the most practical emulation target is the Dallas/Maxim side of the stack.

## Goal

Make Motorola's `BatteryReader.exe` believe it is talking to a supported
TMEX/1-Wire adapter, then feed it controlled 1-Wire responses derived from our
charger captures.

## Route A: TMEX DLL Shim

Build replacement DLLs that export the TMEX functions used by
`BatteryReader.exe`.

`BatteryReader.exe` does not statically import `ibfs32.dll`; it imports
`LoadLibraryA/W`, `GetProcAddress`, and `FreeLibrary`. That means TMEX is loaded
dynamically, which makes DLL shimming a good first test.

Likely functions from string/import inspection:

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
```

Pros:

- No USB hardware required.
- Fast iteration.
- Can log exactly what the Motorola app asks for.
- Can return synthetic battery data from capture fixtures.

Cons:

- Need to match TMEX calling conventions and exports closely enough.
- The app may load specific DLL names or expect registry configuration.
- Some functions may be called by ordinal, not just name.

Best first experiment:

1. Copy `BatteryReader.exe` and its DLLs into a sandbox folder.
2. Replace or interpose `ibfs32.dll` with a logging shim.
3. Run the app and log which TMEX functions are called.
4. Stub success responses until the UI progresses far enough to show what data it
   expects.

Current scaffold:

```text
shim/tmex_shim/tmex_shim.c
shim/tmex_shim/ibfs32.def
```

The export list was generated from the real `ibfs32.dll` and preserves ordinals
`1` through `59`.

Current blocker:

```text
cl, gcc, clang, tcc, zig, and msbuild are not available on PATH.
```

Build needs either Visual Studio Build Tools, MinGW-w64, Zig, or another Windows
C compiler capable of producing a 32-bit DLL.

## Route B: DS2490 USB Device Emulation

Emulate a `VID_04FA PID_2490` DS2490/DS9490-style USB 1-Wire adapter.

Pros:

- Exercises the real Dallas/Maxim driver path.
- Closer to the official hardware boundary.

Cons:

- Requires USB device-mode hardware or Linux USB gadget support.
- Windows driver binding and DS2490 USB command behavior must be correct.
- Slower and more fragile than a DLL shim.

This is possible, but not the first recommended path.

## Route C: Motorola Virtual COM Emulation

Emulate one of the Motorola USB VCOM devices:

```text
VID_0CAD PID_1602 = Motorola IMPRES Battery Data Reader
VID_0CAD PID_1603 = Motorola IMPRES Charger Interface Unit
VID_0CAD PID_1604 = Motorola IMPRES Gen2 Mackinaw DUC Charger
```

Pros:

- Targets Motorola's own named reader/charger devices.

Cons:

- We do not yet know the Motorola-side VCOM protocol.
- The Battery Reader app's strings strongly suggest it uses TMEX calls, so the
  VCOM path may be for charger interface hardware rather than the battery reader
  workflow we want.

## Recommendation

Start with Route A, the TMEX DLL shim.

It lets us observe Motorola's high-level 1-Wire expectations without owning the
official hardware. Once we know the calls and response format, we can decide
whether to:

- keep using the shim as a protocol oracle,
- build a PC-side decoder for captured batteries, or
- emulate a USB DS2490 adapter later.

## Open Questions

- Which TMEX DLL does `BatteryReader.exe` load first in practice?
- Are TMEX functions imported by name or loaded dynamically?
- Does the app require registry keys under
  `Software\Dallas Semiconductor\iButton TMEX`?
- Does it search for a ROM family code before reading battery data?
- Which 1-Wire memory device family does an IMPRES battery emulate?
