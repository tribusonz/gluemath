/*******************************************************************************
	GLUE-Math Tuning: Constant-Expression of Exponent

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_CONSTEXPR_EXP
#define GML_CONSTEXPR_EXP

#if defined(__cplusplus)
extern "C" {
#endif

#include "../sys/float/info.h"
#include "../internal/sys/primitive/float/info.h"

/* Constant Expressions for exponent. Use in compiler */

// for e
// double
static inline void get_exp_const(void);
static int exp_min = -706;
static int exp_max =  709;
static int exp_const_init_pragma = 0;
// long double
static inline void get_expl_const(void);
static int expl_min = -11355;
static int expl_max =  11356;
static int expl_const_init_pragma = 0;
// float
static inline void get_expf_const(void);
static int expf_min = -85;
static int expf_max =  87;
static int expf_const_init_pragma = 0;

// for e_2
// double
static inline void get_exp2_const(void);
static int exp2_min = -1019;
static int exp2_max =  1023;
static int exp2_const_init_pragma = 0;
// long double
static inline void get_exp2l_const(void);
static int exp2l_min = -16382;
static int exp2l_max =  16384;
static int exp2l_const_init_pragma = 0;
// float
static inline void get_exp2f_const(void);
static int exp2f_min = -122;
static int exp2f_max =  126;
static int exp2f_const_init_pragma = 0;

// for e_10
// double
static inline void get_exp10_const(void);
static int exp10_min = -307;
static int exp10_max =  308;
static int exp10_const_init_pragma = 0;
// long double
static inline void get_exp10l_const(void);
static int exp10l_min = -4931;
static int exp10l_max =  4932;
static int exp10l_const_init_pragma = 0;
// float
static inline void get_exp10f_const(void);
static int exp10f_min = -37;
static int exp10f_max =  38;
static int exp10f_const_init_pragma = 0;

// Entity
static inline void
get_exp_const(void)
{
	static const double log10e = 0.4342944819032518;
	if (exp_const_init_pragma)  return;
	get_dbl_info();
	exp_min = (int)(dbl_info.min_10_exp / log10e);
	exp_max = (int)(dbl_info.max_10_exp / log10e);
	exp_const_init_pragma = 1;
}

static inline void
get_expl_const(void)
{
	static const double log10e = 0.4342944819032518;
	if (expl_const_init_pragma)  return;
	get_ldbl_info();
	expl_min = (int)(ldbl_info.min_10_exp / log10e);
	expl_max = (int)(ldbl_info.max_10_exp / log10e);
	expl_const_init_pragma = 1;
}

static inline void
get_expf_const(void)
{
	static const double log10e = 0.4342944819032518;
	if (expf_const_init_pragma)  return;
	get_flt_info();
	expf_min = (int)(flt_info.min_10_exp / log10e);
	expf_max = (int)(flt_info.max_10_exp / log10e);
	expf_const_init_pragma = 1;
}

static inline void
get_exp2_const(void)
{
	static const double log10_2 = 0.30102999566398;
	if (exp2_const_init_pragma)  return;
	get_dbl_info();
	exp2_min = (int)(dbl_info.min_10_exp / log10_2);
	exp2_max = (int)(dbl_info.max_10_exp / log10_2);
	exp2_const_init_pragma = 1;
}

static inline void
get_exp2l_const(void)
{
	static const double log10_2 = 0.30102999566398;
	if (exp2l_const_init_pragma)  return;
	get_ldbl_info();
	exp2l_min = (int)(ldbl_info.min_10_exp / log10_2);
	exp2l_max = (int)(ldbl_info.max_10_exp / log10_2);
	exp2l_const_init_pragma = 1;
}

static inline void
get_exp2f_const(void)
{
	static const double log10_2 = 0.30102999566398;
	if (exp2f_const_init_pragma)  return;
	get_flt_info();
	exp2f_min = (int)(flt_info.min_10_exp / log10_2);
	exp2f_max = (int)(flt_info.max_10_exp / log10_2);
	exp2f_const_init_pragma = 1;
}

static inline void
get_exp10_const(void)
{
	if (exp10_const_init_pragma)  return;
	get_dbl_info();
	exp10_min = dbl_info.min_10_exp;
	exp10_max = dbl_info.max_10_exp;
	exp10_const_init_pragma = 1;
}

static inline void
get_exp10l_const(void)
{
	if (exp10l_const_init_pragma)  return;
	get_ldbl_info();
	exp10l_min = ldbl_info.min_10_exp;
	exp10l_max = ldbl_info.max_10_exp;
	exp10l_const_init_pragma = 1;
}

static inline void
get_exp10f_const(void)
{
	if (exp10f_const_init_pragma)  return;
	get_flt_info();
	exp10f_min = flt_info.min_10_exp;
	exp10f_max = flt_info.max_10_exp;
	exp10f_const_init_pragma = 1;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CONSTEXPR_EXP */
