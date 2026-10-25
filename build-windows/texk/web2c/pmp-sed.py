#!/usr/bin/env python3
import argparse
import re
import sys


REPLACEMENTS = [
    # pmp_sed_main
    (r'mpxout\.h', r'pmpxout.h'),
    (r'mpmp\.h', r'pmpmp.h'),
    (r'mplib\.h', r'pmplib.h'),
    (r'mpstrings\.h', r'pmpstrings.h'),
    (r'tfmin\.h', r'ptfmin.h'),
    (r'TFMIN_H', r'PTFMIN_H'),
    # pmp_sed_math
    (r'mpmath([a-z]*)\.h', r'pmpmath\1.h'),
    # pmp_sed_ps
    (r'mplibps\.h', r'pmplibps.h'),
    (r'mppsout\.h', r'pmppsout.h'),
    # pmp_sed_svg
    (r'mplibsvg\.h', r'pmplibsvg.h'),
    (r'mpsvgout\.h', r'pmpsvgout.h'),
    # pmp_sed_png
    (r'mplibpng\.h', r'pmplibpng.h'),
    (r'mppngout\.h', r'pmppngout.h'),
]


COMPILED_RE = [(re.compile(p), r) for p, r in REPLACEMENTS]


def process_line(line):
    """Apply all replacements to a single line."""
    for pattern, repl in COMPILED_RE:
        line = pattern.sub(repl, line)
    return line


def main():
    parser = argparse.ArgumentParser(description="pmp_sed")
    parser.add_argument("input", help="Path to the input file")
    parser.add_argument("output", help="Path to the output file")

    args = parser.parse_args()

    try:
        with open(args.input, 'r', encoding='utf-8', errors='surrogateescape') as f_in:
            with open(args.output, 'w', encoding='utf-8', errors='surrogateescape') as f_out:
                for line in f_in:
                    f_out.write(process_line(line))
    except FileNotFoundError:
        print(f"Error: File '{args.input}' not found.", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
