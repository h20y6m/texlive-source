#
# meson.build for the TeX Live subdirectory libs/harfbuzz/include/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

hdr_links = [
  '..' / harfbuzz_src / 'hb.h',
  '..' / harfbuzz_src / 'hb-aat-layout.h',
  '..' / harfbuzz_src / 'hb-aat.h',
  '..' / harfbuzz_src / 'hb-blob.h',
  '..' / harfbuzz_src / 'hb-buffer.h',
  '..' / harfbuzz_src / 'hb-common.h',
  '..' / harfbuzz_src / 'hb-deprecated.h',
  '..' / harfbuzz_src / 'hb-draw.h',
  '..' / harfbuzz_src / 'hb-face.h',
  '..' / harfbuzz_src / 'hb-font.h',
  '..' / harfbuzz_src / 'hb-map.h',
  '..' / harfbuzz_src / 'hb-ot-deprecated.h',
  '..' / harfbuzz_src / 'hb-paint.h',
  '..' / harfbuzz_src / 'hb-set.h',
  '..' / harfbuzz_src / 'hb-shape.h',
  '..' / harfbuzz_src / 'hb-shape-plan.h',
  '..' / harfbuzz_src / 'hb-style.h',
  '..' / harfbuzz_src / 'hb-subset-repacker.h',
  '..' / harfbuzz_src / 'hb-unicode.h',
  harfbuzz_gen_headers,
]
## native OpenType Layout backend
hdr_links += [
  '..' / harfbuzz_src / 'hb-ot.h',
  '..' / harfbuzz_src / 'hb-ot-color.h',
  '..' / harfbuzz_src / 'hb-ot-font.h',
  '..' / harfbuzz_src / 'hb-ot-layout.h',
  '..' / harfbuzz_src / 'hb-ot-math.h',
  '..' / harfbuzz_src / 'hb-ot-meta.h',
  '..' / harfbuzz_src / 'hb-ot-metrics.h',
  '..' / harfbuzz_src / 'hb-ot-name.h',
  '..' / harfbuzz_src / 'hb-ot-shape.h',
  '..' / harfbuzz_src / 'hb-ot-var.h',
]
## Graphite library
hdr_links += [
  '..' / harfbuzz_src / 'hb-graphite2.h',
]

harfbuzz_include_headers = []

foreach hdr : hdr_links
  harfbuzz_include_headers += configure_file(
    input: hdr,
    output: fs.name(hdr),
    copy: true,
  )
endforeach
