#
# meson.build for the TeX Live subdirectory libs/expat/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

expat_dir = '.'
expat_src = expat_dir / 'expat-src'

expat_sources = files([
  expat_src / 'lib/xmlparse.c',
  expat_src / 'lib/xmlrole.c',
  expat_src / 'lib/xmltok.c',
])


expat_includes = include_directories(
  expat_src / 'lib',
)


expat_cflags = [
  '-DWIN32=1',
  '-DNDEBUG=1',
  '-D_MBCS',
  '-D_LIB',
  '-DCOMPILED_FROM_DSP=1',
]


expat_lib = static_library('expat',
  expat_sources,
  c_args : expat_cflags,
  include_directories : expat_includes,
  dependencies : [
  ],
)

expat_dep = declare_dependency(
  include_directories: expat_includes,
  link_with: expat_lib,
)

