#!/usr/bin/env python3
"""Small PE import/export inspector with no third-party dependencies."""

from __future__ import annotations

import argparse
import pathlib
import struct


IMAGE_DIRECTORY_ENTRY_EXPORT = 0
IMAGE_DIRECTORY_ENTRY_IMPORT = 1


class PE:
    def __init__(self, path: pathlib.Path):
        self.path = path
        self.data = path.read_bytes()
        self.sections = []
        self.is_64 = False
        self.optional_header_offset = 0
        self.data_directories_offset = 0
        self.number_of_rva_and_sizes = 0
        self._parse_headers()

    def u16(self, offset: int) -> int:
        return struct.unpack_from("<H", self.data, offset)[0]

    def u32(self, offset: int) -> int:
        return struct.unpack_from("<I", self.data, offset)[0]

    def u64(self, offset: int) -> int:
        return struct.unpack_from("<Q", self.data, offset)[0]

    def cstr(self, offset: int) -> str:
        end = self.data.index(b"\0", offset)
        return self.data[offset:end].decode("ascii", errors="replace")

    def _parse_headers(self) -> None:
        if self.data[:2] != b"MZ":
            raise ValueError("not an MZ executable")

        pe_offset = self.u32(0x3C)
        if self.data[pe_offset:pe_offset + 4] != b"PE\0\0":
            raise ValueError("not a PE executable")

        coff = pe_offset + 4
        section_count = self.u16(coff + 2)
        optional_size = self.u16(coff + 16)
        self.optional_header_offset = coff + 20
        magic = self.u16(self.optional_header_offset)
        self.is_64 = magic == 0x20B

        if self.is_64:
            self.number_of_rva_and_sizes = self.u32(self.optional_header_offset + 108)
            self.data_directories_offset = self.optional_header_offset + 112
        else:
            self.number_of_rva_and_sizes = self.u32(self.optional_header_offset + 92)
            self.data_directories_offset = self.optional_header_offset + 96

        section_offset = self.optional_header_offset + optional_size
        for i in range(section_count):
            base = section_offset + i * 40
            name = self.data[base:base + 8].split(b"\0", 1)[0].decode("ascii", errors="replace")
            virtual_size = self.u32(base + 8)
            virtual_address = self.u32(base + 12)
            raw_size = self.u32(base + 16)
            raw_pointer = self.u32(base + 20)
            self.sections.append(
                {
                    "name": name,
                    "virtual_size": virtual_size,
                    "virtual_address": virtual_address,
                    "raw_size": raw_size,
                    "raw_pointer": raw_pointer,
                }
            )

    def directory(self, index: int) -> tuple[int, int]:
        if index >= self.number_of_rva_and_sizes:
            return 0, 0
        offset = self.data_directories_offset + index * 8
        return self.u32(offset), self.u32(offset + 4)

    def rva_to_offset(self, rva: int) -> int:
        for section in self.sections:
            start = section["virtual_address"]
            size = max(section["virtual_size"], section["raw_size"])
            end = start + size
            if start <= rva < end:
                return section["raw_pointer"] + (rva - start)
        return rva

    def imports(self) -> list[tuple[str, list[str]]]:
        rva, _size = self.directory(IMAGE_DIRECTORY_ENTRY_IMPORT)
        if not rva:
            return []

        offset = self.rva_to_offset(rva)
        out = []

        while True:
            original_first_thunk = self.u32(offset)
            name_rva = self.u32(offset + 12)
            first_thunk = self.u32(offset + 16)
            if original_first_thunk == 0 and name_rva == 0 and first_thunk == 0:
                break

            dll_name = self.cstr(self.rva_to_offset(name_rva))
            thunk_rva = original_first_thunk or first_thunk
            thunk_offset = self.rva_to_offset(thunk_rva)
            thunk_size = 8 if self.is_64 else 4
            imports = []

            index = 0
            while True:
                value = self.u64(thunk_offset + index * thunk_size) if self.is_64 else self.u32(thunk_offset + index * thunk_size)
                if value == 0:
                    break
                ordinal_flag = 0x8000000000000000 if self.is_64 else 0x80000000
                if value & ordinal_flag:
                    imports.append(f"ordinal:{value & 0xFFFF}")
                else:
                    hint_name_offset = self.rva_to_offset(value)
                    hint = self.u16(hint_name_offset)
                    name = self.cstr(hint_name_offset + 2)
                    imports.append(f"{name} (hint {hint})")
                index += 1

            out.append((dll_name, imports))
            offset += 20

        return out

    def exports(self) -> list[str]:
        rva, _size = self.directory(IMAGE_DIRECTORY_ENTRY_EXPORT)
        if not rva:
            return []

        offset = self.rva_to_offset(rva)
        ordinal_base = self.u32(offset + 16)
        address_count = self.u32(offset + 20)
        name_count = self.u32(offset + 24)
        names_rva = self.u32(offset + 32)
        ordinals_rva = self.u32(offset + 36)

        names_offset = self.rva_to_offset(names_rva)
        ordinals_offset = self.rva_to_offset(ordinals_rva)
        exports = []

        for i in range(name_count):
            name_rva = self.u32(names_offset + i * 4)
            ordinal_index = self.u16(ordinals_offset + i * 2)
            name = self.cstr(self.rva_to_offset(name_rva))
            exports.append(f"{name} @ {ordinal_base + ordinal_index}")

        if not exports and address_count:
            exports.extend(f"ordinal:{ordinal_base + i}" for i in range(address_count))

        return exports


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("paths", nargs="+", type=pathlib.Path)
    parser.add_argument("--exports", action="store_true")
    parser.add_argument("--imports", action="store_true")
    args = parser.parse_args()

    show_imports = args.imports or not args.exports
    show_exports = args.exports

    for path in args.paths:
        pe = PE(path)
        print(f"== {path} ==")
        print(f"arch: {'x64' if pe.is_64 else 'x86'}")
        if show_imports:
            print("imports:")
            for dll, imports in pe.imports():
                print(f"  {dll}")
                for item in imports:
                    print(f"    {item}")
        if show_exports:
            print("exports:")
            for item in pe.exports():
                print(f"  {item}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
