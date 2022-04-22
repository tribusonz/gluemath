/*******************************************************************************
	GLUE-Math Library: Geometric Distribution CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_GEOMCDF_INTERNAL
#define GML_GEOMCDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../../sys/float/huge_val_nan.h"
#include "pow.h"
#include "floor.h"

static inline double
geomcdf_core(register double x, register double p)
{
	if (p >= 0 && p <= 1)
	{
		if (isnan(x))
			;
		else if (x >= 0)
		{
			if (isinf(x))  return 1.0;
			return 1 - pow_core(1 - p, floor_core(x) + 1);
		}
		else
			return 0.0;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_GEOMCDF_INTERNAL */
