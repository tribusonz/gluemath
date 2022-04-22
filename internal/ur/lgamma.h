/*******************************************************************************
	GLUE-Math Library: Logarithm of Gamma Function

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_LGAMMA_DBL_INTERNAL
#define GML_LGAMMA_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fpclassify(), HUGE_VAL, NAN
#include <limits.h> /* INT_MAX */
#include <stdlib.h> /* NULL */
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "fmod.h"
#include "logfactorial.h"
#include "../../tuning/lgamma_approx.h"
#if defined(_USE_LGAMMA_APPROX) && _USE_LGAMMA_APPROX == 1
# include "lgamma_a.h"
#endif
#include "lgamma_b.h"

static inline double
ur_loggamma_r(double x, int *signp)
{
#if defined(_USE_LGAMMA_APPROX) && _USE_LGAMMA_APPROX == 1
	if (x < 0)  return loggamma_a(x, signp); // approx
#endif
	return loggamma_b(x, signp); // bernoulli
}

static inline double
lgamma_core(double x)
{
	double y;
	int signp;
	switch (fpclassify(y = fmod_core(x, 1))) {
	case FP_NAN:
	case FP_INFINITE:
		if (isinf(x))
		{
			// ComplexInfinity
	 		// loggamma(+Infinity) = (Infinity+Infinity*i)
	 		// loggamma(-Infinity) = (NaN-Infinity*i)
			return x > 0 ? HUGE_VAL : NAN;
		}
		return NAN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		// ComplexInfinity
		// x <= 0 = Re(Infinity), Im(|x|*PI)
		if (x < 0.1)  return HUGE_VAL;
		else if (x <= INT_MAX)
			return logfactorial_core((int)(x - y) - 1);
		break;
	default:
		break;
	}
	return ur_loggamma_r(x, &signp);
}



#if defined(__cplusplus)
}
#endif

#endif /* GML_LGAMMA_DBL_INTERNAL */
