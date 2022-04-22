/*******************************************************************************
	GLUE-Math Library -- Inverse Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Following paper:
		Small CUDA Project
			by Michael B. Giles, University of Oxford, UK
*******************************************************************************/
#ifndef GML_ERFINV_INTERNAL
#define GML_ERFINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "ur_erfinv.h"

static inline double
erfinv_core(register double q)
{
	if (q >= -1 && q <= 1)
		return ur_erfinv(q);
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERFINV_INTERNAL */
