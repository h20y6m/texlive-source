#
# meson.build for the TeX Live subdirectory libs/zlib/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

zlib_srcdir = '../../../libs/zlib'
zlib_tree = zlib_srcdir / 'zlib-src'


zlib_zconf_h = configure_file(
  input : zlib_tree / 'zconf.h.in',
  output : 'zconf.h',
  copy : true,
)

zlib_gen_headers = [
  zlib_zconf_h,
]


zlib_includes = include_directories(
  zlib_tree,
)

zlib_defines = [
  '-D_CRT_NONSTDC_NO_DEPRECATE',
  '-D_CRT_SECURE_NO_DEPRECATE',
]


zlib_sources = [
    zlib_tree / 'adler32.c',
    zlib_tree / 'compress.c',
    zlib_tree / 'crc32.c',
    zlib_tree / 'deflate.c',
    zlib_tree / 'gzclose.c',
    zlib_tree / 'gzlib.c',
    zlib_tree / 'gzread.c',
    zlib_tree / 'gzwrite.c',
    zlib_tree / 'inflate.c',
    zlib_tree / 'infback.c',
    zlib_tree / 'inftrees.c',
    zlib_tree / 'inffast.c',
    zlib_tree / 'trees.c',
    zlib_tree / 'uncompr.c',
    zlib_tree / 'zutil.c',
]


zlib_lib = static_library('zlib',
  zlib_sources,
  zlib_gen_headers,
  c_args : zlib_defines,
  include_directories : zlib_includes,
)


subdir('include')

zlib_dep = declare_dependency(
  sources: zlib_include_headers,
  include_directories: include_directories('include'),
  link_with: zlib_lib,
)
