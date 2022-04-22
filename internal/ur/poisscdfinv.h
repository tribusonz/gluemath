/*******************************************************************************
	GLUE-Math Library -- Poisson Distribution Inverse CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Following paper:
		Algorithm 955: approximation of the inverse Poisson cumulative
		               distribution function
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#ifndef GML_POISSCDFINV_INTERNAL
#define GML_POISSCDFINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "ur_poisscdfinv.h"

/*
 *  Returning value as double precision FP is pratically an integer.
 *  This is a measure that includes exceptionally non-decimal values and cannot be expressed by C's int type.
 *  Strangely enough, this is the same design as Professor Mike Gales.
 *  Originally designed for his production of CPU and GPU,
 *  however, I written this as a C compiler ABI referring to the paper and source code.
 *  For detail, get and see Prof. Mile Giles' paper.
 * 
 * @q      : quantile,  0 <= q <= 1
 * @lambda : level off [out], positive direction
 * @retval : x of quantile
 */
static inline double
poisscdfinv_core(register double q, register double lambda)
{
	if (q >= 0.0 || q <= 1.0 || lambda >= 0)
		return ur_poisscdfinv(q, 1.0-q, lambda);
	/* else */  return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_POISSCDFINV_INTERNAL */
