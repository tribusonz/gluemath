/*******************************************************************************
	GLUE-Math Library: Normal Distribution CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		John Burkardt's Home Page
		 - John Burkardt
*******************************************************************************/
#ifndef GML_NORMCDF_INTERNAL
#define GML_NORMCDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "snormcdf.h"

static inline double
normcdf_core(register double z, register double mu, register double sigma)
{
	register double y;
	y = (z - mu) / sigma;
	if (!(mu != mu) && sigma > 0)  return snormcdf_core(y);
	return z != z ? z : 0;  // out of calculation range with NaN Handling
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_NORMCDF_INTERNAL */


