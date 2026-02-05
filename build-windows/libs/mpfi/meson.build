#
# meson.build for the TeX Live subdirectory libs/mpfi/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

mpfi_srcdir = '../../../libs/mpfi'
mpfi_tree = mpfi_srcdir / 'mpfi-src'
mpfi_src = mpfi_tree / 'src'


mpfi_version = run_command(
  find_program('get-mpfi-version.py'),
  mpfi_srcdir / 'version.ac',
  check: true).stdout().strip()


mpfi_gen_headers = []

mpfi_gen_headers += configure_file(
  input : 'mpfi_config.h.in',
  output : 'mpfi_config.h',
  configuration : {
    'VERSION' : mpfi_version,
  }
)


mpfi_includes = include_directories(
  mpfi_src,
)


mpfi_defines = []
mpfi_defines += [
  # Disable the warning because mpfr does something nasty by applying
  # the unary minus operator to unsigned integers.
  '/wd4146',
]

mpfi_sources = [
  mpfi_tree / 'src/abs.c',
  mpfi_tree / 'src/acos.c',
  mpfi_tree / 'src/acosh.c',
  mpfi_tree / 'src/add.c',
  mpfi_tree / 'src/add_d.c',
  mpfi_tree / 'src/add_fr.c',
  mpfi_tree / 'src/add_q.c',
  mpfi_tree / 'src/add_si.c',
  mpfi_tree / 'src/add_ui.c',
  mpfi_tree / 'src/add_z.c',
  mpfi_tree / 'src/alea.c',
  mpfi_tree / 'src/asin.c',
  mpfi_tree / 'src/asinh.c',
  mpfi_tree / 'src/atan.c',
  mpfi_tree / 'src/atan2.c',
  mpfi_tree / 'src/atanh.c',
  mpfi_tree / 'src/bisect.c',
  mpfi_tree / 'src/blow.c',
  mpfi_tree / 'src/cbrt.c',
  mpfi_tree / 'src/clear.c',
  mpfi_tree / 'src/clears.c',
  mpfi_tree / 'src/cmp.c',
  mpfi_tree / 'src/cmp_sym_pi.c',
  mpfi_tree / 'src/constants.c',
  mpfi_tree / 'src/cos.c',
  mpfi_tree / 'src/cosh.c',
  mpfi_tree / 'src/cot.c',
  mpfi_tree / 'src/coth.c',
  mpfi_tree / 'src/csc.c',
  mpfi_tree / 'src/csch.c',
  mpfi_tree / 'src/d_div.c',
  mpfi_tree / 'src/d_sub.c',
  mpfi_tree / 'src/diam.c',
  mpfi_tree / 'src/div.c',
  mpfi_tree / 'src/div_2exp.c',
  mpfi_tree / 'src/div_2si.c',
  mpfi_tree / 'src/div_2ui.c',
  mpfi_tree / 'src/div_d.c',
  mpfi_tree / 'src/div_ext.c',
  mpfi_tree / 'src/div_fr.c',
  mpfi_tree / 'src/div_q.c',
  mpfi_tree / 'src/div_si.c',
  mpfi_tree / 'src/div_ui.c',
  mpfi_tree / 'src/div_z.c',
  mpfi_tree / 'src/erandom.c',
  mpfi_tree / 'src/error.c',
  mpfi_tree / 'src/exp.c',
  mpfi_tree / 'src/exp10.c',
  mpfi_tree / 'src/exp10m1.c',
  mpfi_tree / 'src/exp2.c',
  mpfi_tree / 'src/exp2m1.c',
  mpfi_tree / 'src/expm1.c',
  mpfi_tree / 'src/fr_div.c',
  mpfi_tree / 'src/fr_sub.c',
  mpfi_tree / 'src/get_d.c',
  mpfi_tree / 'src/get_endpoints.c',
  mpfi_tree / 'src/get_fr.c',
  mpfi_tree / 'src/get_prec.c',
  mpfi_tree / 'src/get_version.c',
  mpfi_tree / 'src/has_zero.c',
  mpfi_tree / 'src/hypot.c',
  mpfi_tree / 'src/increase.c',
  mpfi_tree / 'src/init.c',
  mpfi_tree / 'src/init2.c',
  mpfi_tree / 'src/inits.c',
  mpfi_tree / 'src/inits2.c',
  mpfi_tree / 'src/inp_str.c',
  mpfi_tree / 'src/intersect.c',
  mpfi_tree / 'src/interv_d.c',
  mpfi_tree / 'src/interv_fr.c',
  mpfi_tree / 'src/interv_q.c',
  mpfi_tree / 'src/interv_si.c',
  mpfi_tree / 'src/interv_ui.c',
  mpfi_tree / 'src/interv_z.c',
  mpfi_tree / 'src/inv.c',
  mpfi_tree / 'src/is_empty.c',
  mpfi_tree / 'src/is_inside.c',
  mpfi_tree / 'src/log.c',
  mpfi_tree / 'src/log10.c',
  mpfi_tree / 'src/log10p1.c',
  mpfi_tree / 'src/log1p.c',
  mpfi_tree / 'src/log2.c',
  mpfi_tree / 'src/log2p1.c',
  mpfi_tree / 'src/mag.c',
  mpfi_tree / 'src/mid.c',
  mpfi_tree / 'src/mig.c',
  mpfi_tree / 'src/mpfi-impl.h',
  mpfi_tree / 'src/mpfi.h',
  mpfi_tree / 'src/mpfi_io.h',
  mpfi_tree / 'src/mul.c',
  mpfi_tree / 'src/mul_2exp.c',
  mpfi_tree / 'src/mul_2si.c',
  mpfi_tree / 'src/mul_2ui.c',
  mpfi_tree / 'src/mul_d.c',
  mpfi_tree / 'src/mul_fr.c',
  mpfi_tree / 'src/mul_q.c',
  mpfi_tree / 'src/mul_si.c',
  mpfi_tree / 'src/mul_ui.c',
  mpfi_tree / 'src/mul_z.c',
  mpfi_tree / 'src/neg.c',
  mpfi_tree / 'src/nrandom.c',
  mpfi_tree / 'src/out_str.c',
  mpfi_tree / 'src/predicates.c',
  mpfi_tree / 'src/print_binary.c',
  mpfi_tree / 'src/put.c',
  mpfi_tree / 'src/put_d.c',
  mpfi_tree / 'src/put_fr.c',
  mpfi_tree / 'src/put_q.c',
  mpfi_tree / 'src/put_si.c',
  mpfi_tree / 'src/put_ui.c',
  mpfi_tree / 'src/put_z.c',
  mpfi_tree / 'src/q_div.c',
  mpfi_tree / 'src/q_sub.c',
  mpfi_tree / 'src/quadrant.c',
  mpfi_tree / 'src/rec_sqrt.c',
  mpfi_tree / 'src/revert_if_needed.c',
  mpfi_tree / 'src/round_prec.c',
  mpfi_tree / 'src/sec.c',
  mpfi_tree / 'src/sech.c',
  mpfi_tree / 'src/set.c',
  mpfi_tree / 'src/set_d.c',
  mpfi_tree / 'src/set_flt.c',
  mpfi_tree / 'src/set_fr.c',
  mpfi_tree / 'src/set_ld.c',
  mpfi_tree / 'src/set_prec.c',
  mpfi_tree / 'src/set_q.c',
  mpfi_tree / 'src/set_si.c',
  mpfi_tree / 'src/set_str.c',
  mpfi_tree / 'src/set_ui.c',
  mpfi_tree / 'src/set_z.c',
  mpfi_tree / 'src/si_div.c',
  mpfi_tree / 'src/si_sub.c',
  mpfi_tree / 'src/sign.c',
  mpfi_tree / 'src/sin.c',
  mpfi_tree / 'src/sinh.c',
  mpfi_tree / 'src/sqr.c',
  mpfi_tree / 'src/sqrt.c',
  mpfi_tree / 'src/sub.c',
  mpfi_tree / 'src/sub_d.c',
  mpfi_tree / 'src/sub_fr.c',
  mpfi_tree / 'src/sub_q.c',
  mpfi_tree / 'src/sub_si.c',
  mpfi_tree / 'src/sub_ui.c',
  mpfi_tree / 'src/sub_z.c',
  mpfi_tree / 'src/swap.c',
  mpfi_tree / 'src/tan.c',
  mpfi_tree / 'src/tanh.c',
  mpfi_tree / 'src/ui_div.c',
  mpfi_tree / 'src/ui_sub.c',
  mpfi_tree / 'src/union.c',
  mpfi_tree / 'src/urandom.c',
  mpfi_tree / 'src/z_div.c',
  mpfi_tree / 'src/z_sub.c',
]


mpfi_lib = static_library('mpfi',
  mpfi_sources,
  mpfi_gen_headers,
  c_args : mpfi_defines,
  cpp_args : mpfi_defines,
  include_directories : mpfi_includes,
  dependencies : [
    gmp_dep,
    mpfr_dep,
  ],
)


subdir('include')

mpfi_dep = declare_dependency(
  sources : mpfi_include_headers,
  include_directories : include_directories('include'),
  link_with : mpfi_lib,
  dependencies : [
    gmp_dep,
    mpfr_dep,
  ],
)
