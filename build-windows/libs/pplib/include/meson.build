#
# meson.build for the TeX Live subdirectory libs/pplib/include/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

hdr_links = [
  '..' / pplib_src / 'ppapi.h',
  '..' / pplib_src / 'pparray.h',
  '..' / pplib_src / 'ppconf.h',
  '..' / pplib_src / 'ppcrypt.h',
  '..' / pplib_src / 'ppdict.h',
  '..' / pplib_src / 'ppfilter.h',
  '..' / pplib_src / 'ppheap.h',
  '..' / pplib_src / 'pplib.h',
  '..' / pplib_src / 'ppload.h',
  '..' / pplib_src / 'ppstream.h',
  '..' / pplib_src / 'ppxref.h',
  '..' / pplib_src / 'util/utilbasexx.h',
  '..' / pplib_src / 'util/utilcrypt.h',
  '..' / pplib_src / 'util/utilcryptdef.h',
  '..' / pplib_src / 'util/utildecl.h',
  '..' / pplib_src / 'util/utilflate.h',
  '..' / pplib_src / 'util/utilfpred.h',
  '..' / pplib_src / 'util/utiliof.h',
  '..' / pplib_src / 'util/utillog.h',
  '..' / pplib_src / 'util/utillzw.h',
  '..' / pplib_src / 'util/utilmd5.h',
  '..' / pplib_src / 'util/utilmem.h',
  '..' / pplib_src / 'util/utilmemallc.h',
  '..' / pplib_src / 'util/utilmemallh.h',
  '..' / pplib_src / 'util/utilmemheap.h',
  '..' / pplib_src / 'util/utilmemheapiof.h',
  '..' / pplib_src / 'util/utilmeminfo.h',
  '..' / pplib_src / 'util/utilnumber.h',
  '..' / pplib_src / 'util/utilplat.h',
  '..' / pplib_src / 'util/utilsha.h',
]

pplib_include_headers = []

foreach hdr : hdr_links
  pplib_include_headers += configure_file(
    input: hdr,
    output: fs.name(hdr),
    copy: true,
  )
endforeach
