#
# meson.build for the TeX Live subdirectory texk/ptexenc/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

ptexenc_dir = '../../../texk/ptexenc'

ptexenc_version = run_command(
  find_program('get-ptexenc-version.py'), ptexenc_dir / 'version.ac',
  check: true).stdout().strip()

libptexenc_gen_headers = []
libptexenc_gen_headers += configure_file(
  input : 'c-auto.h.in',
  output : 'c-auto.h',
  configuration : {
    'VERSION' : ptexenc_version,
  }
)

libptexenc_sources = [
  ptexenc_dir / 'jisx0208.h',
  ptexenc_dir / 'kanjicnv.c',
  ptexenc_dir / 'ptexenc.c',
  ptexenc_dir / 'ptexenc/kanjicnv.h',
  ptexenc_dir / 'ptexenc/unicode-jp.h',
  ptexenc_dir / 'unicode-jp.c',
  ptexenc_dir / 'unicode.c',
]

libptexenc_lib = static_library('ptexenc',
  libptexenc_sources,
  libptexenc_gen_headers,
  include_directories : [
    ptexenc_dir,
  ],
  c_args : [
    '-DWIN32=1',
  ],
  dependencies : [
    kpathsea_dep,
  ],
)

ptexenc_dep = declare_dependency(
  sources : [
    libptexenc_gen_headers,
  ],
  include_directories : include_directories(
    ptexenc_dir,
  ),
  link_with : [
    libptexenc_lib,
  ],
)