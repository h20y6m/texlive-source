#
# meson.build for the TeX Live subdirectory libs/pplib/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

pplib_srcdir = '../../../libs/pplib'
pplib_tree = pplib_srcdir / 'pplib-src'
pplib_src = pplib_tree / 'src'


pplib_includes = include_directories(
  pplib_tree / 'src',
  pplib_tree / 'src/util',
)

pplib_defines = [
  '-DNO_IMAGE_FILTER=1',
  '-DWIN32=2',
]

pplib_sources = [
  pplib_tree / 'src/pparray.c',
  pplib_tree / 'src/ppcrypt.c',
  pplib_tree / 'src/ppdict.c',
  pplib_tree / 'src/ppheap.c',
  pplib_tree / 'src/ppload.c',
  pplib_tree / 'src/ppstream.c',
#  pplib_tree / 'src/pptest1.c',
#  pplib_tree / 'src/pptest2.c',
#  pplib_tree / 'src/pptest3.c',
  pplib_tree / 'src/ppxref.c',
  pplib_tree / 'src/util/utilbasexx.c',
  pplib_tree / 'src/util/utilcrypt.c',
  pplib_tree / 'src/util/utilflate.c',
  pplib_tree / 'src/util/utilfpred.c',
  pplib_tree / 'src/util/utiliof.c',
  pplib_tree / 'src/util/utillog.c',
  pplib_tree / 'src/util/utillzw.c',
  pplib_tree / 'src/util/utilmd5.c',
  pplib_tree / 'src/util/utilmem.c',
  pplib_tree / 'src/util/utilmemheap.c',
  pplib_tree / 'src/util/utilmemheapiof.c',
  pplib_tree / 'src/util/utilmeminfo.c',
  pplib_tree / 'src/util/utilnumber.c',
  pplib_tree / 'src/util/utilsha.c',
]

pplib_lib = static_library('pplib',
  pplib_sources,
  c_args : pplib_defines,
  include_directories : pplib_includes,
  dependencies: [
    zlib_dep,
  ],
)


subdir('include')

pplib_dep = declare_dependency(
  sources: pplib_include_headers,
  include_directories: include_directories('include'),
  link_with: pplib_lib,
)
