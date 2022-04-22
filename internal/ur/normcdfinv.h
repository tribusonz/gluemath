/*******************************************************************************
	GLUE-Math Library: Normal Distribution Inverse CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		John Burkardt's Home Page
		 - John Burkardt
*******************************************************************************/
#ifndef GML_NORMCDFINV_INTERNAL
#define GML_NORMCDFINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "snormcdfinv.h"

static inline double
normcdfinv_core(register double q, register double mu, register double sigma)
{
	double x, x2;
	
	if (sigma <= 0)  return 0.0;
	x2 = snormcdfinv_core(q);
	if (isfinite(x2))
	{
		if (isnan(mu) || isnan(sigma))
			return NAN;
		x = mu + sigma * x2;
		return x;
	}
	return x2;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_NORMCDFINV_INTERNAL */
