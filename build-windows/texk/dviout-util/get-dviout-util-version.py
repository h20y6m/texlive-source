#!/usr/bin/env python3
import argparse
import re


def find_version(file):
    with open(file, "r", encoding="utf-8") as f:
        r = re.compile(r"AC_INIT\(\[dviout-util \(TeX Live\)\], \[(.+)\], \[.+\]\)")
        for line in f:
            m = r.match(line)
            if m:
                return m.group(1)
    raise Exception("Not found dviout-util version.")


def main():
    parser = argparse.ArgumentParser(
        description="Get dviout-util version from configure.ac"
    )
    parser.add_argument("file", help="path to configure.ac")
    args = parser.parse_args()
    ver = find_version(args.file)
    print(ver)


if __name__ == "__main__":
    main()
