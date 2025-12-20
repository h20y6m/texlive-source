#
# meson.build for the TeX Live subdirectory libs/zlib/include
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

link_hdr = [
  '..' / zlib_tree / 'zlib.h',
  zlib_zconf_h,
]

zlib_include_headers = []

foreach hdr : link_hdr
  zlib_include_headers += configure_file(
    input : hdr,
    output : fs.name(hdr),
    copy : true,
  )
endforeach
