#
# meson.build for the TeX Live subdirectory libs/freetype2/
#
# Copyright 2025-2026 Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

freetype_dir = '../../../libs/freetype2'
freetype_src = freetype_dir / 'freetype-src'


freetype_includes = include_directories(
  freetype_src / 'include',
)

freetype_defines = [
  '-DFT_CONFIG_MODULES_H=<ftmodule.h>',
  '-DFT_CONFIG_OPTIONS_H=<ftoption.h>',
  '-DFT2_BUILD_LIBRARY=1',
]

freetype_sources = [
  'ftmodule.h',
  'ftoption.h',
]

freetype_sources += files([
  freetype_src / 'src/base/ftbase.c',
  freetype_src / 'src/base/ftinit.c',
])

# FONT_MODULES
freetype_sources += files([
  freetype_src / 'src/truetype/truetype.c',
  freetype_src / 'src/type1/type1.c',
  freetype_src / 'src/cff/cff.c',
  freetype_src / 'src/cid/type1cid.c',
  freetype_src / 'src/pfr/pfr.c',
  freetype_src / 'src/type42/type42.c',
  freetype_src / 'src/winfonts/winfnt.c',
  freetype_src / 'src/pcf/pcf.c',
  freetype_src / 'src/bdf/bdf.c',
  freetype_src / 'src/sfnt/sfnt.c',
])

# HINTING_MODULES
freetype_sources += files([
  freetype_src / 'src/autofit/autofit.c',
  freetype_src / 'src/pshinter/pshinter.c',
])

# RASTER_MODULES
freetype_sources += files([
  freetype_src / 'src/smooth/smooth.c',
  freetype_src / 'src/raster/raster.c',
  freetype_src / 'src/svg/svg.c',
  freetype_src / 'src/sdf/sdf.c',
])

# AUX_MODULES
freetype_sources += files([
  freetype_src / 'src/cache/ftcache.c',
  freetype_src / 'src/gzip/ftgzip.c',
  freetype_src / 'src/lzw/ftlzw.c',
  freetype_src / 'src/psaux/psaux.c',
  freetype_src / 'src/psnames/psnames.c',
])


# BASE_EXTENSIONS
freetype_sources += files([
  freetype_src / 'src/base/ftbbox.c',
  freetype_src / 'src/base/ftbdf.c',
  freetype_src / 'src/base/ftbitmap.c',
  freetype_src / 'src/base/ftcid.c',
  freetype_src / 'src/base/ftfstype.c',
  freetype_src / 'src/base/ftgasp.c',
  freetype_src / 'src/base/ftglyph.c',
  freetype_src / 'src/base/ftgxval.c',
  freetype_src / 'src/base/ftmm.c',
  freetype_src / 'src/base/ftotval.c',
  freetype_src / 'src/base/ftpatent.c',
  freetype_src / 'src/base/ftpfr.c',
  freetype_src / 'src/base/ftstroke.c',
  freetype_src / 'src/base/ftsynth.c',
  freetype_src / 'src/base/fttype1.c',
  freetype_src / 'src/base/ftwinfnt.c',
])

# System support file.
freetype_sources += files([
  freetype_src / 'builds/windows/ftsystem.c',
])

# Debug support file
freetype_sources += [
  freetype_src / 'builds/windows/ftdebug.c',
]


freetype_lib = static_library('freetype',
  freetype_sources,
  c_args : freetype_defines,
  include_directories : freetype_includes,
)

freetype_dep = declare_dependency(
  include_directories : freetype_includes,
  link_with : freetype_lib,
)
