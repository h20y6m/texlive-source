#
# meson.build for the TeX Live subdirectory libs/teckit/include/teckit
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

teckit_dir = '../../../../../libs/teckit'
teckit_src = teckit_dir / 'TECkit-src'

teckit_headers = []
foreach hdr : ['TECkit_Common.h','TECkit_Compiler.h','TECkit_Engine.h',]
  teckit_headers += configure_file(
    input: teckit_src / 'source/Public-headers' / hdr,
    output: hdr,
    copy: true,
  )
endforeach
