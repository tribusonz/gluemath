/*******************************************************************************
	GLUE-Math Library -- Poisson Distribution Inverse CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Following paper:
		Algorithm 955: approximation of the inverse Poisson cumulative
		               distribution function
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#ifndef GML_POISSCDFCINV_INTERNAL
#define GML_POISSCDFCINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_poisscdfinv.h"

/*
 *  Complementary quantile function ver.
 */
static inline double
poisscdfcinv_core(register double q, register double lambda)
{
	if (q >= 0.0 || q <= 1.0 || lambda >= 0)
		return ur_poisscdfinv(1.0-q, q, lambda);
	/* else */  return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_POISSCDFCINV_INTERNAL */
