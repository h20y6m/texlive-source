#
# meson.build for the TeX Live subdirectory libs/fontconfig/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

fontconfig_dir = '.'
fontconfig_src = fontconfig_dir / 'fontconfig-src'


fontconfig_includes = include_directories(
  fontconfig_src,
  '../../texk/kpathsea',
)

fontconfig_defines = [
  '-DXML_STATIC=1',
  '-DHAVE_CONFIG_H=1',
  '-DWIN32=1',
  '-D_WIN32=1',
]

fontconfig_sources = files([
  fontconfig_src / 'src/fcatomic.c',
  fontconfig_src / 'src/fccache.c',
  fontconfig_src / 'src/fccfg.c',
  fontconfig_src / 'src/fccharset.c',
  fontconfig_src / 'src/fccompat.c',
  fontconfig_src / 'src/fcdbg.c',
  fontconfig_src / 'src/fcdefault.c',
  fontconfig_src / 'src/fcdir.c',
  fontconfig_src / 'src/fcformat.c',
  fontconfig_src / 'src/fcfreetype.c',
  fontconfig_src / 'src/fcfs.c',
  fontconfig_src / 'src/fchash.c',
  fontconfig_src / 'src/fcinit.c',
  fontconfig_src / 'src/fclang.c',
  fontconfig_src / 'src/fclist.c',
  fontconfig_src / 'src/fcmatch.c',
  fontconfig_src / 'src/fcmatrix.c',
  fontconfig_src / 'src/fcname.c',
  fontconfig_src / 'src/fcobjs.c',
  fontconfig_src / 'src/fcpat.c',
  fontconfig_src / 'src/fcptrlist.c',
  fontconfig_src / 'src/fcrange.c',
  fontconfig_src / 'src/fcserialize.c',
  fontconfig_src / 'src/fcstat.c',
  fontconfig_src / 'src/fcstr.c',
  fontconfig_src / 'src/fcxml.c',
  fontconfig_src / 'src/fcweight.c',
  fontconfig_src / 'src/ftglue.c',
])


fontconfig_lib = static_library('fontconfig',
  fontconfig_sources,
  c_args : fontconfig_defines,
  include_directories : fontconfig_includes,
  dependencies : [
    expat_dep,
    freetype_dep,
    kpathsea_dep,
  ],
)

fontconfig_dep = declare_dependency(
  include_directories: fontconfig_includes,
  link_with: fontconfig_lib,
)

