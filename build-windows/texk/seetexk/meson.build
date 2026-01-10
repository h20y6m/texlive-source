#
# meson.build for the TeX Live subdirectory texk/seetexk/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

seetex_srcdir = '../../../texk/seetexk'

seetex_version = run_command(
    find_program('get-seetex-version.py'), seetex_srcdir / 'configure.ac',
    check: true).stdout().strip()


seetex_gen_headers = []

seetex_gen_headers += configure_file(
  input : 'config.h.in',
  output : 'config.h',
  configuration : {
    'VERSION' : seetex_version,
    'TL_VERSION' : tex_live_version,
  }
)


seetex_includes = include_directories(
  seetex_srcdir,
)

seetex_defines = [
  '-DHAVE_CONFIG_H',
  '-DWIN32',
  '-DKPATHSEA',
  '-DASCIIPTEX',
]


seetex_libtex_sources = [
  seetex_srcdir / 'dviclass.c',
  seetex_srcdir / 'dviclass.h',
  seetex_srcdir / 'error.c',
  seetex_srcdir / 'error.h',
  seetex_srcdir / 'fio.c',
  seetex_srcdir / 'fio.h',
  seetex_srcdir / 'font.h',
  seetex_srcdir / 'gripes.h',
  seetex_srcdir / 'gripes0.c',
  seetex_srcdir / 'gripes1.c',
  seetex_srcdir / 'search.c',
  seetex_srcdir / 'search.h',
  seetex_srcdir / 'seek.h',
  seetex_srcdir / 'seek.c',
  seetex_srcdir / 'tempfile.c',
  seetex_srcdir / 'tempfile.h',
  seetex_srcdir / 'types.h',
  seetex_srcdir / 'common.h',
]

dvibook_sources = [
  seetex_srcdir / 'dvibook.c',
]

dviconcat_sources = [
  seetex_srcdir / 'dviconcat.c',
]

dviconcat_sources = [
  seetex_srcdir / 'dviconcat.c',
]

dviselect_sources = [
  seetex_srcdir / 'dviselect.c',
]

dvitodvi_sources = [
  seetex_srcdir / 'dvitodvi.c',
]


seetex_libtex_lib = static_library('seetex_libtex',
  seetex_libtex_sources,
  seetex_gen_headers,
  c_args : seetex_defines,
  include_directories : seetex_includes,
  dependencies : [
    kpathsea_dep,
  ],
)

dvibook_exe = executable('dvibook',
  dvibook_sources,
  seetex_gen_headers,
  c_args : seetex_defines,
  include_directories : seetex_includes,
  link_with: seetex_libtex_lib,
  dependencies : [
    kpathsea_dep,
  ],
  install : true,
)

dviconcat_exe = executable('dviconcat',
  dviconcat_sources,
  seetex_gen_headers,
  c_args : seetex_defines,
  include_directories : seetex_includes,
  link_with: seetex_libtex_lib,
  dependencies : [
    kpathsea_dep,
  ],
  install : true,
)

dviselect_exe = executable('dviselect',
  dviselect_sources,
  seetex_gen_headers,
  c_args : seetex_defines,
  include_directories : seetex_includes,
  link_with: seetex_libtex_lib,
  dependencies : [
    kpathsea_dep,
  ],
  install : true,
)

dvitodvi_exe = executable('dvitodvi',
  dvitodvi_sources,
  seetex_gen_headers,
  c_args : seetex_defines,
  include_directories : seetex_includes,
  link_with: seetex_libtex_lib,
  dependencies : [
    kpathsea_dep,
  ],
  install : true,
)
