#
# meson.build for the TeX Live subdirectory libs/pixman/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

pixman_srcdir = '../../../libs/pixman'
pixman_tree = pixman_srcdir / 'pixman-src'
pixman_src = pixman_tree / 'pixman'


pixman_version = run_command(
  find_program('get-pixman-version.py'),
  pixman_srcdir / 'version.ac',
  check: true).stdout().strip()


pixman_gen_headers = []

version_conf = configuration_data()
pixman_version_parts = pixman_version.split('.')
version_conf.set('PIXMAN_VERSION_MAJOR', pixman_version_parts[0])
version_conf.set('PIXMAN_VERSION_MINOR', pixman_version_parts[1])
version_conf.set('PIXMAN_VERSION_MICRO', pixman_version_parts[2])
pixman_version_h = configure_file(
  input : pixman_tree / 'pixman/pixman-version.h.in',
  output : 'pixman-version.h',
  configuration : version_conf,
)
pixman_gen_headers += pixman_version_h


pixman_includes = include_directories(
  pixman_src,
)


pixman_defines = []
pixman_defines += [
  '-DPACKAGE=pixman-1',
  '-DPACKAGE_VERSION=""',
  '-DPACKAGE_BUGREPORT=""',
]
pixman_defines += [
  '/wd4244',
]

libpixman_sources = [
  pixman_tree / 'pixman/pixman.c',
  pixman_tree / 'pixman/pixman-access.c',
  pixman_tree / 'pixman/pixman-access-accessors.c',
  pixman_tree / 'pixman/pixman-bits-image.c',
  pixman_tree / 'pixman/pixman-combine32.c',
  pixman_tree / 'pixman/pixman-combine-float.c',
  pixman_tree / 'pixman/pixman-conical-gradient.c',
  pixman_tree / 'pixman/pixman-filter.c',
  pixman_tree / 'pixman/pixman-x86.c',
  pixman_tree / 'pixman/pixman-mips.c',
  pixman_tree / 'pixman/pixman-arm.c',
  pixman_tree / 'pixman/pixman-ppc.c',
  pixman_tree / 'pixman/pixman-edge.c',
  pixman_tree / 'pixman/pixman-edge-accessors.c',
  pixman_tree / 'pixman/pixman-fast-path.c',
  pixman_tree / 'pixman/pixman-glyph.c',
  pixman_tree / 'pixman/pixman-general.c',
  pixman_tree / 'pixman/pixman-gradient-walker.c',
  pixman_tree / 'pixman/pixman-image.c',
  pixman_tree / 'pixman/pixman-implementation.c',
  pixman_tree / 'pixman/pixman-linear-gradient.c',
  pixman_tree / 'pixman/pixman-matrix.c',
  pixman_tree / 'pixman/pixman-noop.c',
  pixman_tree / 'pixman/pixman-radial-gradient.c',
  pixman_tree / 'pixman/pixman-region16.c',
  pixman_tree / 'pixman/pixman-region32.c',
  pixman_tree / 'pixman/pixman-solid-fill.c',
  pixman_tree / 'pixman/pixman-timer.c',
  pixman_tree / 'pixman/pixman-trap.c',
  pixman_tree / 'pixman/pixman-utils.c',
]


pixman_lib = static_library('pixman',
  libpixman_sources,
  pixman_gen_headers,
  c_args : pixman_defines,
  include_directories : pixman_includes,
  dependencies : [
  ],
)


subdir('include')

pixman_dep = declare_dependency(
  sources : pixman_include_headers,
  include_directories : include_directories('include'),
  link_with : pixman_lib,
  dependencies : [
  ],
)
