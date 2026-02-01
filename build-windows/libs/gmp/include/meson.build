#
# meson.build for the TeX Live subdirectory libs/gmp/include/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

hdr_links = [
  gmp_h,
]

gmp_include_headers = []

foreach hdr : hdr_links
  gmp_include_headers += configure_file(
    input: hdr,
    output: fs.name(hdr),
    copy: true,
  )
endforeach
