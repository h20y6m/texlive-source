#
# meson.build for the TeX Live subdirectory libs/libpng/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

libpng_srcdir = '../../../libs/libpng'
libpng_tree = libpng_srcdir / 'libpng-src'


libpng_includes = include_directories(
  libpng_tree,
)

libpng_defines = [
  '-D_CRT_NONSTDC_NO_DEPRECATE',
  '-D_CRT_SECURE_NO_DEPRECATE',
]


libpng_sources = [
  libpng_tree / 'png.c',
  libpng_tree / 'pngerror.c',
  libpng_tree / 'pngget.c',
  libpng_tree / 'pngmem.c',
  libpng_tree / 'pngpread.c',
  libpng_tree / 'pngread.c',
  libpng_tree / 'pngrio.c',
  libpng_tree / 'pngrtran.c',
  libpng_tree / 'pngrutil.c',
  libpng_tree / 'pngset.c',
  libpng_tree / 'pngtrans.c',
  libpng_tree / 'pngwio.c',
  libpng_tree / 'pngwrite.c',
  libpng_tree / 'pngwtran.c',
  libpng_tree / 'pngwutil.c',
]

if host_machine.cpu() == 'aarch64'
  libpng_defines += [
    '-DPNG_ARM_NEON_OPT=2',
  ]

  libpng_sources += [
    libpng_tree / 'arm/arm_init.c',
    libpng_tree / 'arm/filter_neon_intrinsics.c',
    libpng_tree / 'arm/palette_neon_intrinsics.c',
  ]
endif

if host_machine.cpu() == 'x86' or host_machine.cpu() == 'x86_64'
  libpng_defines += [
    '-DPNG_INTEL_SSE_OPT=1',
  ]

  libpng_sources += [
    libpng_tree / 'intel/intel_init.c',
    libpng_tree / 'intel/filter_sse2_intrinsics.c',
  ]
endif


libpng_lib = static_library('png',
  libpng_sources,
  c_args : libpng_defines,
  include_directories : libpng_includes,
  dependencies : [
    zlib_dep,
  ],
)


subdir('include')

libpng_dep = declare_dependency(
  sources: libpng_include_headers,
  include_directories: include_directories('include'),
  link_with: libpng_lib,
  dependencies : [
    zlib_dep,
  ],
)
