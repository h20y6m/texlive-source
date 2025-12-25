#!/usr/bin/env python3
import argparse
import os
import re
import subprocess


def cvtbib(lines: list[str]) -> list[str]:
    out = []
    i = 0

    while i < len(lines):
        line = lines[i]

        # 1) #include "cpascal.h" の後に追加
        if re.search(r'#include "cpascal.h"', line):
            out.append(line)
            out.append("#include <setjmp.h>")
            out.append("jmp_buf jmp9998, jmp32; int lab31=0;")
            i += 1
            continue

        # 2) #include "u*ptexdir/kanji.h" の後に追加
        if re.search(r'#include "u*ptexdir/kanji.h"', line):
            out.append(line)
            out.append("#include <setjmp.h>")
            out.append("jmp_buf jmp9998, jmp32; int lab31=0;")
            i += 1
            continue

        # ---- 置換群（sed の順番に） ----

        # s/goto lab31 ; */{lab31=1; return;}/
        line = re.sub(r"goto lab31 ; *", r"{lab31=1; return;}\1", line, count=1)

        # s/goto lab32/longjmp(jmp32,1)/
        line = re.sub(r"goto lab32", r"longjmp(jmp32,1)", line, count=1)

        # s/goto lab9998/longjmp(jmp9998,1)/g
        line = re.sub(r"goto lab9998", r"longjmp(jmp9998,1)", line)

        # s/lab31://
        line = re.sub(r"\blab31:", "", line, count=1)

        # s/lab32://
        line = re.sub(r"\blab32:", "", line, count=1)

        # s/hack0 () ;/if(setjmp(jmp9998)==1) goto lab9998;/
        line = re.sub(
            r"hack0 \(\) ;", r"if(setjmp(jmp9998)==1) goto lab9998;", line, count=1
        )

        # s/hack1 () ;/if(setjmp(jmp32)==0)for(;;)/
        line = re.sub(r"hack1 \(\) ;", r"if(setjmp(jmp32)==0)for(;;)", line, count=1)

        # s/hack2 ()/break/
        line = re.sub(r"hack2 \(\)", r"break", line, count=1)

        out.append(line)
        i += 1

    # ---- /^void mainbody/,$s/while ( true/while (lab31==0/ ----
    # 範囲の開始位置検出
    try:
        start = next(idx for idx, s in enumerate(out) if re.match(r"void mainbody", s))
        in_range = True
    except StopIteration:
        in_range = False

    if in_range:
        for j in range(start, len(out)):
            out[j] = re.sub(r"while \( true", r"while (lab31==0", out[j], count=1)

    return out


def cvtmf1(lines: list[str]) -> list[str]:
    i = 0
    while i < len(lines):
        if lines[i].endswith("."):
            lines[i] = lines[i][:-1]
            lines[i + 1] = "." + lines[i + 1]

        lines[i] = re.sub(r"\.hh", r".hhfield", lines[i])
        lines[i] = re.sub(r"\.lh", r".lhfield", lines[i])

    return lines


def cvtmf2(lines: list[str]) -> list[str]:
    out = []
    for line in lines:
        # 1) else write → else\nwrite
        line = re.sub(r"else write", "else\nwrite", line, count=1)

        # 2)  maxcoef(...) →  lmaxcoef(...)
        line = re.sub(r" maxcoef( *[^( ])", r" lmaxcoef\1", line)

        # 3) b1, b2, b3 置換（g）
        line = re.sub(r" b1", " lb1", line)
        line = re.sub(r" b2", " lb2", line)
        line = re.sub(r" b3", " lb3", line)

        out += line.split("\n")
    return out


def cat(files: list[str]) -> list[str]:
    lines = []
    for file in files:
        with open(file, "r", encoding="utf-8", errors="surrogateescape") as file:
            for line in file:
                lines.append(line)
    return lines


def pipe_run(args: list[str], lines: list[str]) -> list[str]:
    return (
        subprocess.run(
            args,
            input="\n".join(lines) + "\n",
            text=True,
            capture_output=True,
            check=True,
        )
        .stdout.rstrip("\n")
        .split("\n")
    )


def make_pipe_cmd(args: list[str]):
    def cmd(lines: list[str]) -> list[str]:
        return pipe_run(args, lines)

    return cmd


def convert(basefile: str, srcdir, splitup, web2c, fixwrites):
    pascalfile = f"{basefile}.p"
    cfile = f"{basefile}.c"

    hfile = "cpascal.h"
    more_defines = []
    web2c_options = [f"-c{basefile}"]
    precmd = None
    midcmd = None
    fixwrites_options = []
    splitup_options = ["-i", "-l", "65000"]
    postcmd = None
    output = cfile

    if basefile in ["pbibtex", "pdvitype", "ppltotf", "ptftopl"]:
        more_defines = [f"{srcdir}/ptexdir/ptex.defines"]
        hfile = "ptexdir/kanji.h"
    elif basefile in ["upbibtex", "updvitype", "uppltotf", "uptftopl"]:
        more_defines = [f"{srcdir}/uptexdir/uptex.defines"]
        hfile = "uptexdir/kanji.h"

    if basefile in ["bibtex", "pbibtex", "upbibtex"]:
        midcmd = cvtbib
    elif basefile in [
        "mf",
        "mflua",
        "mfluajit",
        "tex",
        "aleph",
        "etex",
        "pdftex",
        "ptex",
        "eptex",
        "euptex",
        "uptex",
        "xetex",
        "nptex",
    ]:
        if basefile.startswith("mf"):
            more_defines = [
                f"{srcdir}/web2c/texmf.defines",
                f"{srcdir}/web2c/mfmp.defines",
            ]
            precmd = cvtmf1
            web2c_options = ["-m", f"-c{basefile}coerce"]
            midcmd = cvtmf2
        else:
            more_defines = [
                f"{srcdir}/web2c/texmf.defines",
                f"{srcdir}/synctexdir/synctex.defines",
            ]
            web2c_options = ["-t", f"-c{basefile}coerce"]
            fixwrites_options = ["-t"]
        prog_defines = f"{srcdir}/{basefile}dir/{basefile}.defines"
        if os.path.exists(prog_defines):
            more_defines += [prog_defines]
        hfile = "texmfmp.h"
        postcmd = make_pipe_cmd([splitup, *splitup_options, basefile])
        cfile = f"{basefile}0.c"
        output = None

    lines = cat([f"{srcdir}/web2c/common.defines", *more_defines, pascalfile])
    if precmd is not None:
        lines = precmd(lines)
    lines = pipe_run([web2c, f"-h{hfile}", *web2c_options], lines)
    if midcmd is not None:
        lines = midcmd(lines)
    lines = pipe_run([fixwrites, *fixwrites_options, basefile], lines)
    if postcmd is not None:
        lines = postcmd(lines)
    if output is not None:
        with open(output, "w", encoding="utf-8", errors="surrogateescape") as f:
            for line in lines:
                f.write(line + "\n")

    if basefile in ["bibtex", "pbibtex", "upbibtex"]:
        lines = []
        with open(
            f"{basefile}.h", "r", encoding="utf-8", errors="surrogateescape"
        ) as f:
            for line in f:
                lines.append(line)
        lines = [line for line in lines]
        with open(
            f"{basefile}.h", "w", encoding="utf-8", errors="surrogateescape"
        ) as f:
            for line in lines:
                f.write(line + "\n")
    elif basefile in [
        "mf",
        "mflua",
        "mfluajit",
        "tex",
        "aleph",
        "etex",
        "pdftex",
        "ptex",
        "eptex",
        "euptex",
        "uptex",
        "xetex",
        "nptex",
    ]:
        lines = []
        with open(
            f"{srcdir}/web2c/coerce.h", "r", encoding="utf-8", errors="surrogateescape"
        ) as f:
            for line in f:
                lines.append(line)
        with open(
            f"{basefile}coerce.h", "a", encoding="utf-8", errors="surrogateescape"
        ) as f:
            for line in lines:
                f.write(line + "\n")
        with open(f"{basefile}d.h", "a"):
            pass


def main():
    parser = argparse.ArgumentParser(description="Convert WEB programs")
    parser.add_argument("basefile", help="base file")
    parser.add_argument("--workdir", default=".", help="working directory")
    parser.add_argument("--srcdir", default=".", help="source directory")
    parser.add_argument("--splitup", default="./web2c/splitup", help="splitup command")
    parser.add_argument("--web2c", default="./web2c/web2c", help="web2c command")
    parser.add_argument(
        "--fixwrites", default="./web2c/fixwrites", help="fixwrites command"
    )
    args = parser.parse_args()

    workdir = os.path.abspath(args.workdir)
    srcdir = os.path.abspath(args.srcdir)
    splitup = os.path.abspath(args.splitup)
    web2c = os.path.abspath(args.web2c)
    fixwrites = os.path.abspath(args.fixwrites)

    os.chdir(workdir)
    convert(args.basefile, srcdir, splitup, web2c, fixwrites)


if __name__ == "__main__":
    main()
