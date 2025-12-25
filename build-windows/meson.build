#
# meson.build for the TeX Live
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

project('texlive',
  ['c', 'cpp'],
  version: run_command(
    find_program('get-texlive-version.py'), '../version.ac',
    check: true).stdout().strip(),
  meson_version: '>=1.1.0',
  default_options: [
    'cpp_std=c++17', # icu and its dependent targets require C++17.
  ],
)

tex_live_version = meson.project_version()


python_exe = find_program('python3')
copyfile_py = find_program('copyfile.py')

fs = import('fs')

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')


win32api_winsock2 = cc.find_library('ws2_32', required : true)


subdir('texk/kpathsea')
subdir('texk/web2c/w2c')
subdir('texk/kpathsea/win32') # depends on w2c

subdir('libs/libpaper')
subdir('libs/zlib')
subdir('libs/libpng') # depends on zlib

subdir('texk/dvipdfm-x')
subdir('texk/ptexenc')

subdir('libs/freetype2')
subdir('libs/graphite2')
subdir('libs/harfbuzz') # depends on graphite2
subdir('libs/icu')
subdir('libs/pplib')
subdir('libs/teckit')

subdir('libs/expat')
subdir('libs/fontconfig') # depends on expat, freetype2, kpathsea

subdir('texk/web2c')
