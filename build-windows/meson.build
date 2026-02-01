#
# meson.build for the TeX Live
#
# Copyright 2025-2026 Yukimasa Morimi <h20y6m@yahoo.co.jp>
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

# Meson adds the /utf-8 option by default, but vs backend does not.
if meson.backend().startswith('vs')
  add_project_arguments('/utf-8', language: ['c', 'cpp'])
endif


tex_live_version = meson.project_version()


python_exe = find_program('python3')
copyfile_py = find_program('copyfile.py')

fs = import('fs')

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')


win32api_winsock2 = cc.find_library('ws2_32', required : true)


## kpathsea library

subdir('texk/kpathsea')
subdir('texk/web2c/w2c')
subdir('texk/kpathsea/win32') # depends on w2c

## Dependent Libraries

subdir('libs/libpaper')
subdir('libs/zlib')
subdir('libs/libpng') # depends on zlib

subdir('libs/freetype2')
subdir('libs/graphite2')
subdir('libs/harfbuzz') # depends on graphite2
subdir('libs/icu')
subdir('libs/pplib')
subdir('libs/teckit')

subdir('libs/gmp')
subdir('libs/mpfr') # depends on gmp

## Additional libraries for Windows

subdir('libs/expat')
subdir('libs/fontconfig') # depends on expat, freetype2, kpathsea

## texk programs

subdir('texk/ptexenc')

if get_option('enable_dvi2tty')
  subdir('texk/dvi2tty') # depends on ptexenc
endif
if get_option('enable_dviout_util')
  subdir('texk/dviout-util') # depends on ptexenc
endif
if get_option('enable_dvipdfm_x')
  subdir('texk/dvipdfm-x')
endif
if get_option('enable_dvipsk')
  subdir('texk/dvipsk')
endif
if get_option('enable_makejvf')
  subdir('texk/makejvf') # depends on ptexenc
endif
if get_option('enable_mendexk')
  subdir('texk/mendexk') # depends on ptexenc
endif
if get_option('enable_seetexk')
  subdir('texk/seetexk')
endif
if get_option('enable_upmendex')
  subdir('texk/upmendex') # depends on icu
endif

## web2c programs

subdir('texk/web2c')
