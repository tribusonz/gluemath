/*******************************************************************************
	GLUE-Math Library -- Chi-Square Distribution CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_CHISQCDF_INTERNAL
#define GML_CHISQCDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: lgamma()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "lgamma.h"
#include "p_gamma.h"

/* Lower CDF */
static inline double
ur_p_chisq(double chisq, int df)
{
	return p_gamma_core(0.5 * df, 0.5 * chisq, lgamma_core(0.5 * df));
}

/* Upper CDF */
static inline double
ur_q_chisq(double chisq, int df)
{
	return q_gamma_core(0.5 * df, 0.5 * chisq, lgamma_core(0.5 * df));
}

static inline double
chisqcdf_core(register double z, register int nu)
{
	switch (fpclassify(z)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return z > 0 ? 1 : 0;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0;
		break;
	default:
		if (z < 0)  return 0;
		else if (nu <= 0)  return NAN;
		return ur_p_chisq(z, nu);
		break;
	}
}

static inline double
chisqcdfc_core(register double z, register int nu)
{
	switch (fpclassify(z)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return z > 0 ? 0 : 1;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 1;
		break;
	default:
		if (z < 0)  return 1;
		else if (nu <= 0)  return NAN;
		return ur_q_chisq(z, nu);
		break;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CHISQCDF_INTERNAL */
