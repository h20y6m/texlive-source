#
# meson.build for the TeX Live subdirectory texk/mendexk/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

mendex_srcdir = '../../../texk/mendexk'

mendex_version = run_command(
    find_program('get-mendex-version.py'), mendex_srcdir / 'configure.ac',
    check: true).stdout().strip()


mendex_gen_headers = []

mendex_gen_headers += configure_file(
  input : 'c-auto.h.in',
  output : 'c-auto.h',
  configuration : {
    'VERSION' : mendex_version,
    'TL_VERSION' : tex_live_version,
  }
)


mendex_includes = include_directories(
  mendex_srcdir,
)

mendex_defines = [
  '-DWIN32=1',
  '-DKPATHSEA=1',
]


mendex_sources = [
  mendex_srcdir / 'convert.c',
  mendex_srcdir / 'exkana.h',
  mendex_srcdir / 'exvar.h',
  mendex_srcdir / 'fread.c',
  mendex_srcdir / 'fwrite.c',
  mendex_srcdir / 'kana.h',
  mendex_srcdir / 'kp.c',
  mendex_srcdir / 'kp.h',
  mendex_srcdir / 'ktable.h',
  mendex_srcdir / 'main.c',
  mendex_srcdir / 'mendex.h',
  mendex_srcdir / 'version.h',
  mendex_srcdir / 'pageread.c',
  mendex_srcdir / 'qsort.c',
  mendex_srcdir / 'qsort.h',
  mendex_srcdir / 'sort.c',
  mendex_srcdir / 'styfile.c',
  mendex_srcdir / 'var.h',
]


mendex_exe = executable('mendex',
  mendex_sources,
  mendex_gen_headers,
  c_args : mendex_defines,
  include_directories : mendex_includes,
  dependencies : [
    kpathsea_dep,
    ptexenc_dep,
  ],
  install : true,
)

