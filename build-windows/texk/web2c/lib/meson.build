#
# meson.build for the TeX Live subdirectory texk/web2c/lib/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

proglib_dir = '../../../../texk/web2c/lib'

proglib_includes = include_directories([
  '..',
  proglib_dir / '..',
  proglib_dir / '../../ptexenc',
])

proglib_defines = [
  '-DWIN32=1',
]

proglib_sources = files([
  proglib_dir / 'basechsuffix.c',
  proglib_dir / 'chartostring.c',
  proglib_dir / 'coredump.c',
  proglib_dir / 'eofeoln.c',
  proglib_dir / 'fprintreal.c',
  proglib_dir / 'inputint.c',
  proglib_dir / 'input2int.c',
  proglib_dir / 'lib.h',
  proglib_dir / 'main.c',
  proglib_dir / 'openclose.c',
  proglib_dir / 'printversion.c',
  proglib_dir / 'setupvar.c',
  proglib_dir / 'uexit.c',
  proglib_dir / 'usage.c',
  proglib_dir / 'version.c',
  proglib_dir / 'zround.c',
])

proglib_lib = static_library('proglib',
  proglib_sources,
  include_directories : proglib_includes,
  c_args: proglib_defines,
  dependencies : [
    kpathsea_dep,
  ]
)

pproglib_sources = files([
  proglib_dir / 'openclose.c',
  proglib_dir / 'printversion.c',
])

pproglib_defines = [
  '-DPTEX',
  proglib_defines
]

pproglib_lib = static_library('pproglib',
  pproglib_sources,
  include_directories : proglib_includes,
  c_args: pproglib_defines,
  dependencies : [
    kpathsea_dep,
  ]
)
