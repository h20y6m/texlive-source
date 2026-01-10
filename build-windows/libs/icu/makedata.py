#!/usr/bin/env python3
import argparse
import os
import shutil
import subprocess


def main():
    parser = argparse.ArgumentParser(description="makedata")
    parser.add_argument("--workdir", default=".", help="working directory")
    parser.add_argument("--outdir", default=".", help="output directory")
    parser.add_argument("--icupkg", default="./icupkg", help="icupkg command")
    parser.add_argument("--pkgdata", default="./pkgdata", help="pkgdata command")
    parser.add_argument("--arch", default="X64", help="arch")
    parser.add_argument("--mode", default="dll", help="mode")
    parser.add_argument("--version", help="version")
    parser.add_argument("input", help="input file")
    args = parser.parse_args()

    workdir = os.path.abspath(args.workdir)
    outdir = os.path.abspath(args.outdir)
    icupkg_exe = os.path.abspath(args.icupkg)
    pkgdata_exe = os.path.abspath(args.pkgdata)
    input = os.path.abspath(args.input)

    libname = "icudt.lib"
    dllname = f"icudt{args.version}.dll"

    os.chdir(workdir)

    lib = os.path.join(outdir, libname)
    if os.path.isfile(lib):
        os.unlink(lib)

    dll = os.path.join(outdir, dllname)
    if os.path.isfile(dll):
        os.unlink(dll)

    # U_ICUDATA_NAME=icudt74

    # ICUPKG=$(U_ICUDATA_NAME)$(U_ICUDATA_ENDIAN_SUFFIX)
    # ICUBLD=$(ICUOUT)\build
    # ICUBLD_PKG=$(ICUBLD)\$(ICUPKG)
    # ICUTMP=$(ICUOUT)\tmp

    icudata_name = f"icudt{args.version}"
    icupkg_name = f"{icudata_name}l"
    builddir = os.path.join(workdir, "build")
    pkgdir = os.path.join(builddir, icupkg_name)
    tmpdir = os.path.join(workdir, "tmp")

    if not os.path.isdir(builddir):
        os.mkdir(builddir)
    if not os.path.isdir(pkgdir):
        os.mkdir(pkgdir)
    if not os.path.isdir(tmpdir):
        os.mkdir(tmpdir)

    # cd "$(ICUBLD_PKG)"
    os.chdir(pkgdir)

    # "$(ICUPBIN)\icupkg" -x * --list "$(ICUDATA_SOURCE_ARCHIVE)" > "$(ICUTMP)\icudata.lst"
    icudata_lst = os.path.join(tmpdir, "icudata.lst")

    with open(icudata_lst, "w") as lst:
        subprocess.run([icupkg_exe, "-x", "*", "--list", input], stdout=lst, check=True)

    # ICU_PACKAGE_MODE=-m dll
    # COMMON_ICUDATA_ARGUMENTS=-f -e $(U_ICUDTA_NAME) -v $(ICU_PACKAGE_MODE) -c -p $(ICUPKG) -T "$(ICUTMP)" -L $(U_ICUDATA_NAME) -d "$(ICUBLD_PKG)" -s .
    # COMMON_ICUDATA_ARGUMENTS=$(COMMON_ICUDATA_ARGUMENTS) -a X64
    # "$(ICUPBIN)\pkgdata" $(COMMON_ICUDATA_ARGUMENTS) "$(ICUTMP)\icudata.lst"
    with open("pkgdata.log", "w") as log:
        subprocess.run(
            [
                pkgdata_exe,
                "-f",
                "-e",
                icudata_name,
                "-v",
                "-m",
                args.mode,
                "-c",
                "-p",
                icupkg_name,
                "-T",
                tmpdir,
                "-L",
                icudata_name,
                "-d",
                pkgdir,
                "-s",
                ".",
                "-a",
                args.arch,
                icudata_lst,
            ],
            stdout=log,
            stderr=log,
            check=True,
        )

    shutil.copyfile(libname, lib)
    if args.mode == "dll":
        shutil.copyfile(dllname, dll)


if __name__ == "__main__":
    main()
