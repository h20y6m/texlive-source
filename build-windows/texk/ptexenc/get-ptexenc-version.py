#!/usr/bin/env python3
import argparse
import re


def find_version(file):
    with open(file, "r", encoding="utf-8") as f:
        r = re.compile(r"m4_define\(\[ptexenc_version\], \[(.+)\]\)")
        for line in f:
            m = r.match(line)
            if m:
                return m.group(1)
    raise Exception("Not found ptexenc_version.")


def main():
    parser = argparse.ArgumentParser(description="Get ptexenc version from version.ac")
    parser.add_argument("file", help="path to version.ac")
    args = parser.parse_args()
    ver = find_version(args.file)
    print(ver)


if __name__ == "__main__":
    main()
