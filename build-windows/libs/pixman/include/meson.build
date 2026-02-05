#
# meson.build for the TeX Live subdirectory libs/pixman/include/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

hdr_links = [
  '..' / pixman_src / 'pixman.h',
  pixman_version_h,
]

pixman_include_headers = []

foreach hdr : hdr_links
  pixman_include_headers += configure_file(
    input: hdr,
    output: fs.name(hdr),
    copy: true,
  )
endforeach
