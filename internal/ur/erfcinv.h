/*******************************************************************************
	GLUE-Math Library -- Inverse Complementary Error Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ERFCINV_INTERNAL
#define GML_ERFCINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#if 1
# include "ur_erfinv.h"
#else
# include "ur_erfcinv.h"
#endif

static inline double
erfcinv_core(register double q)
{
	if (q >= 0 && q <= 2)
#if 1
		return ur_erfinv(1-q);
#else
		return ur_erfcinv(q);
#endif
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ERFCINV_INTERNAL */
