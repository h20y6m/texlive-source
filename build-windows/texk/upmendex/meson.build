#
# meson.build for the TeX Live subdirectory texk/upmendex/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

upmendex_srcdir = '../../../texk/upmendex'

upmendex_version = run_command(
    find_program('get-upmendex-version.py'), upmendex_srcdir / 'configure.ac',
    check: true).stdout().strip()


upmendex_gen_headers = []

upmendex_gen_headers += configure_file(
  input : 'c-auto.h.in',
  output : 'c-auto.h',
  configuration : {
    'VERSION' : upmendex_version,
    'TL_VERSION' : tex_live_version,
  }
)


upmendex_includes = include_directories(
  upmendex_srcdir,
)

upmendex_defines = [
  '-DWIN32=1',
  '-DKPATHSEA=1',
]


upmendex_sources = [
  upmendex_srcdir / 'convert.c',
  upmendex_srcdir / 'exkana.h',
  upmendex_srcdir / 'exvar.h',
  upmendex_srcdir / 'fread.c',
  upmendex_srcdir / 'fwrite.c',
  upmendex_srcdir / 'kana.h',
  upmendex_srcdir / 'kp.c',
  upmendex_srcdir / 'kp.h',
  upmendex_srcdir / 'main.c',
  upmendex_srcdir / 'mendex.h',
  upmendex_srcdir / 'version.h',
  upmendex_srcdir / 'pageread.c',
  upmendex_srcdir / 'qsort.c',
  upmendex_srcdir / 'qsort.h',
  upmendex_srcdir / 'sort.c',
  upmendex_srcdir / 'styfile.c',
  upmendex_srcdir / 'var.h',
]


upmendex_exe = executable('mendex',
  upmendex_sources,
  upmendex_gen_headers,
  c_args : upmendex_defines,
  include_directories : upmendex_includes,
  dependencies : [
    kpathsea_dep,
    icu_dep,
  ],
  install : true,
)

