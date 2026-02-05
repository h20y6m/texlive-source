#
# meson.build for the TeX Live subdirectory libs/mpfr/include/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

mpfr_src = mpfr_tree / 'src'

hdr_links = [
  '..' / mpfr_src / 'mpfr.h',
  '..' / mpfr_src / 'mpf2mpfr.h',
]

mpfr_include_headers = []

foreach hdr : hdr_links
  mpfr_include_headers += configure_file(
    input: hdr,
    output: fs.name(hdr),
    copy: true,
  )
endforeach
