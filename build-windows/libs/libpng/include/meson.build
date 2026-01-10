#
# meson.build for the TeX Live subdirectory libs/libpng/include
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

link_hdr = [
  '..' / libpng_tree / 'png.h',
  '..' / libpng_tree / 'pngconf.h',
  '..' / libpng_tree / 'pnglibconf.h',
]

libpng_include_headers = []

foreach hdr : link_hdr
  libpng_include_headers += configure_file(
    input : hdr,
    output : fs.name(hdr),
    copy : true,
  )
endforeach
