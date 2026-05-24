# TMEX Shim

This folder contains a first-pass Windows DLL shim for Motorola's IMPRES Battery
Reader sandbox.

The target is `ibfs32.dll`, because the Motorola app references high-level TMEX
functions and the real `ibfs32.dll` exports the full API surface.

## Current Status

The shim source and `.def` file are generated, but this machine does not
currently expose a C compiler on `PATH`.

Known missing commands:

```text
cl
gcc
clang
```

## Intended Build

With Visual Studio / Build Tools:

```bat
cl /LD /DWIN32 /D_USRDLL tmex_shim.c /link /DEF:ibfs32.def /OUT:ibfs32.dll
```

With MinGW:

```bat
gcc -shared -o ibfs32.dll tmex_shim.c ibfs32.def
```

## Intended Test

1. Copy `vendor_sandbox/IMPRESBatteryReader/ibfs32.dll` to
   `vendor_sandbox/IMPRESBatteryReader/ibfs32.real.dll`.
2. Copy the built shim DLL to
   `vendor_sandbox/IMPRESBatteryReader/ibfs32.dll`.
3. Launch `vendor_sandbox/IMPRESBatteryReader/BatteryReader.exe`.
4. Inspect `vendor_sandbox/IMPRESBatteryReader/tmex_shim.log`.

The first goal is only to learn which TMEX calls the Motorola app makes and in
what order.
