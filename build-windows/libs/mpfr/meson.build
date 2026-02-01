#
# meson.build for the TeX Live subdirectory libs/mpfr/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

mpfr_srcdir = '../../../libs/mpfr'
mpfr_tree = mpfr_srcdir / 'mpfr-src'


mpfr_gen_headers = []

mpfr_gen_headers += configure_file(
  input : 'mparam.h.in',
  output : 'mparam.h',
  copy : true,
)


mpfr_includes = include_directories(
  mpfr_tree / 'src',
)


mpfr_defines = []
mpfr_defines += [
  # Disable the warning because mpfr does something nasty by applying
  # the unary minus operator to unsigned integers.
  '/wd4146',
]


mpfr_sources = [
  mpfr_tree / 'src/abort_prec_max.c',
  mpfr_tree / 'src/add.c',
  mpfr_tree / 'src/add1.c',
  mpfr_tree / 'src/add1sp.c',
  mpfr_tree / 'src/add_d.c',
  mpfr_tree / 'src/add_ui.c',
  mpfr_tree / 'src/agm.c',
  mpfr_tree / 'src/atan.c',
  mpfr_tree / 'src/atan2.c',
  mpfr_tree / 'src/cache.c',
  mpfr_tree / 'src/clear.c',
  mpfr_tree / 'src/clears.c',
  mpfr_tree / 'src/cmp.c',
  mpfr_tree / 'src/cmp2.c',
  mpfr_tree / 'src/cmpabs.c',
  mpfr_tree / 'src/cmp_si.c',
  mpfr_tree / 'src/cmp_ui.c',
  mpfr_tree / 'src/comparisons.c',
  mpfr_tree / 'src/const_catalan.c',
  mpfr_tree / 'src/const_euler.c',
  mpfr_tree / 'src/const_log2.c',
  mpfr_tree / 'src/const_pi.c',
  mpfr_tree / 'src/constant.c',
  mpfr_tree / 'src/cos.c',
  mpfr_tree / 'src/div.c',
  mpfr_tree / 'src/div_2si.c',
  mpfr_tree / 'src/div_2ui.c',
  mpfr_tree / 'src/div_ui.c',
  mpfr_tree / 'src/exceptions.c',
  mpfr_tree / 'src/exp.c',
  mpfr_tree / 'src/exp2.c',
  mpfr_tree / 'src/exp3.c',
  mpfr_tree / 'src/exp_2.c',
  mpfr_tree / 'src/extract.c',
  mpfr_tree / 'src/fits_sint.c',
  mpfr_tree / 'src/fits_slong.c',
  mpfr_tree / 'src/fits_ulong.c',
  mpfr_tree / 'src/free_cache.c',
  mpfr_tree / 'src/get_d.c',
  mpfr_tree / 'src/get_si.c',
  mpfr_tree / 'src/get_str.c',
  mpfr_tree / 'src/get_z.c',
  mpfr_tree / 'src/get_z_2exp.c',
  mpfr_tree / 'src/get_ui.c',
  mpfr_tree / 'src/gmp_op.c',
  mpfr_tree / 'src/init.c',
  mpfr_tree / 'src/init2.c',
  mpfr_tree / 'src/inits2.c',
  mpfr_tree / 'src/isinteger.c',
  mpfr_tree / 'src/isnum.c',
  mpfr_tree / 'src/isqrt.c',
  mpfr_tree / 'src/log.c',
  mpfr_tree / 'src/log2.c',
  mpfr_tree / 'src/min_prec.c',
  mpfr_tree / 'src/mpfr-gmp.c',
  mpfr_tree / 'src/mpn_exp.c',
  mpfr_tree / 'src/mp_clz_tab.c',
  mpfr_tree / 'src/mul.c',
  mpfr_tree / 'src/mul_2si.c',
  mpfr_tree / 'src/mul_2ui.c',
  mpfr_tree / 'src/mul_ui.c',
  mpfr_tree / 'src/mulders.c',
  mpfr_tree / 'src/nbits_ulong.c',
  mpfr_tree / 'src/neg.c',
  mpfr_tree / 'src/next.c',
  mpfr_tree / 'src/pool.c',
  mpfr_tree / 'src/powerof2.c',
  mpfr_tree / 'src/rem1.c',
  mpfr_tree / 'src/rint.c',
  mpfr_tree / 'src/round_near_x.c',
  mpfr_tree / 'src/round_p.c',
  mpfr_tree / 'src/round_prec.c',
  mpfr_tree / 'src/scale2.c',
  mpfr_tree / 'src/set.c',
  mpfr_tree / 'src/set_d.c',
  mpfr_tree / 'src/set_dfl_prec.c',
  mpfr_tree / 'src/set_f.c',
  mpfr_tree / 'src/set_inf.c',
  mpfr_tree / 'src/set_nan.c',
  mpfr_tree / 'src/set_prec.c',
  mpfr_tree / 'src/set_q.c',
  mpfr_tree / 'src/set_rnd.c',
  mpfr_tree / 'src/set_si_2exp.c',
  mpfr_tree / 'src/set_str.c',
  mpfr_tree / 'src/set_ui_2exp.c',
  mpfr_tree / 'src/set_z.c',
  mpfr_tree / 'src/set_z_2exp.c',
  mpfr_tree / 'src/set_zero.c',
  mpfr_tree / 'src/setmax.c',
  mpfr_tree / 'src/setmin.c',
  mpfr_tree / 'src/sgn.c',
  mpfr_tree / 'src/sin.c',
  mpfr_tree / 'src/sin_cos.c',
  mpfr_tree / 'src/si_op.c',
  mpfr_tree / 'src/sqr.c',
  mpfr_tree / 'src/sqrt.c',
  mpfr_tree / 'src/sqrt_ui.c',
  mpfr_tree / 'src/strtofr.c',
  mpfr_tree / 'src/sub.c',
  mpfr_tree / 'src/sub1.c',
  mpfr_tree / 'src/sub1sp.c',
  mpfr_tree / 'src/sub_ui.c',
  mpfr_tree / 'src/swap.c',
  mpfr_tree / 'src/ubf.c',
  mpfr_tree / 'src/ui_div.c',
  mpfr_tree / 'src/ui_sub.c',
  mpfr_tree / 'src/version.c',
]


mpfr_lib = static_library('mpfr',
  mpfr_sources,
  mpfr_gen_headers,
  c_args : mpfr_defines,
  cpp_args : mpfr_defines,
  include_directories : mpfr_includes,
  dependencies : [
    gmp_dep,
  ],
)


subdir('include')

mpfr_dep = declare_dependency(
  sources : mpfr_include_headers,
  include_directories : include_directories('include'),
  link_with : mpfr_lib,
  dependencies : [
    gmp_dep,
  ],
)
