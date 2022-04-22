/*******************************************************************************
	Floating Point Arithmetic -- Macro of fpclassify()

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#if !defined(GLUE_PRIMITIVE_FP_CLASSIFY)
# error include sys/float/fpclassify.h at first
#endif

#ifndef GLUEMATH_FPCLASSIFY_INTERNAL
#define GLUEMATH_FPCLASSIFY_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../../../sys/float/info.h"
#include "info.h"

#define MACRO_ISNAN(x)  (x != x)
#define MACRO_FABS(x)  (x * -1 > 0 ? -x : x)

static inline int
gml_flt_fpclassify(register float x)
{
	get_flt_info();
	if (MACRO_ISNAN(x))
		return FP_NAN;
	else if (!MACRO_ISNAN(x) && MACRO_ISNAN(x - x))
		return FP_INFINITE;
	else if (-x + -x == 0)
		return FP_ZERO;
	else if (flt_info.has_subnorm && MACRO_FABS(x) < flt_info.min)
		return FP_SUBNORMAL;
	else
		return FP_NORMAL;
}

static inline int
gml_dbl_fpclassify(register double x)
{
	get_dbl_info();
	if (MACRO_ISNAN(x))
		return FP_NAN;
	else if (!MACRO_ISNAN(x) && MACRO_ISNAN(x - x))
		return FP_INFINITE;
	else if (-x + -x == 0)
		return FP_ZERO;
	else if (dbl_info.has_subnorm && MACRO_FABS(x) < dbl_info.min)
		return FP_SUBNORMAL;
	else
		return FP_NORMAL;
}

static inline int
gml_ldbl_fpclassify(register long double x)
{
	get_ldbl_info();
	if (MACRO_ISNAN(x))
		return FP_NAN;
	else if (!MACRO_ISNAN(x) && MACRO_ISNAN(x - x))
		return FP_INFINITE;
	else if (-x + -x == 0)
		return FP_ZERO;
	else if (ldbl_info.has_subnorm && MACRO_FABS(x) < ldbl_info.min)
		return FP_SUBNORMAL;
	else
		return FP_NORMAL;
}

#undef MACRO_ISNAN
#undef MACRO_FABS
#define MACRO_SIGNBIT(x)  (x * -1 > 0)

static inline int
gml_flt_isfinite(register float x)
{
	register int fpclass = gml_flt_fpclassify(x);
	return fpclass != FP_NAN && fpclass != FP_INFINITE ? MACRO_SIGNBIT(x) ? -1 : 1 : 0;
}

static inline int
gml_dbl_isfinite(register double x)
{
	register int fpclass = gml_dbl_fpclassify(x);
	return fpclass != FP_NAN && fpclass != FP_INFINITE ? MACRO_SIGNBIT(x) ? -1 : 1 : 0;
}

static inline int
gml_ldbl_isfinite(register long double x)
{
	register int fpclass = gml_ldbl_fpclassify(x);
	return fpclass != FP_NAN && fpclass != FP_INFINITE ? MACRO_SIGNBIT(x) ? -1 : 1 : 0;
}

static inline int
gml_flt_isnormal(register float x)
	{ return gml_flt_fpclassify(x) == FP_NORMAL ? MACRO_SIGNBIT(x) ? -1 : 1 : 0; }

static inline int
gml_dbl_isnormal(register double x)
	{ return gml_dbl_fpclassify(x) == FP_NORMAL ? MACRO_SIGNBIT(x) ? -1 : 1 : 0; }

static inline int
gml_ldbl_isnormal(register long double x)
	{ return gml_ldbl_fpclassify(x) == FP_NORMAL ? MACRO_SIGNBIT(x) ? -1 : 1 : 0; }

static inline int
gml_flt_isnan(register float x)
	{ return gml_flt_fpclassify(x) == FP_NAN; }

static inline int
gml_dbl_isnan(register double x)
	{ return gml_dbl_fpclassify(x) == FP_NAN; }

static inline int
gml_ldbl_isnan(register long double x)
	{ return gml_ldbl_fpclassify(x) == FP_NAN; }

static inline int
gml_flt_isinf(register float x)
	{ return gml_flt_fpclassify(x) == FP_INFINITE ? MACRO_SIGNBIT(x) ? -1 : 1 : 0; }

static inline int
gml_dbl_isinf(register double x)
	{ return gml_dbl_fpclassify(x) == FP_INFINITE ? MACRO_SIGNBIT(x) ? -1 : 1 : 0; }

static inline int
gml_ldbl_isinf(register long double x)
	{ return gml_ldbl_fpclassify(x) == FP_INFINITE ? MACRO_SIGNBIT(x) ? -1 : 1 : 0; }

#undef MACRO_SIGNBIT

#if defined(__cplusplus)
}
#endif

#endif /* GLUEMATH_FPCLASSIFY_INTERNAL */
