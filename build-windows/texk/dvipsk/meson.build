#
# meson.build for the TeX Live subdirectory texk/dvipsk/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

dvips_srcdir = '../../../texk/dvipsk'

dvips_version = run_command(
    find_program('get-dvipsk-version.py'), dvips_srcdir / 'configure.ac',
    check: true).stdout().strip()


dvips_gen_headers = []

dvips_gen_headers += configure_file(
  input : 'c-auto.h.in',
  output : 'c-auto.h',
  configuration : {
    'VERSION' : dvips_version,
    'TL_VERSION' : tex_live_version,
  }
)


dvips_includes = include_directories(
  dvips_srcdir,
)

dvips_defines = [
  '-DWIN32',
  '-DKPATHSEA',
  '-DDSHIFTLOWCHARS',
]


afm2tfm_sources = [
  dvips_srcdir / 'afm2tfm.c',
]

dvips_sources = [
  dvips_srcdir / 'bbox.c',
  dvips_srcdir / 'bitmapenc.c',
  dvips_srcdir / 'color.c',
  dvips_srcdir / 'config.h',
  dvips_srcdir / 'debug.h',
  dvips_srcdir / 'dopage.c',
  dvips_srcdir / 'dosection.c',
  dvips_srcdir / 'dospecial.c',
  dvips_srcdir / 'download.c',
  dvips_srcdir / 'dpicheck.c',
  dvips_srcdir / 'drawPS.c',
  dvips_srcdir / 'dviinput.c',
  dvips_srcdir / 'dvips.c',
  dvips_srcdir / 'dvips.h',
  dvips_srcdir / 'emspecial.c',
  dvips_srcdir / 'finclude.c',
  dvips_srcdir / 'fontdef.c',
  dvips_srcdir / 'header.c',
  dvips_srcdir / 'hps.c',
  dvips_srcdir / 'loadfont.c',
  dvips_srcdir / 'output.c',
  dvips_srcdir / 'papersiz.c',
  dvips_srcdir / 'paths.h',
  dvips_srcdir / 'pprescan.c',
  dvips_srcdir / 'prescan.c',
  dvips_srcdir / 'protos.h',
  dvips_srcdir / 'protos_add.h',
  dvips_srcdir / 'ptexmac.h',
  dvips_srcdir / 'repack.c',
  dvips_srcdir / 'resident.c',
  dvips_srcdir / 'scalewidth.c',
  dvips_srcdir / 'scanpage.c',
  dvips_srcdir / 'search.c',
  dvips_srcdir / 'skippage.c',
  dvips_srcdir / 't1part.c',
  dvips_srcdir / 't1part.h',
  dvips_srcdir / 'tfmload.c',
  dvips_srcdir / 'unpack.c',
  dvips_srcdir / 'virtualfont.c',
  dvips_srcdir / 'writet1.c',
]


afm2tfm_exe = executable('afm2tfm',
  afm2tfm_sources,
  dvips_gen_headers,
  c_args : dvips_defines,
  include_directories : dvips_includes,
  dependencies : [
    kpathsea_dep,
  ],
  install : true,
)

dvips_exe = executable('dvips',
  dvips_sources,
  dvips_gen_headers,
  c_args : dvips_defines,
  include_directories : dvips_includes,
  dependencies : [
    kpathsea_dep,
  ],
  install : true,
)

