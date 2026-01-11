#
# meson.build for the TeX Live subdirectory texk/web2c/w2c/
#
# Copyright 2025-2026 Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

w2c_dir = '../../../../texk/web2c/w2c/'

w2c_headers = []

conf_data = configuration_data()
conf_data.set('VERSION', tex_live_version)
if cc.has_header('stdbool.h')
  conf_data.set('HAVE_STDBOOL_H', 1)
endif

w2c_headers += configure_file(
  input : 'c-auto.h.in',
  output : 'c-auto.h',
  configuration : conf_data,
)
