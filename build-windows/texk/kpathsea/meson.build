#
# meson.build for the TeX Live subdirectory texk/kpathsea/
#
# Copyright 2025      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

kpathsea_srcdir = '../../../texk/kpathsea'

kpse_version = run_command(
    find_program('get-kpathsea-version.py'), kpathsea_srcdir / 'version.ac',
    check: true).stdout().strip()


libkpathsea_gen_headers = []

libkpathsea_gen_headers += configure_file(
  input : 'c-auto.h.in',
  output : 'c-auto.h',
  configuration : {
    'VERSION' : kpse_version,
  }
)


libkpathsea_includes = include_directories(
  '..',
  kpathsea_srcdir / '..',
)

libkpathsea_defines = [
  '-DMAKE_KPSE_DLL',
  '-DWIN32',
]


libkpathsea_sources = [
  kpathsea_srcdir / 'tex-file.c',
  kpathsea_srcdir / 'absolute.c',
  kpathsea_srcdir / 'atou.c',
  kpathsea_srcdir / 'cnf.c',
  kpathsea_srcdir / 'concat.c',
  kpathsea_srcdir / 'concat3.c',
  kpathsea_srcdir / 'concatn.c',
  kpathsea_srcdir / 'db.c',
  kpathsea_srcdir / 'debug.c',
  kpathsea_srcdir / 'dir.c',
  kpathsea_srcdir / 'elt-dirs.c',
  kpathsea_srcdir / 'expand.c',
  kpathsea_srcdir / 'extend-fname.c',
  kpathsea_srcdir / 'file-p.c',
  kpathsea_srcdir / 'find-suffix.c',
  kpathsea_srcdir / 'fn.c',
  kpathsea_srcdir / 'fontmap.c',
  kpathsea_srcdir / 'hash.c',
  kpathsea_srcdir / 'kdefault.c',
  kpathsea_srcdir / 'kpathsea.c',
  kpathsea_srcdir / 'line.c',
  kpathsea_srcdir / 'magstep.c',
  kpathsea_srcdir / 'make-suffix.c',
  kpathsea_srcdir / 'path-elt.c',
  kpathsea_srcdir / 'pathsearch.c',
  kpathsea_srcdir / 'proginit.c',
  kpathsea_srcdir / 'progname.c',
  kpathsea_srcdir / 'readable.c',
  kpathsea_srcdir / 'rm-suffix.c',
  kpathsea_srcdir / 'str-list.c',
  kpathsea_srcdir / 'str-llist.c',
  kpathsea_srcdir / 'tex-glyph.c',
  kpathsea_srcdir / 'tex-hush.c',
  kpathsea_srcdir / 'tex-make.c',
  kpathsea_srcdir / 'tilde.c',
  kpathsea_srcdir / 'uppercasify.c',
  kpathsea_srcdir / 'variable.c',
  kpathsea_srcdir / 'version.c',
  kpathsea_srcdir / 'xbasename.c',
  kpathsea_srcdir / 'xcalloc.c',
  kpathsea_srcdir / 'xdirname.c',
  kpathsea_srcdir / 'xfopen.c',
  kpathsea_srcdir / 'xfseek.c',
  kpathsea_srcdir / 'xftell.c',
  kpathsea_srcdir / 'xgetcwd.c',
  kpathsea_srcdir / 'xmalloc.c',
  kpathsea_srcdir / 'xopendir.c',
  kpathsea_srcdir / 'xputenv.c',
  kpathsea_srcdir / 'xrealloc.c',
  kpathsea_srcdir / 'xstat.c',
  kpathsea_srcdir / 'xstrdup.c',
]

libkpathsea_sources += [
  kpathsea_srcdir / 'getopt.c',
  kpathsea_srcdir / 'getopt1.c',
]

libkpathsea_sources += [
  kpathsea_srcdir / 'win32lib.c',
]

libkpathsea_sources += [
  kpathsea_srcdir / 'knj.c',
]

libkpathsea_sources += [
  'dirent.c'
]


if get_option('no_kpse_dll')
  kpathsea_lib = static_library('kpathsea',
    libkpathsea_sources,
    libkpathsea_gen_headers,
    c_args : libkpathsea_defines + [
      '-DNO_KPSE_DLL',
    ],
    implicit_include_directories : false,
    include_directories : libkpathsea_includes,
  )

  kpathsea_dep = declare_dependency(
    sources: libkpathsea_gen_headers,
    include_directories: libkpathsea_includes,
    compile_args : [
      '-DNO_KPSE_DLL',
    ],
    link_with: kpathsea_lib,
  )
else
  kpathsea_dll = shared_library('kpathsea',
    libkpathsea_sources,
    libkpathsea_gen_headers,
    c_args : libkpathsea_defines,
    implicit_include_directories : false,
    include_directories : libkpathsea_includes,
    soversion : kpse_version.split('/')[0],
    install : true,
  )

  kpathsea_dep = declare_dependency(
    sources: libkpathsea_gen_headers,
    include_directories: libkpathsea_includes,
    link_with: kpathsea_dll,
  )
endif
