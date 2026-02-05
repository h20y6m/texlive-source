#
# meson.build for the TeX Live subdirectory libs/cairo/include/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

hdr_links = [
  '..' / cairo_tree / 'src/cairo.h',
  '..' / cairo_tree / 'src/cairo-deprecated.h',
  '..' / 'cairo-features.h',
  '..' / cairo_tree / 'cairo-version.h',
  '..' / cairo_tree / 'src/cairo-svg.h',
]

cairo_include_headers = []

foreach hdr : hdr_links
  cairo_include_headers += configure_file(
    input: hdr,
    output: fs.name(hdr),
    copy: true,
  )
endforeach
