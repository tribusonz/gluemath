/*******************************************************************************
	GLUE-Math Library: R.N.G. -- Standard Normal Distribution
	
	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_RNG_SNORM_INTERNAL
#define GML_RNG_SNORM_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: log(), sqrt(), sin(), cos()
#include "log.h"
#include "sqrt.h"
#include "uniform.h"

// Ex. Box-Muller Method
static inline double
snormrng_core(void)
{
	static int sw = 0;
	static double r1, r2, s;

	if (sw == 0) {
		sw = 1;
		do {
			r1 = 2 * uniform_core() - 1;
			r2 = 2 * uniform_core() - 1;
			s = r1 * r1 + r2 * r2;
		} while (s >= 1 || s == 0);
		s = sqrt_core(-2 * log_core(s) / s);
		return r1 * s;
	} else {
		sw = 0;
		return r2 * s;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_RNG_SNORM_INTERNAL */
