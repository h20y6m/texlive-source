#
# meson.build for the TeX Live subdirectory libs/mpfi/include/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

hdr_links = [
  '..' / mpfi_src / 'mpfi.h',
  '..' / mpfi_src / 'mpfi-impl.h',
  '..' / mpfi_src / 'mpfi_io.h',
]

mpfi_include_headers = []

foreach hdr : hdr_links
  mpfi_include_headers += configure_file(
    input: hdr,
    output: fs.name(hdr),
    copy: true,
  )
endforeach
