#
# meson.build for the TeX Live subdirectory libs/harfbuzz/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

harfbuzz_srcdir = '../../../libs/harfbuzz'
harfbuzz_tree = harfbuzz_srcdir / 'harfbuzz-src'
harfbuzz_src = harfbuzz_tree / 'src'


harfbuzz_version = run_command(
  find_program('get-harfbuzz-version.py'),
  harfbuzz_srcdir / 'version.ac',
  check: true).stdout().strip()


harfbuzz_gen_headers = []

harfbuzz_gen_headers += configure_file(
  input : harfbuzz_tree / 'src/hb-version.h.in',
  output : 'hb-version.h',
  configuration : {
    'HB_VERSION_MAJOR' : harfbuzz_version.split('.')[0],
    'HB_VERSION_MINOR' : harfbuzz_version.split('.')[1],
    'HB_VERSION_MICRO' : harfbuzz_version.split('.')[2],
    'HB_VERSION' : harfbuzz_version,
  }
)


harfbuzz_includes = include_directories(
  harfbuzz_src,
)


harfbuzz_defines = []
harfbuzz_defines += [
  '-DHB_NO_MT',
  '-DHAVE_FALLBACK',
  '-DHAVE_GRAPHITE2',
]
harfbuzz_defines += [
  '-utf-8',
  '-bigobj', # harfbuzz.cc is huge
]
# NOTE: Unfortunately, harfbuzz emits a huge number of C4244 warnings,
#       so I will have no choice but to disable it.
harfbuzz_defines += [
  '-wd4244',
]

harfbuzz_sources = [
  harfbuzz_tree / 'src/harfbuzz.cc',
  harfbuzz_tree / 'src/graph/gsubgpos-context.cc',
  harfbuzz_tree / 'src/hb-subset-cff-common.cc',
  harfbuzz_tree / 'src/hb-subset-cff1.cc',
  harfbuzz_tree / 'src/hb-subset-cff2.cc',
  harfbuzz_tree / 'src/hb-subset-input.cc',
  harfbuzz_tree / 'src/hb-subset-instancer-iup.cc',
  harfbuzz_tree / 'src/hb-subset-instancer-solver.cc',
  harfbuzz_tree / 'src/hb-subset-plan-layout.cc',
  harfbuzz_tree / 'src/hb-subset-plan-var.cc',
  harfbuzz_tree / 'src/hb-subset-plan.cc',
  harfbuzz_tree / 'src/hb-subset-serialize.cc',
  harfbuzz_tree / 'src/hb-subset-table-cff.cc',
  harfbuzz_tree / 'src/hb-subset-table-color.cc',
  harfbuzz_tree / 'src/hb-subset-table-layout.cc',
  harfbuzz_tree / 'src/hb-subset-table-other.cc',
  harfbuzz_tree / 'src/hb-subset-table-var.cc',
  harfbuzz_tree / 'src/hb-subset.cc',
]


harfbuzz_lib = static_library('harfbuzz',
  harfbuzz_sources,
  harfbuzz_gen_headers,
  c_args : harfbuzz_defines,
  cpp_args : harfbuzz_defines,
  include_directories : harfbuzz_includes,
  dependencies : [
    graphite2_dep,
  ],
)


subdir('include')

harfbuzz_dep = declare_dependency(
  sources : harfbuzz_include_headers,
  include_directories : include_directories('include'),
  link_with : harfbuzz_lib,
  dependencies : [
    graphite2_dep,
  ],
)
