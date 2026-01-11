#
# meson.build for the TeX Live subdirectory texk/makejvf/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

makejvf_srcdir = '../../../texk/makejvf'


makejvf_gen_headers = []


makejvf_includes = include_directories(
  makejvf_srcdir,
)

makejvf_defines = [
  '-DWIN32=1',
  '/source-charset:.20932', # The source code of makejvf contains Japanese characters encoded in EUC-JP.
  '/execution-charset:.932', # Set to shift_jis to run on Japanese Windows.
]


makejvf_sources = [
  makejvf_srcdir / 'main.c',
  makejvf_srcdir / 'makejvf.h',
  makejvf_srcdir / 'tfmread.c',
  makejvf_srcdir / 'tool.c',
  makejvf_srcdir / 'uniblock.c',
  makejvf_srcdir / 'uniblock.h',
  makejvf_srcdir / 'usrtable.c',
  makejvf_srcdir / 'usrtable.h',
  makejvf_srcdir / 'version.h',
  makejvf_srcdir / 'write.c',
]


makejvf_exe = executable('makejvf',
  makejvf_sources,
  makejvf_gen_headers,
  c_args : makejvf_defines,
  include_directories : makejvf_includes,
  dependencies : [
    kpathsea_dep,
    ptexenc_dep,
  ],
  install : true,
)

