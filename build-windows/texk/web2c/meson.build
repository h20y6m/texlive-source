#
# meson.build for the TeX Live subdirectory texk/web2c/
#
# Copyright 2025-2026 Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

subdir('lib')
subdir('web2c')

web2c_dir = '../../../texk/web2c'

web2c_convert_py = find_program('web2c-convert.py')
tangle_py = find_program('tangle.py')
tie_py = find_program('tie.py')
makecpool_py = find_program('makecpool.py')

########################################################################
#
# tangle and ctangle
#
########################################################################

# tangleboot

tangleboot_p = configure_file(
  input: web2c_dir / 'tangleboot.pin',
  output: 'tangleboot.p',
  copy: true,
)

tangleboot_sources = []
tangleboot_sources += custom_target('tangleboot.[ch]',
  input: [tangleboot_p],
  output: ['tangleboot.c', 'tangleboot.h'],
  command: [web2c_convert_py, 'tangleboot', 
    '--workdir', '@OUTDIR@',
    '--srcdir', '@CURRENT_SOURCE_DIR@' / web2c_dir,
    '--splitup', splitup_exe,
    '--web2c', web2c_exe,
    '--fixwrites', fixwrites_exe,
  ],
)

tangleboot_exe = executable('tangleboot',
  tangleboot_sources,
  c_args: ['-DWIN32'],
  include_directories: [web2c_dir],
  link_with: [proglib_lib],
  dependencies: [
    kpathsea_dep,
  ],
)

# tangle

tangle_p = custom_target('tangle.p',
  input: [
    web2c_dir / 'tangle.web',
    web2c_dir / 'tangle.ch',
  ],
  output: ['tangle.p'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', tangleboot_exe,
    'tangle', 'tangle',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join('.', meson.current_source_dir() / web2c_dir),
  }
)

tangle_c_h = custom_target('tangle.[ch]',
  input: [tangle_p],
  output: ['tangle.c', 'tangle.h'],
  command: [web2c_convert_py,
    '--workdir', '@OUTDIR@',
    '--srcdir', '@CURRENT_SOURCE_DIR@' / web2c_dir,
    '--splitup', splitup_exe,
    '--web2c', web2c_exe,
    '--fixwrites', fixwrites_exe,
    'tangle',
  ],
)

tangle_exe = executable('tangle',
  tangle_c_h,
  c_args: ['-DWIN32'],
  include_directories: [web2c_dir],
  link_with: [proglib_lib],
  dependencies: [
    kpathsea_dep,
  ],
)

# ctangleboot

ctangleboot_sources = []

ctangleboot_sources += configure_file(
  input: web2c_dir / 'ctangleboot.cin',
  output: 'ctangleboot.c',
  copy: true,
)

ctangleboot_sources += configure_file(
  input: web2c_dir / 'cwebboot.cin',
  output: 'cwebboot.c',
  copy: true,
)

ctangleboot_exe = executable('ctangleboot',
  ctangleboot_sources,
  c_args: ['-DWIN32'],
  include_directories: [web2c_dir],
  link_with: [proglib_lib],
  dependencies: [
    kpathsea_dep,
  ],
)

# ctangle

ctangle_sources = []

ctangle_sources += custom_target('ctangle.c',
  input: [
    web2c_dir / 'cwebdir/ctangle.w',
    web2c_dir / 'cwebdir/ctang-w2c.ch',
  ],
  output: ['ctangle.c'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', ctangleboot_exe,
    'ctangle', 'ctang-w2c.ch',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'CWEBINPUTS': ';'.join(meson.current_source_dir() / web2c_dir / 'cwebdir'),
  }
)

ctangle_sources += custom_target('cweb.c',
  input: [
    web2c_dir / 'cwebdir/common.w',
    web2c_dir / 'cwebdir/comm-w2c.ch',
  ],
  output: ['cweb.c'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', ctangleboot_exe,
    'common', 'comm-w2c.ch', 'cweb.c',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'CWEBINPUTS': ';'.join(meson.current_source_dir() / web2c_dir / 'cwebdir'),
  }
)

ctangle_exe = executable('ctangle',
  ctangle_sources,
  c_args: ['-DWIN32'],
  include_directories: [web2c_dir],
  link_with: [proglib_lib],
  dependencies: [
    kpathsea_dep,
  ],
)

########################################################################
#
# normal cweb programs
#
########################################################################

tie_c = custom_target('tie.c',
  input: [
    web2c_dir / 'tiedir/tie.w',
    web2c_dir / 'tiedir/tie-w2c.ch',
  ],
  output: ['tie.c'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', ctangle_exe,
    'tie.w', 'tie-w2c.ch',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'CWEBINPUTS': ';'.join(meson.current_source_dir() / web2c_dir / 'tiedir'),
  }
)

tie_exe = executable('tie',
  tie_c,
  c_args: ['-DNOT_WEB2C', '-DWIN32'],
  include_directories: [web2c_dir],
  link_with: [proglib_lib],
  dependencies: [
    kpathsea_dep,
  ],
)

########################################################################
#
# omegaware web programs
#
########################################################################

# otangle

otangle_p = custom_target('otangle.p',
  input: [
    web2c_dir / 'omegaware/otangle.web',
    web2c_dir / 'omegaware/otangle.ch',
  ],
  output: ['otangle.p'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', tangle_exe,
    'otangle', 'otangle',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '..',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir / 'omegaware',
    ),
  }
)

otangle_c_h = custom_target('otangle.[ch]',
  input: [otangle_p],
  output: ['otangle.c', 'otangle.h'],
  command: [web2c_convert_py,
    '--workdir', '@OUTDIR@',
    '--srcdir', '@CURRENT_SOURCE_DIR@' / web2c_dir,
    '--splitup', splitup_exe,
    '--web2c', web2c_exe,
    '--fixwrites', fixwrites_exe,
    'otangle',
  ],
)

otangle_exe = executable('otangle',
  otangle_c_h,
  c_args: ['-DWIN32'],
  include_directories: [web2c_dir],
  link_with: [proglib_lib],
  dependencies: [
    kpathsea_dep,
  ],
)

########################################################################
#
# SyncTeX
#
########################################################################

## libsynctex

## SyncTeX infrastructure: e-upTeX

euptex_ch_synctex = []
euptex_sources_synctex = []
euptex_defines_synctex = []

if get_option('enable_euptex_synctex')
  euptex_ch_synctex = [
    'synctexdir/synctex-def.ch0',
    'synctexdir/synctex-ep-mem.ch0',
    'synctexdir/synctex-mem.ch0',
    'synctexdir/synctex-e-mem.ch0',
    'synctexdir/synctex-ep-mem.ch1',
    'synctexdir/synctex-p-rec.ch0',
    'synctexdir/synctex-rec.ch0',
    'synctexdir/synctex-rec.ch1',
    'synctexdir/synctex-ep-rec.ch0',
    'synctexdir/synctex-e-rec.ch0',
    'synctexdir/synctex-p-rec.ch1',
  ]

  euptex_sources_synctex = [
    web2c_dir / 'synctexdir/synctex.c',
    web2c_dir / 'synctexdir/synctex.h',
    web2c_dir / 'synctexdir/synctex-common.h',
    web2c_dir / 'synctexdir/synctex-euptex.h',
  ]

  euptex_defines_synctex = [
    '-D__SyncTeX__',
    '-DSYNCTEX_ENGINE_H="synctex-euptex.h"',
  ]
endif

## SyncTeX infrastructure: XeTeX

xetex_ch_synctex = []
xetex_post_ch_synctex = []
xetex_sources_synctex = []
xetex_defines_synctex = []

if get_option('enable_xetex_synctex')
  xetex_ch_synctex = [
    'synctexdir/synctex-xe-def.ch0',
    'synctexdir/synctex-mem.ch0',
    'synctexdir/synctex-e-mem.ch0',
    'synctexdir/synctex-e-mem.ch1',
    'synctexdir/synctex-rec.ch0',
    'synctexdir/synctex-e-rec.ch0',
  ]

  xetex_post_ch_synctex = [
    'synctexdir/synctex-xe-rec.ch3',
  ]

  xetex_sources_synctex = [
    web2c_dir / 'synctexdir/synctex.c',
    web2c_dir / 'synctexdir/synctex.h',
    web2c_dir / 'synctexdir/synctex-common.h',
    web2c_dir / 'synctexdir/synctex-xetex.h',
  ]

  xetex_defines_synctex = [
    '-D__SyncTeX__',
    '-DSYNCTEX_ENGINE_H="synctex-xetex.h"',
  ]
endif

## SyncTeX infrastructure: npTeX

nptex_ch_synctex = []
nptex_post_ch_synctex = []
nptex_sources_synctex = []
nptex_defines_synctex = []

if get_option('enable_nptex_synctex')
  nptex_ch_synctex = [
    'synctexdir/synctex-xe-def.ch0',
    'synctexdir/synctex-np-mem.ch0',
    'synctexdir/synctex-mem.ch0',
    'synctexdir/synctex-e-mem.ch0',
    'synctexdir/synctex-np-mem.ch1',
    'synctexdir/synctex-np-rec.ch0',
    'synctexdir/synctex-rec.ch0',
    'synctexdir/synctex-rec.ch1',
    'synctexdir/synctex-np-rec.ch1',
    'synctexdir/synctex-e-rec.ch0',
    'synctexdir/synctex-np-rec.ch2',
  ]

  nptex_post_ch_synctex = [
    'synctexdir/synctex-np-rec.ch3',
  ]

  nptex_sources_synctex = [
    web2c_dir / 'synctexdir/synctex.c',
    web2c_dir / 'synctexdir/synctex.h',
    web2c_dir / 'synctexdir/synctex-common.h',
    web2c_dir / 'synctexdir/synctex-nptex.h',
  ]

  nptex_defines_synctex = [
    '-D__SyncTeX__',
    '-DSYNCTEX_ENGINE_H="synctex-nptex.h"',
  ]
endif

########################################################################
#
# libmd5
#
########################################################################

libmd5 = static_library('md5',
  web2c_dir / 'libmd5/md5.c',
  web2c_dir / 'libmd5/md5.h',
  include_directories: [
    web2c_dir / 'libmd5',
  ],
  c_args: [
    '-DWIN32',
  ],
)

libmd5_dep = declare_dependency(
  include_directories: include_directories(
    web2c_dir / 'libmd5',
  ),
  link_with: libmd5,
)

########################################################################
#
# libmputil, libmplib, used by MetaPost and luaTeX
#
########################################################################

## libmputil

libmputil_sources = [
  web2c_dir / 'mplibdir/avl.h',
  web2c_dir / 'mplibdir/avl.c',
  web2c_dir / 'mplibdir/decNumber.c',
  web2c_dir / 'mplibdir/decNumber.h',
  web2c_dir / 'mplibdir/decNumberLocal.h',
  web2c_dir / 'mplibdir/decContext.h',
  web2c_dir / 'mplibdir/decContext.c',
]

libmputil_lib = static_library('mputil',
  libmputil_sources,
  include_directories : include_directories(
    web2c_dir / 'mplibdir',
  ),
  c_args: [
    '-DWIN32',
  ],
)

## libmplib

libmplibcore_sources = []
libmplibextramath_sources = []
libmplibbackends_sources = []
libmplib_gen_c_h_files = {} # for pMetaPost, upMetaPost

libmplib_tfmin_c = custom_target('tfmin.c',
  input: [
    web2c_dir / 'mplibdir/tfmin.w',
  ],
  output: ['tfmin.c'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', ctangle_exe,
    'tfmin.w',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'CWEBINPUTS': meson.current_source_dir() / web2c_dir / 'mplibdir',
  }
)
libmplibcore_sources += libmplib_tfmin_c

libmplib_mp_c_h = custom_target('mp.[ch]',
  input: [
    web2c_dir / 'mplibdir/mp.w',
  ],
  output: [
    'mp.c',
    'mplib.h',
    'mpmp.h',
  ],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', ctangle_exe,
    'mp',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'CWEBINPUTS': meson.current_source_dir() / web2c_dir / 'mplibdir',
  }
)
libmplibcore_sources += libmplib_mp_c_h
libmplibcore_sources += web2c_dir / 'mplibdir/mpconfig.h'
libmplibextramath_sources += libmplib_mp_c_h[2]
libmplibbackends_sources += libmplib_mp_c_h[2]

foreach name : ['mpmath', 'mpmathbinary', 'mpmathdecimal', 'mpmathdouble', 'mpmathinterval', 'mpstrings']
  libmplib_c_h = custom_target(f'@name@.[ch]',
    input: [
      web2c_dir / 'mplibdir' / f'@name@.w',
    ],
    output: [
      f'@name@.h',
      f'@name@.c',
    ],
    command: [tangle_py,
      '--workdir', '@OUTDIR@',
      '--tangle', ctangle_exe,
      name,
    ],
    env: {
      'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
      'CWEBINPUTS': meson.current_source_dir() / web2c_dir / 'mplibdir',
    }
  )
  if name == 'mpmathbinary' or name == 'mpmathinterval'
    libmplibextramath_sources += libmplib_c_h
  else
    libmplibcore_sources += libmplib_c_h
  endif
  libmplib_gen_c_h_files += {
    f'@name@.h' : libmplib_c_h[0],
    f'@name@.c' : libmplib_c_h[1],
  }
endforeach

foreach name : ['ps', 'svg', 'png']
  libmplib_c_h = custom_target(f'mp@name@out.[ch]',
    input: [
      web2c_dir / 'mplibdir' / f'@name@out.w',
    ],
    output: [
      f'mplib@name@.h',
      f'mp@name@out.h',
      f'@name@out.c',
    ],
    command: [tangle_py,
      '--workdir', '@OUTDIR@',
      '--tangle', ctangle_exe,
      f'@name@out',
    ],
    env: {
      'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
      'CWEBINPUTS': meson.current_source_dir() / web2c_dir / 'mplibdir',
    }
  )
  if name == 'ps'
    libmplibcore_sources += libmplib_c_h
  else
    libmplibbackends_sources += libmplib_c_h
    libmplibcore_sources += [libmplib_c_h[0], libmplib_c_h[1]]
  endif
  libmplib_gen_c_h_files += {
    f'mplib@name@.h' : libmplib_c_h[0],
    f'mp@name@out.h' : libmplib_c_h[1],
    f'@name@out.c' : libmplib_c_h[2],
  }
endforeach

libmplibcore_lib = static_library('mplibcore',
  libmplibcore_sources,
  include_directories : include_directories(
    web2c_dir,
    web2c_dir / 'mplibdir',
  ),
  c_args: [
    '-DWIN32',
  ],
  dependencies : [
    libpng_dep,
    zlib_dep,
    kpathsea_dep,
  ],
)

libmplibcore_lib = static_library('mplibextramath',
  libmplibextramath_sources,
  include_directories : include_directories(
    web2c_dir,
    web2c_dir / 'mplibdir',
  ),
  c_args: [
    '-DWIN32',
  ],
  dependencies : [
    mpfi_dep,
    mpfr_dep,
    gmp_dep,
    kpathsea_dep,
  ],
)

libmplibcore_lib = static_library('mplibbackends',
  libmplibbackends_sources,
  include_directories : include_directories(
    web2c_dir,
    web2c_dir / 'mplibdir',
  ),
  c_args: [
    '-DWIN32',
  ],
  dependencies : [
    mpfi_dep,
    mpfr_dep,
    gmp_dep,
    cairo_dep,
    pixman_dep,
    libpng_dep,
    zlib_dep,
    kpathsea_dep,
  ],
)

########################################################################
#
# pMetaPost and upMetaPost
#
########################################################################

pmp_sed_py = find_program('pmp-sed.py')

pmpost_sources = []

foreach name : ['mpost', 'tfmin']
  pmpost_w = custom_target(f'p@name@.w',
    input: web2c_dir / 'mplibdir' / f'@name@.w',
    output: f'p@name@.w',
    command: [pmp_sed_py, '@INPUT@', '@OUTPUT@'],
  )
  pmpost_c = custom_target(f'p@name@.c',
    input: [
      pmpost_w,
      web2c_dir / 'pmpostdir' / f'p@name@.ch',
    ],
    output: f'p@name@.c',
    command: [tangle_py,
      '--workdir', '@OUTDIR@',
      '--tangle', ctangle_exe,
      f'p@name@', f'p@name@',
    ],
    env: {
      'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
      'CWEBINPUTS': ';'.join(['.', meson.current_source_dir() / web2c_dir / 'pmpostdir']),
    }
  )
  pmpost_sources += pmpost_c
endforeach

pmpost_pmp_w = custom_target('pmp.w',
  input: web2c_dir / 'mplibdir' / 'mp.w',
  output: f'pmp.w',
  command: [pmp_sed_py, '@INPUT@', '@OUTPUT@'],
)
pmpost_pmp_c_h = custom_target('pmp.[ch]',
  input: [
    pmpost_pmp_w,
    web2c_dir / 'pmpostdir' / 'pmp.ch',
  ],
  output: [
    'pmp.c',
    'pmplib.h',
    'pmpmp.h',
  ],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', ctangle_exe,
    'pmp', 'pmp',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'CWEBINPUTS': ';'.join(['.', meson.current_source_dir() / web2c_dir / 'pmpostdir']),
  }
)
pmpost_sources += pmpost_pmp_c_h

foreach name : ['mpmath', 'mpmathbinary', 'mpmathdecimal', 'mpmathdouble', 'mpmathinterval', 'mpstrings']
  pmpost_c = custom_target(f'p@name@.c',
    input: libmplib_gen_c_h_files[f'@name@.c'],
    output: f'p@name@.c',
    command: [pmp_sed_py, '@INPUT@', '@OUTPUT@'],
  )
  pmpost_sources += pmpost_c
  pmpost_h = custom_target(f'p@name@.h',
    input: libmplib_gen_c_h_files[f'@name@.h'],
    output: f'p@name@.h',
    command: [pmp_sed_py, '@INPUT@', '@OUTPUT@'],
  )
  pmpost_sources += pmpost_h
endforeach

foreach name : ['mpxout']
  pmpost_w = custom_target(f'p@name@.w',
    input: web2c_dir / 'mplibdir' / f'@name@.w',
    output: f'p@name@.w',
    command: [pmp_sed_py, '@INPUT@', '@OUTPUT@'],
  )
  pmpost_c_h = custom_target(f'p@name@.[ch]',
    input: [
      pmpost_w,
      web2c_dir / 'pmpostdir' / f'p@name@.ch',
    ],
    output: [
      f'p@name@.c',
      f'p@name@.h',
    ],
    command: [tangle_py,
      '--workdir', '@OUTDIR@',
      '--tangle', ctangle_exe,
      f'p@name@', f'p@name@',
    ],
    env: {
      'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
      'CWEBINPUTS': ';'.join(['.', meson.current_source_dir() / web2c_dir / 'pmpostdir']),
    }
  )
  pmpost_sources += pmpost_c_h
endforeach

foreach name : ['ps', 'svg']
  pmpost_w = custom_target(f'p@name@out.w',
    input: web2c_dir / 'mplibdir' / f'@name@out.w',
    output: f'p@name@out.w',
    command: [pmp_sed_py, '@INPUT@', '@OUTPUT@'],
  )
  pmpost_c_h = custom_target(f'p@name@out.[ch]',
    input: [
      pmpost_w,
      web2c_dir / 'pmpostdir' / f'p@name@out.ch',
    ],
    output: [
      f'pmplib@name@.h',
      f'pmp@name@out.h',
      f'p@name@out.c',
    ],
    command: [tangle_py,
      '--workdir', '@OUTDIR@',
      '--tangle', ctangle_exe,
      f'p@name@out', f'p@name@out',
    ],
    env: {
      'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
      'CWEBINPUTS': ';'.join(['.', meson.current_source_dir() / web2c_dir / 'pmpostdir']),
    }
  )
  pmpost_sources += pmpost_c_h
endforeach

foreach name : ['png']
  pmpost_h = custom_target(f'pmplib@name@.h',
    input: libmplib_gen_c_h_files[f'mplib@name@.h'],
    output: f'pmplib@name@.h',
    command: [pmp_sed_py, '@INPUT@', '@OUTPUT@'],
  )
  pmpost_sources += pmpost_h
  pmpost_h = custom_target(f'pmp@name@out.h',
    input: libmplib_gen_c_h_files[f'mp@name@out.h'],
    output: f'pmp@name@out.h',
    command: [pmp_sed_py, '@INPUT@', '@OUTPUT@'],
  )
  pmpost_sources += pmpost_h
  pmpost_c = custom_target(f'p@name@out.c',
    input: libmplib_gen_c_h_files[f'@name@out.c'],
    output: f'p@name@out.c',
    command: [pmp_sed_py, '@INPUT@', '@OUTPUT@'],
  )
  pmpost_sources += pmpost_c
endforeach

if get_option('enable_pmp')
  pmpost_dll = shared_library('pmpost',
    pmpost_sources,
    include_directories : include_directories(
      web2c_dir,
      web2c_dir / 'pmpostdir',
      web2c_dir / 'mplibdir',
    ),
    c_args: [
      '-DWIN32',
    ],
    link_with : [
      libmputil_lib,
      libmputil_lib,
    ],
    dependencies : [
      mpfi_dep,
      mpfr_dep,
      gmp_dep,
      cairo_dep,
      pixman_dep,
      libpng_dep,
      zlib_dep,
      ptexenc_dep,
      kpathsea_dep,
    ],
    install : true,
  )
  pmpost_calldll_exe = executable('pmpost-calldll',
    '../calldll/calldll.c',
    c_args : '-DDLLPROC=dllpmpostmain',
    implicit_include_directories : false,
    link_with: pmpost_dll,
  )
  foreach exe : ['pmpost.exe', 'pdvitomp.exe', 'r-pmpost.exe']
    custom_target(exe,
      input: pmpost_calldll_exe,
      output: exe,
      command: [copyfile_py, '@INPUT@', '@OUTPUT@'],
      build_by_default : true,
      install : true,
      install_dir : get_option('bindir'),
    )
  endforeach
endif # enable_upmp

if get_option('enable_upmp')
  upmpost_dll = shared_library('upmpost',
    pmpost_sources,
    include_directories : include_directories(
      web2c_dir,
      web2c_dir / 'pmpostdir',
      web2c_dir / 'mplibdir',
    ),
    c_args: [
      '-DUPMP',
      '-DWIN32',
    ],
    link_with : [
      libmputil_lib,
      libmputil_lib,
    ],
    dependencies : [
      mpfi_dep,
      mpfr_dep,
      gmp_dep,
      cairo_dep,
      pixman_dep,
      libpng_dep,
      zlib_dep,
      ptexenc_dep,
      kpathsea_dep,
    ],
    install : true,
  )
  upmpost_calldll_exe = executable('upmpost-calldll',
    '../calldll/calldll.c',
    c_args : '-DDLLPROC=dllupmpostmain',
    implicit_include_directories : false,
    link_with: upmpost_dll,
  )
  foreach exe : ['upmpost.exe', 'updvitomp.exe', 'r-upmpost.exe']
    custom_target(exe,
      input: upmpost_calldll_exe,
      output: exe,
      command: [copyfile_py, '@INPUT@', '@OUTPUT@'],
      build_by_default : true,
      install : true,
      install_dir : get_option('bindir'),
    )
  endforeach
endif # enable_upmp

########################################################################
#
# upTeX
#
########################################################################

uptex_includes = [
  web2c_dir,
  web2c_dir / 'uptexdir',
]

uptex_defines = [
  '-DWIN32=1',
  '-DHAVE_CONFIG_H=1',
]

## libukanji

libukanji_lib = static_library('ukanji',
  web2c_dir / 'uptexdir/kanji.c',
  web2c_dir / 'uptexdir/kanji.h',
  web2c_dir / 'uptexdir/kanji_dump.c',
  include_directories : include_directories(
    web2c_dir,
  ),
  c_args: [],
  dependencies : [
    ptexenc_dep,
    kpathsea_dep,
    zlib_dep,
  ],
)

## upbibtex

upbibtex_web = custom_target('upbibtex.web',
  input: [
    web2c_dir / 'bibtex.web',
    web2c_dir / 'bibtex.ch',
  ],
  output: ['upbibtex.web'],
  command: [tie_py,
    '--workdir', '@OUTDIR@',
    '--tie', tie_exe,
    '-m', 'upbibtex.web',
    'bibtex.web',
    'bibtex.ch',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir
    ),
  },
)

upbibtex_p = custom_target('upbibtex.p',
  input: [
    upbibtex_web,
    web2c_dir / 'uptexdir/upbibtex.ch',
  ],
  output: ['upbibtex.p'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', tangle_exe,
    'upbibtex', 'upbibtex',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir / 'uptexdir',
      meson.current_source_dir() / web2c_dir,
    ),
  }
)

upbibtex_c_h = custom_target('upbibtex.[ch]',
  input: [
    upbibtex_p,
    web2c_dir / 'uptexdir/uptex.defines',
  ],
  output: ['upbibtex.c', 'upbibtex.h'],
  command: [web2c_convert_py,
    '--workdir', '@OUTDIR@',
    '--srcdir', '@CURRENT_SOURCE_DIR@' / web2c_dir,
    '--splitup', splitup_exe,
    '--web2c', web2c_exe,
    '--fixwrites', fixwrites_exe,
    'upbibtex',
  ],
)

upbibtex_sources = [
  web2c_dir / 'uptexdir/kanji.h',
]

upbibtex_exe = executable('upbibtex',
  upbibtex_c_h,
  upbibtex_sources,
  include_directories : include_directories(uptex_includes),
  c_args: uptex_defines,
  link_with: [
    libukanji_lib,
    pproglib_lib,
    proglib_lib,
  ],
  dependencies : [
    ptexenc_dep,
    kpathsea_dep,
    libmd5_dep,
    zlib_dep,
    win32api_winsock2,
  ],
  install : true,
)

custom_target('pbibtex.exe',
  input: upbibtex_exe,
  output: 'pbibtex.exe',
  command: [copyfile_py, '@INPUT@', '@OUTPUT@'],
  build_by_default : true,
  install : true,
  install_dir : get_option('bindir'),
)

## updvitype

updvitype_web = custom_target('updvitype.web',
  input: [
    web2c_dir / 'dvitype.web',
    web2c_dir / 'dvitype.ch',
  ],
  output: ['updvitype.web'],
  command: [tie_py,
    '--workdir', '@OUTDIR@',
    '--tie', tie_exe,
    '-m', 'updvitype.web',
    'dvitype.web',
    'dvitype.ch',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir
    ),
  },
)

updvitype_p = custom_target('updvitype.p',
  input: [
    updvitype_web,
    web2c_dir / 'uptexdir/updvitype.ch',
  ],
  output: ['updvitype.p'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', tangle_exe,
    'updvitype', 'updvitype',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir / 'uptexdir',
      meson.current_source_dir() / web2c_dir,
    ),
  }
)

updvitype_c_h = custom_target('updvitype.[ch]',
  input: [
    updvitype_p,
    web2c_dir / 'uptexdir/uptex.defines',
  ],
  output: ['updvitype.c', 'updvitype.h'],
  command: [web2c_convert_py,
    '--workdir', '@OUTDIR@',
    '--srcdir', '@CURRENT_SOURCE_DIR@' / web2c_dir,
    '--splitup', splitup_exe,
    '--web2c', web2c_exe,
    '--fixwrites', fixwrites_exe,
    'updvitype',
  ],
)

updvitype_sources = [
  web2c_dir / 'uptexdir/kanji.h',
]

updvitype_exe = executable('updvitype',
  updvitype_c_h,
  updvitype_sources,
  include_directories : include_directories(uptex_includes),
  c_args: uptex_defines,
  link_with: [
    libukanji_lib,
    pproglib_lib,
    proglib_lib,
  ],
  dependencies : [
    ptexenc_dep,
    kpathsea_dep,
    libmd5_dep,
    zlib_dep,
    win32api_winsock2,
  ],
  install : true,
)

custom_target('pdvitype.exe',
  input: updvitype_exe,
  output: 'pdvitype.exe',
  command: [copyfile_py, '@INPUT@', '@OUTPUT@'],
  build_by_default : true,
  install : true,
  install_dir : get_option('bindir'),
)

## uppltotf

uppltotf_web = custom_target('uppltotf.web',
  input: [
    web2c_dir / 'pltotf.web',
    web2c_dir / 'pltotf.ch',
  ],
  output: ['uppltotf.web'],
  command: [tie_py,
    '--workdir', '@OUTDIR@',
    '--tie', tie_exe,
    '-m', 'uppltotf.web',
    'pltotf.web',
    'pltotf.ch',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir
    ),
  },
)

uppltotf_p = custom_target('uppltotf.p',
  input: [
    uppltotf_web,
    web2c_dir / 'uptexdir/uppltotf.ch',
  ],
  output: ['uppltotf.p'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', tangle_exe,
    'uppltotf', 'uppltotf',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir / 'uptexdir',
      meson.current_source_dir() / web2c_dir,
    ),
  }
)

uppltotf_c_h = custom_target('uppltotf.[ch]',
  input: [
    uppltotf_p,
    web2c_dir / 'uptexdir/uptex.defines',
  ],
  output: ['uppltotf.c', 'uppltotf.h'],
  command: [web2c_convert_py,
    '--workdir', '@OUTDIR@',
    '--srcdir', '@CURRENT_SOURCE_DIR@' / web2c_dir,
    '--splitup', splitup_exe,
    '--web2c', web2c_exe,
    '--fixwrites', fixwrites_exe,
    'uppltotf',
  ],
)

uppltotf_sources = [
  web2c_dir / 'uptexdir/kanji.h',
]

uppltotf_exe = executable('uppltotf',
  uppltotf_c_h,
  uppltotf_sources,
  include_directories : include_directories(uptex_includes),
  c_args: uptex_defines,
  link_with: [
    libukanji_lib,
    pproglib_lib,
    proglib_lib,
  ],
  dependencies : [
    ptexenc_dep,
    kpathsea_dep,
    libmd5_dep,
    zlib_dep,
    win32api_winsock2,
  ],
  install : true,
)

custom_target('ppltotf.exe',
  input: uppltotf_exe,
  output: 'ppltotf.exe',
  command: [copyfile_py, '@INPUT@', '@OUTPUT@'],
  build_by_default : true,
  install : true,
  install_dir : get_option('bindir'),
)

## uptftopl

uptftopl_web = custom_target('uptftopl.web',
  input: [
    web2c_dir / 'tftopl.web',
    web2c_dir / 'tftopl.ch',
  ],
  output: ['uptftopl.web'],
  command: [tie_py,
    '--workdir', '@OUTDIR@',
    '--tie', tie_exe,
    '-m', 'uptftopl.web',
    'tftopl.web',
    'tftopl.ch',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir
    ),
  },
)

uptftopl_p = custom_target('uptftopl.p',
  input: [
    uptftopl_web,
    web2c_dir / 'uptexdir/uptftopl.ch',
  ],
  output: ['uptftopl.p'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', tangle_exe,
    'uptftopl', 'uptftopl',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir / 'uptexdir',
      meson.current_source_dir() / web2c_dir,
    ),
  }
)

uptftopl_c_h = custom_target('uptftopl.[ch]',
  input: [
    uptftopl_p,
    web2c_dir / 'uptexdir/uptex.defines',
  ],
  output: ['uptftopl.c', 'uptftopl.h'],
  command: [web2c_convert_py,
    '--workdir', '@OUTDIR@',
    '--srcdir', '@CURRENT_SOURCE_DIR@' / web2c_dir,
    '--splitup', splitup_exe,
    '--web2c', web2c_exe,
    '--fixwrites', fixwrites_exe,
    'uptftopl',
  ],
)

uptftopl_sources = [
  web2c_dir / 'uptexdir/kanji.h',
]

uptftopl_exe = executable('uptftopl',
  uptftopl_c_h,
  uptftopl_sources,
  include_directories : include_directories(uptex_includes),
  c_args: uptex_defines,
  link_with: [
    libukanji_lib,
    pproglib_lib,
    proglib_lib,
  ],
  dependencies : [
    ptexenc_dep,
    kpathsea_dep,
    libmd5_dep,
    zlib_dep,
    win32api_winsock2,
  ],
  install : true,
)

custom_target('ptftopl.exe',
  input: uptftopl_exe,
  output: 'ptftopl.exe',
  command: [copyfile_py, '@INPUT@', '@OUTPUT@'],
  build_by_default : true,
  install : true,
  install_dir : get_option('bindir'),
)

########################################################################
#
# e-upTeX
#
########################################################################

euptex_includes = include_directories(
  '.',
  web2c_dir,
  web2c_dir / 'euptexdir',
)

euptex_defines = [
  '-DWIN32=1',
  '-DHAVE_CONFIG_H=1',
]

euptex_web_srcs = [
  'tex.web',
  'etexdir/etex.ch',
  'etexdir/tex.ch0',
  'tex.ch',
  'tracingstacklevels.ch',
  'partoken.ch',
  'locnull-optimize.ch',
  'showstream.ch',
  'zlib-fmt.ch',
  'etexdir/tex.ech',
]
euptex_web_inputs = []
foreach src : euptex_web_srcs
  euptex_web_inputs += web2c_dir / src
endforeach

euptex_web = custom_target('euptex.web',
  input: euptex_web_inputs,
  output: ['euptex.web'],
  command: [tie_py,
    '--workdir', '@OUTDIR@',
    '--tie', tie_exe,
    '-m', 'euptex.web',
    euptex_web_srcs,
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir
    ),
  },
)

euptex_ch_srcs = [
  'euptexdir/etex.ch0',
  'uptexdir/ptex-base.ch',
  'uptexdir/uptex-m.ch',
  'euptexdir/eptex.ech',
  'euptexdir/etex.ch1',
] +  euptex_ch_synctex + [
  'unbalanced-braces.ch',
  'euptexdir/fam256.ch',
  'euptexdir/pdfutils.ch',
  'euptexdir/suppresserrors.ch',
  'euptexdir/char-warning-eptex.ch',
  'tex-binpool.ch',
]
euptex_ch_inputs = []
foreach src : euptex_ch_srcs
  euptex_ch_inputs += web2c_dir / src
endforeach

euptex_ch = custom_target('euptex.ch',
  input: [
    euptex_web,
    euptex_ch_inputs,
  ],
  output: ['euptex.ch'],
  command: [tie_py,
    '--workdir', '@OUTDIR@',
    '--tie', tie_exe,
    '-c', 'euptex.ch',
    'euptex.web',
    euptex_ch_srcs,
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir
    ),
  },
)

euptex_p_pool = custom_target('euptex.p',
  input: [
    euptex_web,
    euptex_ch,
  ],
  output: ['euptex.p', 'euptex.pool'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', tangle_exe,
    'euptex', 'euptex',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '..',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir / 'euptexdir',
    ),
  }
)

euptex_c_h = custom_target('euptex.[ch]',
  input: [
    euptex_p_pool[0],
    web2c_dir / 'euptexdir/euptex.defines',
  ],
  output: ['euptexini.c', 'euptex0.c', 'euptexcoerce.h', 'euptexd.h'],
  command: [web2c_convert_py,
    '--workdir', '@OUTDIR@',
    '--srcdir', '@CURRENT_SOURCE_DIR@' / web2c_dir,
    '--splitup', splitup_exe,
    '--web2c', web2c_exe,
    '--fixwrites', fixwrites_exe,
    'euptex',
  ],
)

euptex_pool_c = custom_target('euptex-pool.c',
  input: [
    euptex_p_pool[1],
    euptex_c_h[3],
  ],
  output: ['euptex-pool.c'],
  command: [makecpool_py,
    '--workdir', '@OUTDIR@',
    '--makecpool', makecpool_exe,
    '--output', '@OUTPUT@',
    'euptex',
  ],
)

euptex_sources = [
  euptex_c_h,
  euptex_pool_c,
]
euptex_sources += [
  web2c_dir / 'euptexdir/euptexextra.c',
  web2c_dir / 'euptexdir/euptexextra.h',
]
euptex_sources += [
  web2c_dir / 'etexdir/etex_version.h',
  web2c_dir / 'uptexdir/ptex_version.h',
  web2c_dir / 'euptexdir/eptex_version.h',
  web2c_dir / 'uptexdir/uptex_version.h',
]


if get_option('enable_euptex')
  euptex_dll = shared_library('euptex',
    euptex_sources + euptex_sources_synctex,
    include_directories : euptex_includes,
    c_args: euptex_defines + euptex_defines_synctex,
    link_with: [
      libukanji_lib,
      pproglib_lib,
      proglib_lib,
    ],
    dependencies : [
      ptexenc_dep,
      kpathsea_dep,
      libmd5_dep,
      zlib_dep,
      win32api_winsock2,
    ],
    install : true,
  )

  euptex_calldll_exe = executable('euptex-calldll',
    '../calldll/calldll.c',
    c_args : '-DDLLPROC=dlleuptexmain',
    implicit_include_directories : false,
    link_with: euptex_dll,
  )

  foreach exe : [
    'eptex.exe',
    'euptex.exe',
    'platex.exe',
    'platex-dev.exe',
    'ptex.exe',
    'uplatex.exe',
    'uplatex-dev.exe',
    'uptex.exe',
  ]
    custom_target(exe,
      input: euptex_calldll_exe,
      output: exe,
      command: [copyfile_py, '@INPUT@', '@OUTPUT@'],
      build_by_default : true,
      install : true,
      install_dir : get_option('bindir'),
    )
  endforeach

endif # enable_euptex

########################################################################
#
# XeTeX
#
########################################################################

xetex_includes = include_directories(
  '.',
  web2c_dir,
  web2c_dir / 'xetexdir',
)

xetex_defines = [
  '-DWIN32=1',
  '-D_CRT_DECLARE_NONSTDC_NAMES', # enable POSIX function names (strdup, etc.)
  '-DHAVE_CONFIG_H=1',
]

xetex_deps = [
   kpathsea_dep,
   libpng_dep,
   fontconfig_dep,
   freetype_dep,
   graphite2_dep,
   harfbuzz_dep,
   icu_dep,
   pplib_dep,
   teckit_dep,
   libmd5_dep,
   win32api_winsock2,
]

## xetex web2c

xetex_ch_srcs = [
  'xetexdir/xetex.web',
  'xetexdir/tex.ch0',
  'tex.ch',
  'tracingstacklevels.ch',
  'partoken-102.ch',
  'partoken.ch',
  'locnull-optimize.ch',
  'unbalanced-braces.ch',
  'showstream.ch',
] + xetex_ch_synctex + [
  'xetexdir/xetex.ch',
] + xetex_post_ch_synctex + [
  'xetexdir/char-warning-xetex.ch',
  'tex-binpool.ch',
]
xetex_final_ch_input = []
foreach src : xetex_ch_srcs
  xetex_final_ch_input += web2c_dir / src
endforeach

xetex_final_ch = custom_target('xetex-final.ch',
  input: xetex_final_ch_input,
  output: ['xetex-final.ch'],
  command: [tie_py,
    '--workdir', '@OUTDIR@',
    '--tie', tie_exe,
    '-c', 'xetex-final.ch',
    xetex_ch_srcs,
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir
    ),
  },
)

xetex_p_pool = custom_target('xetex.p',
  input: [
    web2c_dir / 'xetexdir/xetex.web',
    xetex_final_ch,
  ],
  output: ['xetex.p', 'xetex.pool'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', otangle_exe,
    'xetex', 'xetex-final',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '..',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir / 'xetexdir',
    ),
  }
)

xetex_c_h = custom_target('xetex.[ch]',
  input: [
    xetex_p_pool[0],
    web2c_dir / 'xetexdir/xetex.defines',
  ],
  output: ['xetexini.c', 'xetex0.c', 'xetexcoerce.h', 'xetexd.h'],
  command: [web2c_convert_py,
    '--workdir', '@OUTDIR@',
    '--srcdir', '@CURRENT_SOURCE_DIR@' / web2c_dir,
    '--splitup', splitup_exe,
    '--web2c', web2c_exe,
    '--fixwrites', fixwrites_exe,
    'xetex',
  ],
)

xetex_pool_c = custom_target('xetex-pool.c',
  input: [
    xetex_p_pool[1],
    xetex_c_h[3],
  ],
  output: ['xetex-pool.c'],
  command: [makecpool_py,
    '--workdir', '@OUTDIR@',
    '--makecpool', makecpool_exe,
    '--output', '@OUTPUT@',
    'xetex',
  ],
)

## libxetex

libxetex_sources = [
  web2c_dir / 'xetexdir/XeTeXFontInst.cpp',
  web2c_dir / 'xetexdir/XeTeXFontInst.h',
  web2c_dir / 'xetexdir/XeTeXFontMgr.cpp',
  web2c_dir / 'xetexdir/XeTeXFontMgr.h',
  web2c_dir / 'xetexdir/XeTeXLayoutInterface.cpp',
  web2c_dir / 'xetexdir/XeTeXLayoutInterface.h',
  web2c_dir / 'xetexdir/XeTeXOTMath.cpp',
  web2c_dir / 'xetexdir/XeTeXOTMath.h',
  web2c_dir / 'xetexdir/XeTeX_ext.c',
  web2c_dir / 'xetexdir/XeTeX_ext.h',
  web2c_dir / 'xetexdir/XeTeX_pic.c',
  web2c_dir / 'xetexdir/XeTeX_web.h',
  web2c_dir / 'xetexdir/XeTeXswap.h',
  web2c_dir / 'xetexdir/trans.c',
  web2c_dir / 'xetexdir/trans.h',
  web2c_dir / 'xetexdir/hz.cpp',
  web2c_dir / 'xetexdir/xetex.h',
  web2c_dir / 'xetexdir/pdfimage.cpp',
  web2c_dir / 'xetexdir/pdfimage.h',
  web2c_dir / 'xetexdir/image/bmpimage.c',
  web2c_dir / 'xetexdir/image/bmpimage.h',
  web2c_dir / 'xetexdir/image/jpegimage.c',
  web2c_dir / 'xetexdir/image/jpegimage.h',
  web2c_dir / 'xetexdir/image/mfileio.c',
  web2c_dir / 'xetexdir/image/mfileio.h',
  web2c_dir / 'xetexdir/image/numbers.c',
  web2c_dir / 'xetexdir/image/numbers.h',
  web2c_dir / 'xetexdir/image/pngimage.c',
  web2c_dir / 'xetexdir/image/pngimage.h',
]

libxetex_sources += [
  web2c_dir / 'xetexdir/XeTeXFontMgr_FC.cpp',
  web2c_dir / 'xetexdir/XeTeXFontMgr_FC.h',
]

libxetex_defines = xetex_defines

libxetex_lib = static_library('libxetex',
  libxetex_sources,
  xetex_c_h[3],
  w2c_headers,
  include_directories : xetex_includes,
  c_args: libxetex_defines,
  cpp_args: libxetex_defines,
  dependencies : xetex_deps,
)

## xetex

xetex_sources = [
  xetex_c_h,
  xetex_pool_c,
]

xetex_sources += [
  web2c_dir / 'xetexdir/xetexextra.c',
  web2c_dir / 'xetexdir/xetexextra.h',
  web2c_dir / 'xetexdir/etex_version.h',
  web2c_dir / 'xetexdir/xetex_version.h',
]


if get_option('enable_xetex')
  xetex_dll = shared_library('xetex',
    xetex_sources + xetex_sources_synctex,
    include_directories : xetex_includes,
    c_args: xetex_defines + xetex_defines_synctex,
    cpp_args: xetex_defines + xetex_defines_synctex,
    link_with: [
      libxetex_lib,
      proglib_lib,
    ],
    dependencies : xetex_deps,
    install : true,
  )

  xetex_calldll_exe = executable('xetex-calldll',
    '../calldll/calldll.c',
    c_args : '-DDLLPROC=dllxetexmain',
    implicit_include_directories : false,
    link_with: xetex_dll,
  )

  foreach exe : ['xetex.exe', 'xelatex.exe', 'xelatex-dev.exe']
    custom_target(exe,
      input: xetex_calldll_exe,
      output: exe,
      command: [copyfile_py, '@INPUT@', '@OUTPUT@'],
      build_by_default : true,
      install : true,
      install_dir : get_option('bindir'),
    )
  endforeach
endif # enable_xetex


########################################################################
#
# npTeX
#
########################################################################

nptex_includes = [xetex_includes] + [include_directories(
  web2c_dir / 'nptexdir',
)]

nptex_defines = xetex_defines

nptex_deps = xetex_deps + [
  ptexenc_dep,
]

## nptex web2c

nptex_ch_srcs = [
  'nptexdir/nptex.web',
  'nptexdir/tex.ch0',
  'tex.ch',
  'tracingstacklevels.ch',
  'partoken.ch',
  'locnull-optimize.ch',
  'unbalanced-braces.ch',
  'showstream.ch',
] + nptex_ch_synctex + [
  'nptexdir/nptex.ch',
] + nptex_post_ch_synctex + [
  'xetexdir/char-warning-xetex.ch',
  'tex-binpool.ch',
]

nptex_final_ch_input = []
foreach src : nptex_ch_srcs
  nptex_final_ch_input += web2c_dir / src
endforeach

nptex_final_ch = custom_target('nptex-final.ch',
  input: nptex_final_ch_input,
  output: ['nptex-final.ch'],
  command: [tie_py,
    '--workdir', '@OUTDIR@',
    '--tie', tie_exe,
    '-c', 'nptex-final.ch',
    nptex_ch_srcs,
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '../kpathsea',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir
    ),
  },
)

nptex_p_pool = custom_target('nptex.p',
  input: [
    web2c_dir / 'nptexdir/nptex.web',
    nptex_final_ch,
  ],
  output: ['nptex.p', 'nptex.pool'],
  command: [tangle_py,
    '--workdir', '@OUTDIR@',
    '--tangle', otangle_exe,
    'nptex', 'nptex-final',
  ],
  env: {
    'TEXMFCNF': meson.current_source_dir() / web2c_dir / '..',
    'WEBINPUTS': ';'.join(
      '.',
      meson.current_source_dir() / web2c_dir / 'nptexdir',
    ),
  }
)

nptex_c_h = custom_target('nptex.[ch]',
  input: [
    nptex_p_pool[0],
    web2c_dir / 'nptexdir/nptex.defines',
  ],
  output: ['nptexini.c', 'nptex0.c', 'nptexcoerce.h', 'nptexd.h'],
  command: [web2c_convert_py,
    '--workdir', '@OUTDIR@',
    '--srcdir', '@CURRENT_SOURCE_DIR@' / web2c_dir,
    '--splitup', splitup_exe,
    '--web2c', web2c_exe,
    '--fixwrites', fixwrites_exe,
    'nptex',
  ],
)

nptex_pool_c = custom_target('nptex-pool.c',
  input: [
    nptex_p_pool[1],
    nptex_c_h[3],
  ],
  output: ['nptex-pool.c'],
  command: [makecpool_py,
    '--workdir', '@OUTDIR@',
    '--makecpool', makecpool_exe,
    '--output', '@OUTPUT@',
    'nptex',
  ],
)

## libnptex

libnptex_defines = nptex_defines + ['-DnpTeX_h']

libnptex_lib = static_library('libnptex',
 web2c_dir / 'xetexdir/XeTeX_ext.c', 
 nptex_c_h[3], # nptexd.h
 w2c_headers,
 include_directories : nptex_includes,
 c_args: libnptex_defines,
 cpp_args: libnptex_defines,
 dependencies : nptex_deps,
)

## nptex

nptex_sources = [
  nptex_c_h,
  nptex_pool_c,
]

nptex_sources += [
  web2c_dir / 'nptexdir/nptexextra.c',
  web2c_dir / 'nptexdir/nptexextra.h',
  web2c_dir / 'nptexdir/etex_version.h',
  web2c_dir / 'nptexdir/xetex_version.h',
  web2c_dir / 'nptexdir/nptex_version.h',
]

if get_option('enable_nptex')
  nptex_dll = shared_library('nptex',
    nptex_sources,
    nptex_sources_synctex,
    include_directories : nptex_includes,
    c_args: nptex_defines + nptex_defines_synctex,
    cpp_args: nptex_defines + nptex_defines_synctex,
    link_with: [
      libnptex_lib,
      libxetex_lib,
      proglib_lib,
    ],
    dependencies : nptex_deps,
    install : true,
  )

  nptex_calldll_exe = executable('nptex-calldll',
    '../calldll/calldll.c',
    c_args : '-DDLLPROC=dllnptexmain',
    implicit_include_directories : false,
    link_with: nptex_dll,
  )

  foreach exe : ['nptex.exe', 'nplatex.exe', 'nplatex-dev.exe']
    custom_target(exe,
      input: nptex_calldll_exe,
      output: exe,
      command: [copyfile_py, '@INPUT@', '@OUTPUT@'],
      build_by_default : true,
      install : true,
      install_dir : get_option('bindir'),
    )
  endforeach
endif # enable_nptex