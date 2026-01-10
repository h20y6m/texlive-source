#
# meson.build for the TeX Live subdirectory texk/kpathsea/win32/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

win32_srcdir = '../../../../texk/kpathsea/win32'


win32_defines = [
  '-DWIN32',
]


mktexfmt_sources = [
  win32_srcdir / 'mktexfmt.c',
]

mktexlsr_sources = [
  win32_srcdir / 'dirutil.c',
  win32_srcdir / 'mkpaths.c',
  win32_srcdir / 'mktex.h',
  win32_srcdir / 'mktexlsr.c',
]

mktexmf_sources = [
  win32_srcdir / 'dirutil.c',
  win32_srcdir / 'getdestdir.c',
  win32_srcdir / 'mkpaths.c',
  win32_srcdir / 'mktex.h',
  win32_srcdir / 'mktexmf.c',
  win32_srcdir / 'mktexupd.c',
]

mktexpk_sources = [
  win32_srcdir / 'dirutil.c',
  win32_srcdir / 'getdestdir.c',
  win32_srcdir / 'mkpaths.c',
  win32_srcdir / 'mktex.h',
  win32_srcdir / 'mktexpk.c',
  win32_srcdir / 'mktexupd.c',
]

mktextfm_sources = [
  win32_srcdir / 'dirutil.c',
  win32_srcdir / 'getdestdir.c',
  win32_srcdir / 'mkpaths.c',
  win32_srcdir / 'mktex.h',
  win32_srcdir / 'mktextfm.c',
  win32_srcdir / 'mktexupd.c',
]

mktexupd_sources = [
  win32_srcdir / 'mkpaths.c',
  win32_srcdir / 'mktex.h',
  win32_srcdir / 'mktexupdmain.c',
  win32_srcdir / 'mktexupd.c',
]


mktexfmt_exe = executable('mktexfmt',
  sources : mktexfmt_sources,
  c_args : win32_defines,
  dependencies : kpathsea_dep,
  install : true,
)

mktexlsr_exe = executable('mktexlsr',
  sources : mktexlsr_sources,
  c_args : win32_defines,
  dependencies : kpathsea_dep,
  install : true,
)

mktexmf_exe = executable('mktexmf',
  sources : mktexmf_sources,
  c_args : win32_defines,
  dependencies : kpathsea_dep,
  install : true,
)

mktexpk_exe = executable('mktexpk',
  sources : mktexpk_sources + w2c_headers,
  c_args : win32_defines,
  dependencies : kpathsea_dep,
  install : true,
)

mktextfm_exe = executable('mktextfm',
  sources : mktextfm_sources + w2c_headers,
  c_args : win32_defines,
  dependencies : kpathsea_dep,
  install : true,
)

mktexupd_exe = executable('mktexupd',
  sources : mktexupd_sources,
  c_args : win32_defines,
  dependencies : kpathsea_dep,
  install : true,
)
