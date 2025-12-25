#!/usr/bin/env python3
import argparse
import os
import subprocess


def main():
    parser = argparse.ArgumentParser(description="Call tangle")
    parser.add_argument("--workdir", default=".", help="working directory")
    parser.add_argument("--tangle", default="./tangle", help="tangle command")
    parser.add_argument("args", nargs="*", help="tangle arguments")
    args = parser.parse_args()

    workdir = os.path.abspath(args.workdir)
    tangle = os.path.abspath(args.tangle)

    os.chdir(workdir)
    subprocess.run([tangle, *args.args], check=True)


if __name__ == "__main__":
    main()
