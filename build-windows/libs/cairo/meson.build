#
# meson.build for the TeX Live subdirectory libs/cairo/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

# cairo is included in the TeX Live tree but is not usable with MSVC.
# Use the version in windows-src2025.tar.xz from Kakuto.
#cairo_srcdir = '../../../libs/cairo'
cairo_srcdir = '.'
cairo_tree = cairo_srcdir / 'cairo-src'
cairo_src = cairo_tree / 'src'


cairo_gen_headers = []


cairo_includes = include_directories(
  cairo_src,
)


cairo_defines = []

# Disables a huge number of warnings from cairo.
cairo_defines += [
  '/wd4146',
  '/wd4244',
  '/wd5286',
  '/wd5287',
]

cairo_sources = [
  cairo_tree / 'src/cairo-analysis-surface.c',
  cairo_tree / 'src/cairo-arc.c',
  cairo_tree / 'src/cairo-array.c',
  cairo_tree / 'src/cairo-atomic.c',
  cairo_tree / 'src/cairo-base64-stream.c',
  cairo_tree / 'src/cairo-base85-stream.c',
  cairo_tree / 'src/cairo-bentley-ottmann-rectangular.c',
  cairo_tree / 'src/cairo-bentley-ottmann-rectilinear.c',
  cairo_tree / 'src/cairo-bentley-ottmann.c',
  cairo_tree / 'src/cairo-botor-scan-converter.c',
  cairo_tree / 'src/cairo-boxes-intersect.c',
  cairo_tree / 'src/cairo-boxes.c',
  cairo_tree / 'src/cairo-cache.c',
  cairo_tree / 'src/cairo-clip-boxes.c',
  cairo_tree / 'src/cairo-clip-polygon.c',
  cairo_tree / 'src/cairo-clip-region.c',
  cairo_tree / 'src/cairo-clip-surface.c',
  cairo_tree / 'src/cairo-clip-tor-scan-converter.c',
  cairo_tree / 'src/cairo-clip.c',
  cairo_tree / 'src/cairo-color.c',
  cairo_tree / 'src/cairo-composite-rectangles.c',
  cairo_tree / 'src/cairo-compositor.c',
  cairo_tree / 'src/cairo-contour.c',
  cairo_tree / 'src/cairo-damage.c',
  cairo_tree / 'src/cairo-debug.c',
  cairo_tree / 'src/cairo-default-context.c',
  cairo_tree / 'src/cairo-device.c',
  cairo_tree / 'src/cairo-error.c',
  cairo_tree / 'src/cairo-fallback-compositor.c',
  cairo_tree / 'src/cairo-fixed.c',
  cairo_tree / 'src/cairo-font-face-twin-data.c',
  cairo_tree / 'src/cairo-font-face-twin.c',
  cairo_tree / 'src/cairo-font-face.c',
  cairo_tree / 'src/cairo-font-options.c',
  cairo_tree / 'src/cairo-freed-pool.c',
  cairo_tree / 'src/cairo-freelist.c',
  cairo_tree / 'src/cairo-gstate.c',
  cairo_tree / 'src/cairo-hash.c',
  cairo_tree / 'src/cairo-hull.c',
  cairo_tree / 'src/cairo-image-compositor.c',
  cairo_tree / 'src/cairo-image-info.c',
  cairo_tree / 'src/cairo-image-source.c',
  cairo_tree / 'src/cairo-image-surface.c',
  cairo_tree / 'src/cairo-line.c',
  cairo_tree / 'src/cairo-lzw.c',
  cairo_tree / 'src/cairo-mask-compositor.c',
  cairo_tree / 'src/cairo-matrix.c',
  cairo_tree / 'src/cairo-mempool.c',
  cairo_tree / 'src/cairo-mesh-pattern-rasterizer.c',
  cairo_tree / 'src/cairo-misc.c',
  cairo_tree / 'src/cairo-mono-scan-converter.c',
  cairo_tree / 'src/cairo-mutex.c',
  cairo_tree / 'src/cairo-no-compositor.c',
  cairo_tree / 'src/cairo-observer.c',
  cairo_tree / 'src/cairo-output-stream.c',
  cairo_tree / 'src/cairo-paginated-surface.c',
  cairo_tree / 'src/cairo-path-bounds.c',
  cairo_tree / 'src/cairo-path-fill.c',
  cairo_tree / 'src/cairo-path-fixed.c',
  cairo_tree / 'src/cairo-path-in-fill.c',
  cairo_tree / 'src/cairo-path-stroke-boxes.c',
  cairo_tree / 'src/cairo-path-stroke-polygon.c',
  cairo_tree / 'src/cairo-path-stroke-traps.c',
  cairo_tree / 'src/cairo-path-stroke-tristrip.c',
  cairo_tree / 'src/cairo-path-stroke.c',
  cairo_tree / 'src/cairo-path.c',
  cairo_tree / 'src/cairo-pattern.c',
  cairo_tree / 'src/cairo-pen.c',
  cairo_tree / 'src/cairo-polygon-intersect.c',
  cairo_tree / 'src/cairo-polygon-reduce.c',
  cairo_tree / 'src/cairo-polygon.c',
  cairo_tree / 'src/cairo-raster-source-pattern.c',
  cairo_tree / 'src/cairo-recording-surface.c',
  cairo_tree / 'src/cairo-rectangle.c',
  cairo_tree / 'src/cairo-rectangular-scan-converter.c',
  cairo_tree / 'src/cairo-region.c',
  cairo_tree / 'src/cairo-rtree.c',
  cairo_tree / 'src/cairo-scaled-font.c',
  cairo_tree / 'src/cairo-shape-mask-compositor.c',
  cairo_tree / 'src/cairo-slope.c',
  cairo_tree / 'src/cairo-spans-compositor.c',
  cairo_tree / 'src/cairo-spans.c',
  cairo_tree / 'src/cairo-spline.c',
  cairo_tree / 'src/cairo-stroke-dash.c',
  cairo_tree / 'src/cairo-stroke-style.c',
  cairo_tree / 'src/cairo-surface-clipper.c',
  cairo_tree / 'src/cairo-surface-fallback.c',
  cairo_tree / 'src/cairo-surface-observer.c',
  cairo_tree / 'src/cairo-surface-offset.c',
  cairo_tree / 'src/cairo-surface-snapshot.c',
  cairo_tree / 'src/cairo-surface-subsurface.c',
  cairo_tree / 'src/cairo-surface-wrapper.c',
  cairo_tree / 'src/cairo-surface.c',
  cairo_tree / 'src/cairo-time.c',
  cairo_tree / 'src/cairo-tor-scan-converter.c',
  cairo_tree / 'src/cairo-tor22-scan-converter.c',
  cairo_tree / 'src/cairo-toy-font-face.c',
  cairo_tree / 'src/cairo-traps-compositor.c',
  cairo_tree / 'src/cairo-traps.c',
  cairo_tree / 'src/cairo-tristrip.c',
  cairo_tree / 'src/cairo-unicode.c',
  cairo_tree / 'src/cairo-user-font.c',
  cairo_tree / 'src/cairo-version.c',
  cairo_tree / 'src/cairo-wideint.c',
  cairo_tree / 'src/cairo.c',

  cairo_tree / 'src/cairo-cff-subset.c',
  cairo_tree / 'src/cairo-scaled-font-subsets.c',
  cairo_tree / 'src/cairo-truetype-subset.c',
  cairo_tree / 'src/cairo-type1-fallback.c',
  cairo_tree / 'src/cairo-type1-glyph-names.c',
  cairo_tree / 'src/cairo-type1-subset.c',
  cairo_tree / 'src/cairo-type3-glyph-surface.c',

  cairo_tree / 'src/cairo-pdf-operators.c',
  cairo_tree / 'src/cairo-pdf-shading.c',
  cairo_tree / 'src/cairo-tag-attributes.c',

  cairo_tree / 'src/cairo-deflate-stream.c',

  cairo_tree / 'src/win32/cairo-win32-debug.c',
  cairo_tree / 'src/win32/cairo-win32-device.c',
  cairo_tree / 'src/win32/cairo-win32-gdi-compositor.c',
  cairo_tree / 'src/win32/cairo-win32-system.c',
  cairo_tree / 'src/win32/cairo-win32-surface.c',
  cairo_tree / 'src/win32/cairo-win32-display-surface.c',
  cairo_tree / 'src/win32/cairo-win32-printing-surface.c',

  cairo_tree / 'src/win32/cairo-win32-font.c',

  cairo_tree / 'src/cairo-png.c',

  cairo_tree / 'src/cairo-script-surface.c',

  cairo_tree / 'src/cairo-ps-surface.c',

  cairo_tree / 'src/cairo-pdf-surface.c',
  cairo_tree / 'src/cairo-pdf-interchange.c',
  cairo_tree / 'src/cairo-tag-stack.c',

  cairo_tree / 'src/cairo-svg-surface.c',
]


cairo_lib = static_library('cairo',
  cairo_sources,
  cairo_gen_headers,
  c_args : cairo_defines,
  include_directories : cairo_includes,
  dependencies : [
    pixman_dep,
    libpng_dep,
    zlib_dep,
  ],
)


subdir('cairo')

cairo_dep = declare_dependency(
  sources : cairo_include_headers,
  include_directories : include_directories('cairo'),
  compile_args : ['-DCAIRO_WIN32_STATIC_BUILD'],
  link_with : cairo_lib,
  dependencies : [
    pixman_dep,
    libpng_dep,
    zlib_dep,
  ],
)
