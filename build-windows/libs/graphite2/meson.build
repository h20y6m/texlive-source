#
# meson.build for the TeX Live subdirectory libs/graphite2/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

graphite2_dir = '../../../libs/graphite2'
graphite2_src = graphite2_dir / 'graphite2-src'


graphite2_defines = [
  '-DGRAPHITE2_STATIC=1',
  '-DGRAPHITE2_NTRACING=1',
  '-DWIN32=1',
  '-D_WINDOWS=1',
  '-DUNICODE=1',
]

graphite2_includes = include_directories(
  graphite2_src / 'src',
  graphite2_src / 'include',
)

graphite2_sources = [
  graphite2_src / 'src/CmapCache.cpp',
  graphite2_src / 'src/Code.cpp',
  graphite2_src / 'src/Collider.cpp',
  graphite2_src / 'src/Decompressor.cpp',
  graphite2_src / 'src/Face.cpp',
  graphite2_src / 'src/FeatureMap.cpp',
  graphite2_src / 'src/Font.cpp',
  graphite2_src / 'src/GlyphCache.cpp',
  graphite2_src / 'src/GlyphFace.cpp',
  graphite2_src / 'src/Intervals.cpp',
  graphite2_src / 'src/Justifier.cpp',
  graphite2_src / 'src/NameTable.cpp',
  graphite2_src / 'src/Pass.cpp',
  graphite2_src / 'src/Position.cpp',
  graphite2_src / 'src/Segment.cpp',
  graphite2_src / 'src/Silf.cpp',
  graphite2_src / 'src/Slot.cpp',
  graphite2_src / 'src/Sparse.cpp',
  graphite2_src / 'src/TtfUtil.cpp',
  graphite2_src / 'src/UtfCodec.cpp',
  graphite2_src / 'src/gr_char_info.cpp',
  graphite2_src / 'src/gr_face.cpp',
  graphite2_src / 'src/gr_features.cpp',
  graphite2_src / 'src/gr_font.cpp',
  graphite2_src / 'src/gr_logging.cpp',
  graphite2_src / 'src/gr_segment.cpp',
  graphite2_src / 'src/gr_slot.cpp',
]

graphite2_sources += [
  graphite2_src / 'src/call_machine.cpp',
]

graphite2_sources += [
  graphite2_src / 'src/FileFace.cpp',
]


graphite2_lib = static_library('graphite2',
  graphite2_sources,
  cpp_args : graphite2_defines,
  include_directories : graphite2_includes,
  override_options : ['cpp_std=c++14'], # graphite2 use deprecated features in C++17
)

graphite2_dep = declare_dependency(
  include_directories : include_directories(
    graphite2_src / 'include',
  ),
  compile_args : ['-DGRAPHITE2_STATIC=1'],
  link_with : graphite2_lib,
)
