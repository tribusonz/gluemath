/*******************************************************************************
	GLUE-Math Library -- Inverse Complementary Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Following paper:
		Small CUDA Project
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#ifndef GML_ERFCINV_INTERNAL
#define GML_ERFCINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "ur_erfinv.h"

static inline double
erfcinv_core(register double q)
{
	if (q >= 0 && q <= 2)
		return ur_erfinv(1-q);
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERFCINV_INTERNAL */
