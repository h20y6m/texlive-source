#
# meson.build for the TeX Live subdirectory texk/web2c/web2c/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

web2c_web2c_dir = '../../../../texk/web2c/web2c'


web2c_web2c_includes = include_directories(
  '..',
  web2c_web2c_dir / '..',
)

web2c_web2c_defines = [
  '-DWIN32',
]


## web2c

web2c_sources = files([
  web2c_web2c_dir / 'web2c-parser.h',
  web2c_web2c_dir / 'web2c-parser.c',
  web2c_web2c_dir / 'web2c-lexer.c',
  web2c_web2c_dir / 'main.c',
  web2c_web2c_dir / 'web2c.h',
])

web2c_exe = executable('web2c',
  web2c_sources,
  w2c_headers,
  include_directories : web2c_web2c_includes,
  c_args: web2c_web2c_defines,
  dependencies : [
    kpathsea_dep,
  ]
)


## fixwrites

fixwrites_exe = executable('fixwrites',
  web2c_web2c_dir / 'fixwrites.c',
  w2c_headers,
  include_directories : web2c_web2c_includes,
  c_args: web2c_web2c_defines,
  dependencies : [
    kpathsea_dep,
  ]
)


## splitup

splitup_exe = executable('splitup',
  web2c_web2c_dir / 'splitup.c',
  w2c_headers,
  include_directories : web2c_web2c_includes,
  c_args: web2c_web2c_defines,
  dependencies : [
    kpathsea_dep,
  ]
)


## makecpool

makecpool_exe = executable('makecpool',
  web2c_web2c_dir / 'makecpool.c',
  w2c_headers,
  include_directories : web2c_web2c_includes,
  dependencies : [
    kpathsea_dep,
  ]
)
