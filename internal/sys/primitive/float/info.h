/*******************************************************************************
	GLUE-Math FP information

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#if !defined(GLUE_PRIMITIVE_FP_INFO)
# error include sys/float/info.h at first
#endif

#ifndef FLOAT_INFO_INTERNAL
#define FLOAT_INFO_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../../../sys/float/huge_val_nan.h"
#include "../../arch/foo.h"

/***** Entities of Environment *****/
/* for float */
struct _FltInfo
{
	unsigned char has_subnorm;
	unsigned char radix;
	unsigned char mant_dig;
	unsigned char dig;
	char eps_10_exp;
	float epsilon;
	float max;
	float min;
	float true_min;
	int min_exp;
	int min_10_exp;
	int max_exp;
	int max_10_exp;
} ;

/* for double */
struct _DblInfo
{
	unsigned char has_subnorm;
	unsigned char radix;
	unsigned char mant_dig;
	unsigned char dig;
	char eps_10_exp;
	double epsilon;
	double max;
	double min;
	double true_min;
	int min_exp;
	int min_10_exp;
	int max_exp;
	int max_10_exp;
} ;

/* for long double */
struct _LDblInfo
{
	unsigned char has_subnorm;
	unsigned char radix;
	unsigned char mant_dig;
	unsigned char dig;
	char eps_10_exp;
	long double epsilon;
	long double max;
	long double min;
	long double true_min;
	int min_exp;
	int min_10_exp;
	int max_exp;
	int max_10_exp;
} ;

/**** Environment checker of floating point based on Prof. Okumura's routine ****/
static int fp_flt_initialize_pragma = 0;

// For detail, get Prof. Okumura's handbook and see p243-246.
static inline void
get_flt_info(void)
{
	register float x, y;

	if (fp_flt_initialize_pragma)  return;

	/* FLT_RADIX */
	x = y = 2;
	while (foof(x + 1) - x == 1) x *= 2;
	while (foof(x + y) == x) y *= 2;
	flt_info.radix = foof(x + y) - x;
	/* FLT_MANT_DIG */
	flt_info.mant_dig = 1;  x = flt_info.radix;
	while (foof(x + 1) - x == 1) {  flt_info.mant_dig++;  x *= flt_info.radix;  }
	/* FLT_EPSILON */
	flt_info.epsilon = 1;
	while (foof(1 + flt_info.epsilon / 2) > 1)  flt_info.epsilon /= 2;
	flt_info.epsilon = foof(1 + flt_info.epsilon) - 1;
	/* float EPSILON EXPONENT */
	x = flt_info.radix; flt_info.eps_10_exp = 0;
	while (foof(y = x * x) != HUGE_VALF) { x = y; flt_info.eps_10_exp--; }
	/* FLT_DIG */
	x = flt_info.epsilon; flt_info.dig = 0;
	while (foof(x *= 10) < 1)  flt_info.dig++;
	/* FLT_MAX, FLT_MAX_EXP */
	x = flt_info.radix; flt_info.max_exp = flt_info.radix;
	while ((foof(y = x * flt_info.radix)) != HUGE_VALF) { x = y; flt_info.max_exp++; }
	flt_info.max = x - x * flt_info.epsilon + x;
	/* FLT_MAX_10_EXP */
	x = flt_info.max; flt_info.max_10_exp = 1;
	while (foof((x /= 10) > 10)) flt_info.max_10_exp++;
	/* Check denormalized number support */
	x = flt_info.radix / flt_info.max * flt_info.radix;
	flt_info.has_subnorm = x == 0.0 ? 0 : 1;
	/* FLT_MIN, FLT_TRUE_MIN, FLT_MIN_EXP */
	if (flt_info.has_subnorm) {
	flt_info.min = x; x = flt_info.radix; flt_info.min_exp = 1;
	while ((foof(y = x / flt_info.radix)) > flt_info.min) { x = y; flt_info.min_exp--; }
	while ((foof(y = x / flt_info.radix)) != 0) { x = y; }
	flt_info.true_min = x; }
	else {
	x = flt_info.radix; flt_info.min_exp = 1;
	while ((foof(y = x / flt_info.radix)) != 0) { x = y; flt_info.min_exp--; }
	flt_info.min = flt_info.true_min = x; }
	/* FLT_MIN_10_EXP */
	x = flt_info.min; flt_info.min_10_exp = 0;
	while (foof((x *= 10) < 1)) flt_info.min_10_exp--;
	fp_flt_initialize_pragma = 1;
}

static int fp_dbl_initialize_pragma = 0;

static inline void
get_dbl_info(void)
{
	register double x, y;

	if (fp_dbl_initialize_pragma)  return;

	/* FLT_RADIX */
	x = y = 2;
	while (foo(x + 1) - x == 1) x *= 2;
	while (foo(x + y) == x) y *= 2;
	dbl_info.radix = foo(x + y) - x;
	/* DBL_MANT_DIG */
	dbl_info.mant_dig = 1;  x = dbl_info.radix;
	while (foo(x + 1) - x == 1) {  dbl_info.mant_dig++;  x *= dbl_info.radix;  }
	/* DBL_EPSILON */
	dbl_info.epsilon = 1;
	while (foo(1 + dbl_info.epsilon / 2) > 1)  dbl_info.epsilon /= 2;
	dbl_info.epsilon = foo(1 + dbl_info.epsilon) - 1;
	/* double EPSILON EXPONENT */
	x = dbl_info.radix; dbl_info.eps_10_exp = 0;
	while (foo(y = x * x) != HUGE_VAL) { x = y; dbl_info.eps_10_exp--; }
	/* DBL_DIG */
	x = dbl_info.epsilon; dbl_info.dig = 0;
	while (foo(x *= 10) < 1)  dbl_info.dig++;
	/* DBL_MAX, DBL_MAX_EXP */
	x = dbl_info.radix; dbl_info.max_exp = dbl_info.radix;
	while ((foo(y = x * dbl_info.radix)) != HUGE_VAL) { x = y; dbl_info.max_exp++; }
	dbl_info.max = x - x * dbl_info.epsilon + x;
	/* DBL_MAX_10_EXP */
	x = dbl_info.max; dbl_info.max_10_exp = 1;
	while (foo((x /= 10) > 10)) dbl_info.max_10_exp++;
	/* Check denormalized number support */
	x = dbl_info.radix / dbl_info.max * dbl_info.radix;
	dbl_info.has_subnorm = x == 0.0 ? 0 : 1;
	/* DBL_MIN, DBL_TRUE_MIN, DBL_MIN_EXP */
	if (dbl_info.has_subnorm) {
	dbl_info.min = x; x = dbl_info.radix; dbl_info.min_exp = 1;
	while ((foo(y = x / dbl_info.radix)) > dbl_info.min) { x = y; dbl_info.min_exp--; }
	while ((foo(y = x / dbl_info.radix)) != 0) { x = y; }
	dbl_info.true_min = x; }
	else {
	x = dbl_info.radix; dbl_info.min_exp = 1;
	while ((foo(y = x / dbl_info.radix)) != 0) { x = y; dbl_info.min_exp--; }
	dbl_info.min = dbl_info.true_min = x; }
	/* DBL_MIN_10_EXP */
	x = dbl_info.min; dbl_info.min_10_exp = 0;
	while (foo((x *= 10) < 1)) dbl_info.min_10_exp--;

	fp_dbl_initialize_pragma = 1;
}

static int fp_ldbl_initialize_pragma = 0;

static inline void
get_ldbl_info(void)
{
	register long double x, y;

	if (fp_ldbl_initialize_pragma)  return;

	/* FLT_RADIX */
	x = y = 2;
	while (fool(x + 1) - x == 1) x *= 2;
	while (fool(x + y) == x) y *= 2;
	ldbl_info.radix = fool(x + y) - x;
	/* LDBL_MANT_DIG */
	ldbl_info.mant_dig = 1;  x = ldbl_info.radix;
	while (fool(x + 1) - x == 1) {  ldbl_info.mant_dig++;  x *= ldbl_info.radix;  }
	/* LDBL_EPSILON */
	ldbl_info.epsilon = 1;
	while (fool(1 + ldbl_info.epsilon / 2) > 1)  ldbl_info.epsilon /= 2;
	ldbl_info.epsilon = fool(1 + ldbl_info.epsilon) - 1;
	/* long double EPSILON EXPONENT */
	x = ldbl_info.radix; ldbl_info.eps_10_exp = 0;
	while (fool(y = x * x) != HUGE_VALL) { x = y; ldbl_info.eps_10_exp--; }
	/* LDBL_DIG */
	x = ldbl_info.epsilon; ldbl_info.dig = 0;
	while (fool(x *= 10) < 1)  ldbl_info.dig++;
	/* LDBL_MAX, LDBL_MAX_EXP */
	x = ldbl_info.radix; ldbl_info.max_exp = ldbl_info.radix;
	while ((fool(y = x * ldbl_info.radix)) != HUGE_VALL) { x = y; ldbl_info.max_exp++; }
	ldbl_info.max = x - x * ldbl_info.epsilon + x;
	/* LDBL_MAX_10_EXP */
	x = ldbl_info.max; ldbl_info.max_10_exp = 1;
	while (fool((x /= 10) > 10)) ldbl_info.max_10_exp++;
	/* Check denormalized number support */
	x = ldbl_info.radix / ldbl_info.max * ldbl_info.radix;
	ldbl_info.has_subnorm = x == 0.0 ? 0 : 1;
	/* LDBL_MIN, LDBL_TRUE_MIN, LDBL_MIN_EXP */
	if (ldbl_info.has_subnorm) {
	ldbl_info.min = x; x = ldbl_info.radix; ldbl_info.min_exp = 1;
	while ((fool(y = x / ldbl_info.radix)) > ldbl_info.min) { x = y; ldbl_info.min_exp--; }
	while ((fool(y = x / ldbl_info.radix)) != 0) { x = y; }
	ldbl_info.true_min = x; }
	else {
	x = ldbl_info.radix; ldbl_info.min_exp = 1;
	while ((fool(y = x / ldbl_info.radix)) != 0) { x = y; ldbl_info.min_exp--; }
	ldbl_info.min = ldbl_info.true_min = x; }
	/* LDBL_MIN_10_EXP */
	x = ldbl_info.min; ldbl_info.min_10_exp = 0;
	while (fool((x *= 10) < 1)) ldbl_info.min_10_exp--;

	fp_ldbl_initialize_pragma = 1;
}

#if defined(__cplusplus)
}
#endif

#endif /* FLOAT_INFO_INTERNAL */
