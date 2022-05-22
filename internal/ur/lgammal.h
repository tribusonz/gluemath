/*******************************************************************************
	GLUE-Math Library: Logarithm of Gamma Function (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_LGAMMA_LDBL_INTERNAL
#define GML_LGAMMA_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fpclassify(), HUGE_VAL, NAN
#include <limits.h> /* INT_MAX */
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "fmodl.h"
#include "logfactoriall.h"
#include "../../tuning/lgamma_approx.h"
#if defined(_USE_LGAMMA_APPROX) && _USE_LGAMMA_APPROX == 1
# include "lgammal_a.h"
#endif
#include "lgammal_b.h"

static inline long double
ur_loggammal_r(long double x, int *signp)
{
#if defined(_USE_LGAMMA_APPROX) && _USE_LGAMMA_APPROX == 1
	if (x < 0.L)  return loggammal_a(x, signp); // approx
#endif
	return loggammal_b(x, signp); // bernoulli
}

static inline long double
lgammal_core(long double x)
{
	long double y;
	int signp;
	switch (fpclassify(y = fmodl_core(x, 1))) {
	case FP_NAN:
	case FP_INFINITE:
		if (isinf(x))
		{
			// ComplexInfinity
			// loggamma(+Infinity) = (Infinity+Infinity*i)
			// loggamma(-Infinity) = (NaN-Infinity*i)
			return x > 0 ? HUGE_VALL : NAN;
		}
		return NAN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		// ComplexInfinity
		// x <= 0 = Re(Infinity), Im(|x|*PI)
		if (x < 0.1)  return HUGE_VALL;
		else if (x <= INT_MAX)
			return logfactoriall_core((int)(x - y) - 1);
		break;
	default:
		break;
	}
	return ur_loggammal_r(x, &signp);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LGAMMA_LDBL_INTERNAL */
