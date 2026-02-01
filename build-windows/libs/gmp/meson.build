#
# meson.build for the TeX Live subdirectory libs/gmp/
#
# Copyright 2026      Yukimasa Morimi <h20y6m@yahoo.co.jp>
# You may freely use, modify and/or distribute this file.

gmp_srcdir = '../../../libs/gmp'
gmp_tree = gmp_srcdir / 'gmp-src'

subdir('native')

gmp_version = run_command(
  find_program('get-gmp-version.py'),
  gmp_srcdir / 'version.ac',
  check: true).stdout().strip()


gmp_gen_headers = []

conf_data = configuration_data()
conf_data.set('VERSION', gmp_version)
if target_machine.cpu_family() == 'x86'
  conf_data.set('HAVE_HOST_CPU_FAMILY_x86', 1)
endif
if target_machine.cpu_family() == 'x86_64'
  conf_data.set('HAVE_HOST_CPU_FAMILY_x86_64', 1)
endif

gmp_gen_headers += configure_file(
  input : 'config.h.in',
  output : 'config.h',
  configuration : conf_data,
)


conf_data = configuration_data()
sizeof_void_p = cc.sizeof('void*')
sizeof_unsigned_long = cc.sizeof('unsigned long')
sizeof_unsigned_long_long = cc.sizeof('unsigned long long')
if sizeof_void_p > sizeof_unsigned_long and sizeof_void_p <= sizeof_unsigned_long_long
  gmp_limb_bits = 8 * sizeof_unsigned_long_long
  conf_data.set('DEFN_LONG_LONG_LIMB', '#define _LONG_LONG_LIMB 1')
else
  gmp_limb_bits = 8 * sizeof_unsigned_long
  conf_data.set('DEFN_LONG_LONG_LIMB', '')
endif
gmp_nail_bits = 0
conf_data.set('GMP_LIMB_BITS', gmp_limb_bits)
conf_data.set('GMP_NAIL_BITS', gmp_nail_bits)
conf_data.set('LIBGMP_DLL', 0)

conf_data.set('CC', ' '.join(cc.cmd_array()))
conf_data.set('CFLAGS', '')

gmp_h = configure_file(
  input : 'gmp.h.in',
  output : 'gmp.h',
  configuration : conf_data,
)

gmp_gen_headers += gmp_h



gmp_includes = include_directories(
  gmp_tree,
  gmp_tree / 'mpn/generic',
)


gmp_defines = []
gmp_defines += [
  '-DNO_ASM',
  # Disable the warning because gmp does something nasty by applying
  # the unary minus operator to unsigned integers.
  '/wd4146',
]

gmp_mp_bases_h = custom_target('mp_bases.h',
  output : 'mp_bases.h',
  capture : true,
  command : [
    gmp_native_gen_bases_exe,
    'header',
    gmp_limb_bits.to_string(),
    gmp_nail_bits.to_string(),
  ],
)
gmp_gen_headers += gmp_mp_bases_h
gmp_mp_bases_c = custom_target('mp_bases.c',
  output : 'mp_bases.c',
  capture : true,
  command : [
    gmp_native_gen_bases_exe,
    'table',
    gmp_limb_bits.to_string(),
    gmp_nail_bits.to_string(),
  ],
)

gmp_fac_table_h = custom_target('fac_table.h',
  output : 'fac_table.h',
  capture : true,
  command : [
    gmp_native_gen_fac_exe,
    gmp_limb_bits.to_string(),
    gmp_nail_bits.to_string(),
  ],
)
gmp_gen_headers += gmp_fac_table_h

gmp_fib_table_h = custom_target('fib_table.h',
  output : 'fib_table.h',
  capture : true,
  command : [
    gmp_native_gen_fib_exe,
    'header',
    gmp_limb_bits.to_string(),
    gmp_nail_bits.to_string(),
  ],
)
gmp_gen_headers += gmp_fib_table_h

gmp_basic_sources = [
  gmp_tree / 'assert.c',
  gmp_tree / 'compat.c',
  gmp_tree / 'errno.c',
  gmp_tree / 'extract-dbl.c',
  gmp_tree / 'invalid.c',
  gmp_tree / 'memory.c',
  gmp_tree / 'mp_bpl.c',
  gmp_tree / 'mp_clz_tab.c',
  gmp_tree / 'mp_dv_tab.c',
  gmp_tree / 'mp_get_fns.c',
  gmp_tree / 'mp_minv_tab.c',
  gmp_tree / 'mp_set_fns.c',
  gmp_tree / 'nextprime.c',
  gmp_tree / 'primesieve.c',
  gmp_tree / 'tal-reent.c',
  gmp_tree / 'version.c',
]

gmp_mpn_sources = [
  gmp_mp_bases_c,
  'popcount.c',
  gmp_tree / 'mpn/generic/add.c',
  gmp_tree / 'mpn/generic/add_1.c',
  gmp_tree / 'mpn/generic/add_n.c',
  gmp_tree / 'mpn/generic/addmul_1.c',
  gmp_tree / 'mpn/generic/bdiv_dbm1c.c',
  gmp_tree / 'mpn/generic/bdiv_q.c',
  gmp_tree / 'mpn/generic/bdiv_q_1.c',
  gmp_tree / 'mpn/generic/binvert.c',
  gmp_tree / 'mpn/generic/cmp.c',
  gmp_tree / 'mpn/generic/com.c',
  gmp_tree / 'mpn/generic/compute_powtab.c',
  gmp_tree / 'mpn/generic/copyd.c',
  gmp_tree / 'mpn/generic/copyi.c',
  gmp_tree / 'mpn/generic/dcpi1_bdiv_q.c',
  gmp_tree / 'mpn/generic/dcpi1_bdiv_qr.c',
  gmp_tree / 'mpn/generic/dcpi1_div_q.c',
  gmp_tree / 'mpn/generic/dcpi1_div_qr.c',
  gmp_tree / 'mpn/generic/dcpi1_divappr_q.c',
  gmp_tree / 'mpn/generic/div_q.c',
  gmp_tree / 'mpn/generic/div_qr_2n_pi1.c',
  gmp_tree / 'mpn/generic/dive_1.c',
  gmp_tree / 'mpn/generic/divexact.c',
  gmp_tree / 'mpn/generic/divrem.c',
  gmp_tree / 'mpn/generic/divrem_1.c',
  gmp_tree / 'mpn/generic/divrem_2.c',
  gmp_tree / 'mpn/generic/gcd_subdiv_step.c',
  gmp_tree / 'mpn/generic/gcdext.c',
  gmp_tree / 'mpn/generic/gcdext_1.c',
  gmp_tree / 'mpn/generic/gcdext_lehmer.c',
  gmp_tree / 'mpn/generic/get_str.c',
  gmp_tree / 'mpn/generic/hgcd.c',
  gmp_tree / 'mpn/generic/hgcd2.c',
  gmp_tree / 'mpn/generic/hgcd_appr.c',
  gmp_tree / 'mpn/generic/hgcd_matrix.c',
  gmp_tree / 'mpn/generic/hgcd_reduce.c',
  gmp_tree / 'mpn/generic/hgcd_step.c',
  gmp_tree / 'mpn/generic/invertappr.c',
  gmp_tree / 'mpn/generic/lshift.c',
  gmp_tree / 'mpn/generic/lshiftc.c',
  gmp_tree / 'mpn/generic/matrix22_mul.c',
  gmp_tree / 'mpn/generic/matrix22_mul1_inverse_vector.c',
  gmp_tree / 'mpn/generic/mod_1.c',
  gmp_tree / 'mpn/generic/mu_bdiv_q.c',
  gmp_tree / 'mpn/generic/mu_div_q.c',
  gmp_tree / 'mpn/generic/mu_div_qr.c',
  gmp_tree / 'mpn/generic/mu_divappr_q.c',
  gmp_tree / 'mpn/generic/mul.c',
  gmp_tree / 'mpn/generic/mul_1.c',
  gmp_tree / 'mpn/generic/mul_basecase.c',
  gmp_tree / 'mpn/generic/mul_fft.c',
  gmp_tree / 'mpn/generic/mul_n.c',
  gmp_tree / 'mpn/generic/mullo_basecase.c',
  gmp_tree / 'mpn/generic/mullo_n.c',
  gmp_tree / 'mpn/generic/mulmod_bnm1.c',
  gmp_tree / 'mpn/generic/neg.c',
  gmp_tree / 'mpn/generic/nussbaumer_mul.c',
  gmp_tree / 'mpn/generic/powlo.c',
  gmp_tree / 'mpn/generic/powm.c',
  gmp_tree / 'mpn/generic/pre_divrem_1.c',
  gmp_tree / 'mpn/generic/redc_1.c',
  gmp_tree / 'mpn/generic/redc_n.c',
  gmp_tree / 'mpn/generic/rshift.c',
  gmp_tree / 'mpn/generic/sbpi1_bdiv_q.c',
  gmp_tree / 'mpn/generic/sbpi1_bdiv_qr.c',
  gmp_tree / 'mpn/generic/sbpi1_div_q.c',
  gmp_tree / 'mpn/generic/sbpi1_div_qr.c',
  gmp_tree / 'mpn/generic/sbpi1_divappr_q.c',
  gmp_tree / 'mpn/generic/scan1.c',
  gmp_tree / 'mpn/generic/set_str.c',
  gmp_tree / 'mpn/generic/sqr.c',
  gmp_tree / 'mpn/generic/sqr_basecase.c',
  gmp_tree / 'mpn/generic/sqrlo.c',
  gmp_tree / 'mpn/generic/sqrlo_basecase.c',
  gmp_tree / 'mpn/generic/sqrmod_bnm1.c',
  gmp_tree / 'mpn/generic/sqrtrem.c',
  gmp_tree / 'mpn/generic/sub.c',
  gmp_tree / 'mpn/generic/sub_1.c',
  gmp_tree / 'mpn/generic/sub_n.c',
  gmp_tree / 'mpn/generic/submul_1.c',
  gmp_tree / 'mpn/generic/tdiv_qr.c',
  gmp_tree / 'mpn/generic/toom22_mul.c',
  gmp_tree / 'mpn/generic/toom2_sqr.c',
  gmp_tree / 'mpn/generic/toom32_mul.c',
  gmp_tree / 'mpn/generic/toom33_mul.c',
  gmp_tree / 'mpn/generic/toom3_sqr.c',
  gmp_tree / 'mpn/generic/toom42_mul.c',
  gmp_tree / 'mpn/generic/toom42_mulmid.c',
  gmp_tree / 'mpn/generic/toom43_mul.c',
  gmp_tree / 'mpn/generic/toom44_mul.c',
  gmp_tree / 'mpn/generic/toom4_sqr.c',
  gmp_tree / 'mpn/generic/toom53_mul.c',
  gmp_tree / 'mpn/generic/toom63_mul.c',
  gmp_tree / 'mpn/generic/toom6_sqr.c',
  gmp_tree / 'mpn/generic/toom6h_mul.c',
  gmp_tree / 'mpn/generic/toom8_sqr.c',
  gmp_tree / 'mpn/generic/toom8h_mul.c',
  gmp_tree / 'mpn/generic/toom_couple_handling.c',
  gmp_tree / 'mpn/generic/toom_eval_dgr3_pm1.c',
  gmp_tree / 'mpn/generic/toom_eval_dgr3_pm2.c',
  gmp_tree / 'mpn/generic/toom_eval_pm1.c',
  gmp_tree / 'mpn/generic/toom_eval_pm2.c',
  gmp_tree / 'mpn/generic/toom_eval_pm2exp.c',
  gmp_tree / 'mpn/generic/toom_eval_pm2rexp.c',
  gmp_tree / 'mpn/generic/toom_interpolate_12pts.c',
  gmp_tree / 'mpn/generic/toom_interpolate_16pts.c',
  gmp_tree / 'mpn/generic/toom_interpolate_5pts.c',
  gmp_tree / 'mpn/generic/toom_interpolate_6pts.c',
  gmp_tree / 'mpn/generic/toom_interpolate_7pts.c',
  gmp_tree / 'mpn/generic/toom_interpolate_8pts.c',
  gmp_tree / 'mpn/generic/zero_p.c',
]

gmp_mpz_sources = [
  gmp_tree / 'mpz/abs.c',
  gmp_tree / 'mpz/add.c',
  gmp_tree / 'mpz/add_ui.c',
  gmp_tree / 'mpz/aorsmul.c',
  gmp_tree / 'mpz/aorsmul_i.c',
  gmp_tree / 'mpz/cdiv_qr_ui.c',
  gmp_tree / 'mpz/cdiv_q_ui.c',
  gmp_tree / 'mpz/cfdiv_q_2exp.c',
  gmp_tree / 'mpz/clear.c',
  gmp_tree / 'mpz/cmp.c',
  gmp_tree / 'mpz/cmp_ui.c',
  gmp_tree / 'mpz/cmpabs.c',
  gmp_tree / 'mpz/divexact.c',
  gmp_tree / 'mpz/fdiv_q.c',
  gmp_tree / 'mpz/fdiv_q_ui.c',
  gmp_tree / 'mpz/fdiv_r_ui.c',
  gmp_tree / 'mpz/fdiv_qr.c',
  gmp_tree / 'mpz/fits_slong.c',
  gmp_tree / 'mpz/gcdext.c',
  gmp_tree / 'mpz/get_si.c',
  gmp_tree / 'mpz/get_ui.c',
  gmp_tree / 'mpz/init.c',
  gmp_tree / 'mpz/init2.c',
  gmp_tree / 'mpz/invert.c',
  gmp_tree / 'mpz/iset.c',
  gmp_tree / 'mpz/iset_ui.c',
  gmp_tree / 'mpz/mod.c',
  gmp_tree / 'mpz/mul.c',
  gmp_tree / 'mpz/mul_2exp.c',
  gmp_tree / 'mpz/mul_si.c',
  gmp_tree / 'mpz/mul_ui.c',
  gmp_tree / 'mpz/n_pow_ui.c',
  gmp_tree / 'mpz/neg.c',
  gmp_tree / 'mpz/pow_ui.c',
  gmp_tree / 'mpz/powm.c',
  gmp_tree / 'mpz/powm_ui.c',
  gmp_tree / 'mpz/realloc.c',
  gmp_tree / 'mpz/realloc2.c',
  gmp_tree / 'mpz/scan0.c',
  gmp_tree / 'mpz/scan1.c',
  gmp_tree / 'mpz/set.c',
  gmp_tree / 'mpz/set_si.c',
  gmp_tree / 'mpz/size.c',
  gmp_tree / 'mpz/set_ui.c',
  gmp_tree / 'mpz/sizeinbase.c',
  gmp_tree / 'mpz/sqrt.c',
  gmp_tree / 'mpz/sub.c',
  gmp_tree / 'mpz/sub_ui.c',
  gmp_tree / 'mpz/swap.c',
  gmp_tree / 'mpz/tdiv_q.c',
  gmp_tree / 'mpz/tdiv_q_2exp.c',
  gmp_tree / 'mpz/tdiv_qr.c',
  gmp_tree / 'mpz/tdiv_r.c',
  gmp_tree / 'mpz/tdiv_r_2exp.c',
  gmp_tree / 'mpz/tstbit.c',
  gmp_tree / 'mpz/ui_pow_ui.c',
]

gmp_sources = gmp_basic_sources + gmp_mpn_sources + gmp_mpz_sources

gmp_lib = static_library('gmp',
  gmp_sources,
  gmp_gen_headers,
  c_args : gmp_defines,
  include_directories : gmp_includes,
)


subdir('include')

gmp_dep = declare_dependency(
  sources : gmp_include_headers,
  include_directories : include_directories('include'),
  link_with : gmp_lib,
)
