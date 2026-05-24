#!/usr/bin/env python3
"""Analyze OpenIMPRES capture markdown files.

The capture notes are intentionally human-friendly markdown. This script extracts
the stable bits we care about: battery labels, charger state, transaction byte
strings, first-byte families, and short prefixes for comparison.
"""

from __future__ import annotations

import argparse
import collections
import dataclasses
import pathlib
import re
from typing import Iterable


HEX_STREAM_RE = re.compile(r"\b(?:[0-9A-Fa-f]{2}:){2,}[0-9A-Fa-f]{2}\b")
INDEX_BYTES_RE = re.compile(
    r"\bindex\s+(?P<index>\d+)\s+bytes:\s+(?P<bytes>(?:[0-9A-Fa-f]{2}:){2,}[0-9A-Fa-f]{2})",
    re.IGNORECASE,
)
JSON_BYTES_RE = re.compile(
    r'"bytes"\s*:\s*"(?P<bytes>(?:[0-9A-Fa-f]{2}:){2,}[0-9A-Fa-f]{2})"',
    re.IGNORECASE,
)
META_RE = re.compile(r"^-\s*(?P<key>[^:]+):\s*`?(?P<value>[^`\r\n]+)`?\s*$")

ONE_WIRE_COMMANDS = {
    "33": "READ_ROM",
    "55": "MATCH_ROM",
    "F0": "SEARCH_ROM_OR_READ_MEMORY",
    "CC": "SKIP_ROM",
}

ONE_WIRE_FAMILIES = {
    "A3": "DS2433_EEPROM",
    "A6": "DS2438_BATTERY_MONITOR",
}


@dataclasses.dataclass(frozen=True)
class Transaction:
    source: str
    battery: str
    state: str
    bytes_text: str
    index: str = ""

    @property
    def parts(self) -> tuple[str, ...]:
        return tuple(part.upper() for part in self.bytes_text.split(":"))

    @property
    def first(self) -> str:
        return self.parts[0] if self.parts else ""

    def prefix(self, length: int) -> str:
        return ":".join(self.parts[:length])

    @property
    def one_wire_hint(self) -> str:
        if not self.parts:
            return ""

        command = ONE_WIRE_COMMANDS.get(self.parts[0], "")
        if self.parts[0] == "55" and len(self.parts) > 1:
            family = ONE_WIRE_FAMILIES.get(self.parts[1], "")
            if family:
                return f"{command}->{family}"

        family = ONE_WIRE_FAMILIES.get(self.parts[0], "")
        if family:
            return family

        return command

    @property
    def one_wire_detail(self) -> str:
        if len(self.parts) < 2:
            return ""

        if self.parts[0] == "55" and self.parts[1] in ONE_WIRE_FAMILIES:
            detail = [f"rom={':'.join(self.parts[1:9])}"]
            if len(self.parts) >= 12:
                detail.append(f"op={self.parts[9]}")
                detail.append(f"addr={self.parts[11]}{self.parts[10]}")
            return " ".join(detail)

        if self.parts[0] == "F0" and self.parts[1] in ONE_WIRE_FAMILIES:
            return f"family={ONE_WIRE_FAMILIES[self.parts[1]]} candidate={':'.join(self.parts[1:9])}"

        return ""


@dataclasses.dataclass
class Capture:
    path: pathlib.Path
    battery: str = "unknown"
    model: str = ""
    serial: str = ""
    chemistry: str = ""
    state: str = ""
    transactions: list[Transaction] = dataclasses.field(default_factory=list)


def parse_capture(path: pathlib.Path) -> Capture:
    text = path.read_text(encoding="utf-8", errors="replace")
    capture = Capture(path=path)

    metadata: dict[str, str] = {}
    for line in text.splitlines():
        match = META_RE.match(line.strip())
        if not match:
            continue
        key = match.group("key").strip().lower()
        value = match.group("value").strip()
        metadata[key] = value

    capture.battery = metadata.get("bench label", "unknown")
    capture.model = metadata.get("model", metadata.get("model number", ""))
    capture.serial = metadata.get("serial", metadata.get("serial number", ""))
    capture.chemistry = metadata.get("chemistry", "")
    capture.state = metadata.get("charger/display state", "")

    seen: set[tuple[str, str]] = set()

    for match in INDEX_BYTES_RE.finditer(text):
        index = match.group("index")
        bytes_text = normalize_hex(match.group("bytes"))
        key = (index, bytes_text)
        if key in seen:
            continue
        seen.add(key)
        capture.transactions.append(
            Transaction(path.name, capture.battery, capture.state, bytes_text, index)
        )

    for match in JSON_BYTES_RE.finditer(text):
        bytes_text = normalize_hex(match.group("bytes"))
        key = ("", bytes_text)
        if key in seen:
            continue
        seen.add(key)
        capture.transactions.append(
            Transaction(path.name, capture.battery, capture.state, bytes_text)
        )

    # Fallback for short manually written capture notes.
    if not capture.transactions:
        for match in HEX_STREAM_RE.finditer(text):
            bytes_text = normalize_hex(match.group(0))
            key = ("", bytes_text)
            if key in seen:
                continue
            seen.add(key)
            capture.transactions.append(
                Transaction(path.name, capture.battery, capture.state, bytes_text)
            )

    return capture


def normalize_hex(value: str) -> str:
    return ":".join(part.upper() for part in value.split(":"))


def group_by_battery(captures: Iterable[Capture]) -> dict[str, list[Transaction]]:
    grouped: dict[str, list[Transaction]] = collections.defaultdict(list)
    for capture in captures:
        grouped[capture.battery].extend(capture.transactions)
    return dict(grouped)


def count_prefixes(transactions: Iterable[Transaction], prefix_len: int) -> collections.Counter[str]:
    counter: collections.Counter[str] = collections.Counter()
    for tx in transactions:
        if len(tx.parts) >= prefix_len:
            counter[tx.prefix(prefix_len)] += 1
    return counter


def first_family_counts(transactions: Iterable[Transaction]) -> collections.Counter[str]:
    counter: collections.Counter[str] = collections.Counter()
    for tx in transactions:
        if tx.first:
            counter[tx.first] += 1
    return counter


def one_wire_hint_counts(transactions: Iterable[Transaction]) -> collections.Counter[str]:
    counter: collections.Counter[str] = collections.Counter()
    for tx in transactions:
        if tx.one_wire_hint:
            counter[tx.one_wire_hint] += 1
    return counter


def format_counter(counter: collections.Counter[str], limit: int = 20) -> str:
    if not counter:
        return "_none_"
    return "\n".join(f"- `{key}`: {count}" for key, count in counter.most_common(limit))


def unique_prefixes(
    grouped: dict[str, list[Transaction]], battery: str, prefix_len: int
) -> collections.Counter[str]:
    target = count_prefixes(grouped.get(battery, []), prefix_len)
    others: set[str] = set()
    for name, transactions in grouped.items():
        if name == battery:
            continue
        others.update(count_prefixes(transactions, prefix_len).keys())
    return collections.Counter({key: count for key, count in target.items() if key not in others})


def build_report(captures: list[Capture], prefix_len: int) -> str:
    grouped = group_by_battery(captures)
    lines: list[str] = []
    lines.append("# Capture Analysis")
    lines.append("")
    lines.append("## Captures")
    lines.append("")
    for capture in captures:
        lines.append(
            f"- `{capture.path.name}`: battery `{capture.battery}`, "
            f"state `{capture.state or 'unknown'}`, transactions {len(capture.transactions)}"
        )

    lines.append("")
    lines.append("## First-Byte Families")
    lines.append("")
    for battery, transactions in sorted(grouped.items()):
        lines.append(f"### {battery}")
        lines.append("")
        lines.append(format_counter(first_family_counts(transactions), limit=30))
        lines.append("")

    lines.append("## Common Prefixes")
    lines.append("")
    for battery, transactions in sorted(grouped.items()):
        lines.append(f"### {battery} prefix length {prefix_len}")
        lines.append("")
        lines.append(format_counter(count_prefixes(transactions, prefix_len), limit=30))
        lines.append("")

    lines.append("## One-Wire Hints")
    lines.append("")
    lines.append(
        "Hints are based on common 1-Wire commands plus DS2433 (`A3`) and "
        "DS2438 (`A6`) family codes observed in Motorola IMPRES gen-2 reader work."
    )
    lines.append("")
    for battery, transactions in sorted(grouped.items()):
        lines.append(f"### {battery}")
        lines.append("")
        lines.append(format_counter(one_wire_hint_counts(transactions), limit=30))
        lines.append("")

    lines.append("## Battery-Unique Prefix Candidates")
    lines.append("")
    for battery in sorted(grouped):
        if battery == "unknown":
            continue
        lines.append(f"### {battery} unique prefix length {prefix_len}")
        lines.append("")
        lines.append(format_counter(unique_prefixes(grouped, battery, prefix_len), limit=30))
        lines.append("")

    lines.append("## Transaction Rows")
    lines.append("")
    lines.append("| Battery | State | Source | Index | Hint | Detail | Bytes |")
    lines.append("| --- | --- | --- | --- | --- | --- | --- |")
    for capture in captures:
        for tx in capture.transactions:
            lines.append(
                f"| `{tx.battery}` | `{tx.state or ''}` | `{tx.source}` | "
                f"`{tx.index}` | `{tx.one_wire_hint}` | `{tx.one_wire_detail}` | "
                f"`{tx.bytes_text}` |"
            )

    lines.append("")
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "captures",
        nargs="*",
        type=pathlib.Path,
        default=[pathlib.Path("captures")],
        help="Capture markdown files or directories to scan.",
    )
    parser.add_argument(
        "--prefix-len",
        type=int,
        default=6,
        help="Number of leading bytes to use for prefix comparisons.",
    )
    parser.add_argument(
        "--output",
        type=pathlib.Path,
        default=pathlib.Path("analysis/capture-analysis.md"),
        help="Markdown report path.",
    )
    args = parser.parse_args()

    paths: list[pathlib.Path] = []
    for input_path in args.captures:
        if input_path.is_dir():
            paths.extend(sorted(input_path.glob("*.md")))
        else:
            paths.append(input_path)

    captures = [parse_capture(path) for path in paths]
    report = build_report(captures, args.prefix_len)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(report, encoding="utf-8")
    print(f"Wrote {args.output} from {len(captures)} captures")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
