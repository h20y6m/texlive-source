#
# meson.build for the TeX Live subdirectory texk/dviout-util/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

dviout_util_srcdir = '../../../texk/dviout-util'

dviout_util_version = run_command(
    find_program('get-dviout-util-version.py'), dviout_util_srcdir / 'configure.ac',
    check: true).stdout().strip()


dviout_util_gen_headers = []

dviout_util_gen_headers += configure_file(
  input : 'config.h.in',
  output : 'config.h',
  configuration : {
    'VERSION' : dviout_util_version,
    'TL_VERSION' : tex_live_version,
  }
)


dviout_util_includes = include_directories(
  dviout_util_srcdir,
)

dviout_util_defines = [
  '-DWIN32',
  '-DKPATHSEA',
  '-DPTEXENC',
]


dvispc_sources = [
  dviout_util_srcdir / 'dvispc.c',
  dviout_util_srcdir / 'common.h',
]

chkdvifont_sources = [
  dviout_util_srcdir / 'chkdvifont.c',
  dviout_util_srcdir / 'dd.h',
  dviout_util_srcdir / 'msvcdir.h',
  dviout_util_srcdir / 'common.h',
]


dvispc_exe = executable('dvispc',
  dvispc_sources,
  dviout_util_gen_headers,
  c_args : dviout_util_defines,
  include_directories : dviout_util_includes,
  dependencies : [
    kpathsea_dep,
    ptexenc_dep,
  ],
  install : true,
)

chkdvifont_exe = executable('chkdvifont',
  chkdvifont_sources,
  dviout_util_gen_headers,
  c_args : dviout_util_defines,
  include_directories : dviout_util_includes,
  dependencies : [
    kpathsea_dep,
    ptexenc_dep,
  ],
  install : true,
)
