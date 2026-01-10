#
# meson.build for the TeX Live subdirectory texk/dvi2tty/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

dvi2tty_srcdir = '../../../texk/dvi2tty'
dvi2tty_tree = dvi2tty_srcdir / 'dvi2tty-src'

dvi2tty_version = run_command(
    find_program('get-dvi2tty-version.py'), dvi2tty_srcdir / 'version.ac',
    check: true).stdout().strip()


dvi2tty_gen_headers = []

dvi2tty_gen_headers += configure_file(
  input : 'c-auto.h.in',
  output : 'c-auto.h',
  configuration : {
    'VERSION' : dvi2tty_version,
  }
)


dvi2tty_includes = include_directories(
  dvi2tty_srcdir,
)

dvi2tty_defines = [
  '-DWIN32',
  '-DKPATHSEA',
  '-DPTEXENC',
]


disdvi_sources = [
  dvi2tty_tree / 'commands.h',
  dvi2tty_tree / 'disdvi.c',
]

dvi2tty_sources = [
  dvi2tty_tree / 'commands.h',
  dvi2tty_tree / 'dvi2tty.c',
  dvi2tty_tree / 'dvi2tty.h',
  dvi2tty_tree / 'tex2ucs.h',
  dvi2tty_tree / 'dvistuff.c',
]


disdvi_exe = executable('disdvi',
  disdvi_sources,
  dvi2tty_gen_headers,
  c_args : dvi2tty_defines,
  include_directories : dvi2tty_includes,
  dependencies : [
    kpathsea_dep,
    ptexenc_dep,
  ],
  install : true,
)

dvi2tty_exe = executable('dvi2tty',
  dvi2tty_sources,
  dvi2tty_gen_headers,
  c_args : dvi2tty_defines,
  include_directories : dvi2tty_includes,
  dependencies : [
    kpathsea_dep,
    ptexenc_dep,
  ],
  install : true,
)
