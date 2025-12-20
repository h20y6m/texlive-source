#
# meson.build for the TeX Live subdirectory texk/web2c/w2c/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

w2c_dir = '../../../../texk/web2c/w2c/'

w2c_headers = []

w2c_headers += configure_file(
  input : 'c-auto.h.in',
  output : 'c-auto.h',
  configuration : {
    'VERSION' : tex_live_version,
  }
)
