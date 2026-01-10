#
# meson.build for the TeX Live subdirectory libs/libpaper/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

libpaper_srcdir = '../../../libs/libpaper'
libpaper_tree = libpaper_srcdir / 'libpaper-src'

libpaper_version = run_command(
    find_program('get-libpaper-version.py'), libpaper_srcdir / 'version.ac',
    check: true).stdout().strip()


libpaper_gen_headers = []

libpaper_gen_headers += configure_file(
  input : 'config.h.in',
  output : 'config.h',
  configuration : {
    'VERSION' : libpaper_version,
  }
)


libpaper_includes = include_directories(
  libpaper_tree / 'lib',
)

libpaper_defines = [
  '-DWIN32=1',
  '-D_CRT_NONSTDC_NO_DEPRECATE',
  '-D_CRT_SECURE_NO_DEPRECATE',
  '-D_CRT_OBSOLETE_NO_DEPRECATE',
  '-D_SECURE_SCL=0',
  '-DHAVE_CONFIG_H=1',
  '-D_REENTRANT',
]

libpaper_sources = [
  libpaper_tree / 'lib/dimen.c',
  libpaper_tree / 'lib/dimen.h',
  libpaper_tree / 'lib/paper.c',
  libpaper_tree / 'lib/paper.h',
  libpaper_tree / 'lib/paperspecs.h',
]


libpaper_lib = static_library('paper',
  libpaper_sources,
  libpaper_gen_headers,
  c_args : libpaper_defines,
  include_directories : libpaper_includes,
)


subdir('include')

libpaper_dep = declare_dependency(
  sources: libpaper_include_headers,
  include_directories: include_directories('include'),
  link_with: libpaper_lib,
)
