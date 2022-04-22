/*******************************************************************************
	GLUE-Math Library: Regularized Incomplete Gamma Function

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
	Following paper:
	  All about of p-adic special functions (Japanese) - Yasuo Morita
******************************************************************************/
#ifndef GML_GAMMAINCR_INTERNAL
#define GML_GAMMAINCR_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: p_gamma(), q_gamma(), lgamma(), fpclassify(), signbit(), NAN
#include "../../sys/float/signbit.h"
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "lgamma.h"
#include "p_gamma.h"

/* Regularized Incomplete Gamma Function the 1st kind, q(a,x) */
static inline double
gammaincr1_core(register double a, register double x)
{
	double y = 0.0;
	switch (fpclassify(a)) {
	case FP_NAN:
		return NAN;
	case FP_INFINITE:
		return a < 0 ? NAN : 0.0;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return x != x ? x : x > 0 ? 1.0 : NAN;
		break;
	default:
		if (isnan(x))  return NAN;
		else if (signbit(x)) return NAN; // solve is in complex plane
		else if (!isnan(y = p_gamma_core(a, x, lgamma_core(a))))  return y;
		return 0.0;
		break;
	}
}

/* Regularized Incomplete Gamma Function the 2nd kind, Q(a,x) */
static inline double
gammaincr2_core(register double a, register double x)
{
	double y = 0.0;
	switch (fpclassify(a)) {
	case FP_NAN:
		return NAN;
	case FP_INFINITE:
		return a < 0 ? NAN : 1.0;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return x != x ? x : x > 0 ? 0.0 : NAN;
		break;
	default:
		if (isnan(x))  return NAN;
		else if (signbit(x))  return NAN; // solve is in complex plane
		else if (!isnan(y = q_gamma_core(a, x, lgamma_core(a))))  return y;
		return 1.0;
		break;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GAMMAINCR_INTERNAL */
