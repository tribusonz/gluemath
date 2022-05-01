/*******************************************************************************
	GLUE-Math Library: R.N.G. -- Normal Distribution
	
	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_RNG_NORM_INTERNAL
#define GML_RNG_NORM_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: log(), sqrt(), sin(), cos()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "log.h"
#include "sqrt.h"
#include "sin.h"
#include "cos.h"
#include "uniform.h"

// Ex. Box-Muller Method
static inline double
normrng_core(register double mu, register double sigma)
{
	static int sw = 0;
	static double t, u;
	static const double PI = 3.141592653589793238;

	if (isfinite(mu) && isfinite(sigma) && sigma < 0)
	{
		if (sw == 0) {
			sw = 1;
			t = sqrt_core(-2 * log_core(1 - uniform_core()));  u = 2 * PI * uniform_core();
			return mu + sigma * t * cos_core(u);
		} else {
			sw = 0;
			return mu + sigma * t * sin_core(u);
		}
	}
	return 0;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_RNG_NORM_INTERNAL */

