#
# meson.build for the TeX Live subdirectory texk/bibtex-x/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

bibtexx_srcdir = '../../../texk/bibtex-x'

bibtexx_version = run_command(
    find_program('get-bibtex-x-version.py'), bibtexx_srcdir / 'configure.ac',
    check: true).stdout().strip()


bibtexx_gen_headers = []

bibtexx_gen_headers += configure_file(
  input : 'config.h.in',
  output : 'config.h',
  configuration : {
    'TL_VERSION' : tex_live_version,
    'VERSION' : bibtexx_version,
  }
)


bibtexx_includes = include_directories(
  bibtexx_srcdir,
)

bibtexx_common_defines = [
  '-DWIN32=1',
  '-DKPATHSEA=1',
  '-DHAVE_CONFIG_H=1',
]


bibtexx_common_sources = [
  bibtexx_srcdir / 'bibtex-1.c',
  bibtexx_srcdir / 'bibtex-2.c',
  bibtexx_srcdir / 'bibtex-3.c',
  bibtexx_srcdir / 'bibtex-4.c',
  bibtexx_srcdir / 'bibtex.c',
  bibtexx_srcdir / 'bibtex.h',
  bibtexx_srcdir / 'datatype.h',
  bibtexx_srcdir / 'gblprocs.h',
  bibtexx_srcdir / 'gblvars.h',
  bibtexx_srcdir / 'utils.c',
  bibtexx_srcdir / 'utils.h',
  bibtexx_srcdir / 'version.h',
  bibtexx_srcdir / 'sysdep.h',
]


bibtexx_dll = executable('bibtex8',
  bibtexx_common_sources,
  bibtexx_gen_headers,
  c_args : bibtexx_common_defines + ['-DSUPPORT_8BIT'],
  include_directories : bibtexx_includes,
  dependencies : [
    kpathsea_dep,
  ],
  install : true,
)

bibtexx_dll = executable('bibtexu',
  bibtexx_common_sources,
  bibtexx_gen_headers,
  c_args : bibtexx_common_defines + ['-DUTF_8'],
  include_directories : bibtexx_includes,
  dependencies : [
    kpathsea_dep,
    icu_dep,
  ],
  install : true,
)
