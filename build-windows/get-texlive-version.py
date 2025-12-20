#!/usr/bin/env python3
import argparse
import re


def find_version(file):
    with open(file, "r", encoding="utf-8") as f:
        r = re.compile(r"m4_define\(\[tex_live_version\], \[(.+)\]\)")
        for line in f:
            m = r.match(line)
            if m:
                return m.group(1)
    raise Exception("Not found tex_live_version.")


def main():
    parser = argparse.ArgumentParser(description="Get TeX Live version from version.ac")
    parser.add_argument("file", help="path to version.ac")
    args = parser.parse_args()
    tlver = find_version(args.file)
    print(tlver)


if __name__ == "__main__":
    main()
