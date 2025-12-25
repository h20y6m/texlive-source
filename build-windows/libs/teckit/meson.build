#
# meson.build for the TeX Live subdirectory libs/teckit/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

subdir('include/teckit')

teckit_dir = '../../../libs/teckit'
teckit_src = teckit_dir / 'TECkit-src'


teckit_sources = [
  teckit_src / 'source/Engine.cpp',
]


teckit_includes = include_directories(teckit_src / 'source/Public-headers')


teckit_lib = static_library('teckit',
  teckit_sources,
#  c_args : [],
  include_directories : teckit_includes,
  dependencies : [
    zlib_dep,
  ],
)

teckit_dep = declare_dependency(
  include_directories: include_directories('include'),
  link_with: teckit_lib,
  sources: teckit_headers,
)

