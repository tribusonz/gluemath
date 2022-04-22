/*******************************************************************************
	GLUE-Math Library -- Binomial Distribution Inverse CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Efficient evaluation of the inverse Binomial
		cumulative distribution function where the
		number of trials is large
			by Sean Moorhead
*******************************************************************************/
#ifndef GML_BINOMCDFCINV_INTERNAL
#define GML_BINOMCDFCINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_binomcdfinv.h"

static inline double
binomcdfcinv_core(register double q, register int nu, register double phi)
{
	if (q >= 0.0 && q <= 1.0 && phi >= 0.0 && phi <= 1.0)
		return ur_binomcdfinv(1-q, nu, phi);
	/* else */  return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_BINOMCDFCINV_INTERNAL */
