#!/usr/bin/env python3
import argparse
import os
import subprocess


def main():
    parser = argparse.ArgumentParser(description="Call tie")
    parser.add_argument("--workdir", default=".", help="working directory")
    parser.add_argument("--tie", default="./tangle", help="tie command")
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument("-c", action="store_true", help="tie -c")
    group.add_argument("-m", action="store_true", help="tie -m")
    parser.add_argument("args", nargs="*", help="tangle arguments")
    args = parser.parse_args()

    workdir = os.path.abspath(args.workdir)
    tie = os.path.abspath(args.tie)

    os.chdir(workdir)
    if args.c:
        subprocess.run([tie, "-c", *args.args], check=True)
    if args.m:
        subprocess.run([tie, "-m", *args.args], check=True)


if __name__ == "__main__":
    main()
