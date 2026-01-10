#!/usr/bin/env python3
import argparse
import os
import subprocess
import sys


def main():
    parser = argparse.ArgumentParser(description="Call makecpool")
    parser.add_argument("--workdir", default=".", help="working directory")
    parser.add_argument("--makecpool", default="./makecpool", help="makecpool command")
    parser.add_argument("-o", "--output", type=argparse.FileType("w"), default=sys.stdout, help="output file (default STDOUT)")
    parser.add_argument("args", nargs="*", help="tangle arguments")
    args = parser.parse_args()

    workdir = os.path.abspath(args.workdir)
    makecpool = os.path.abspath(args.makecpool)

    os.chdir(workdir)
    subprocess.run([makecpool, *args.args], stdout=args.output, check=True)


if __name__ == "__main__":
    main()
