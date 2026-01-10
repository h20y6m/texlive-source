#!/usr/bin/env python3
import argparse
import os
import re


def get_sources(dir, subdir):
    file = os.path.join(dir, '../../../libs/icu/icu-src/source', subdir, 'sources.txt')
    lines = []
    with open(file, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.strip()
            lines.append(f"  icu_src / '{subdir}/{line}',\n")
    return lines


def update_meson_build(file):
    dir = os.path.dirname(file)
    lines = []
    in_sources = False
    with open(file, 'r', encoding='utf-8') as f:
        for line in f:
            if in_sources:
                if line.startswith(']'):
                    lines.append(line)
                    in_sources = False
            elif line.startswith('icu_common_sources'):
                lines.append(line)
                lines.extend(get_sources(dir, 'common'))
                in_sources = True
            elif line.startswith('icu_i18n_sources'):
                lines.append(line)
                lines.extend(get_sources(dir, 'i18n'))
                in_sources = True
            elif line.startswith('icu_toolutil_sources'):
                lines.append(line)
                lines.extend(get_sources(dir, 'tools/toolutil'))
                in_sources = True
            else:
                lines.append(line)
    with open(file, 'w', encoding='utf-8') as f:
        f.write(''.join(lines))


def main():
    parser = argparse.ArgumentParser(description='Update meson.build')
    parser.add_argument('file', help='path to meson.build')
    args = parser.parse_args()
    update_meson_build(args.file)


if __name__ == '__main__':
    main()
