/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsine (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ASINH_FLT_INTERNAL
#define GML_ASINH_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: logf(), sqrtf()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "logf.h"
#include "sqrtf.h"

static inline float
asinhf_core(register float x)
{
	static const float LOG2 = 0.693147180559945309417;
	register int sgn = 0;
	register float x2 = 0.0, y = 0.0;
	if (isnan(x) || isinf(x))  return x;
	else if (x < 0)  { sgn = 1; x = -x; }
	if (x >= 1)
	{
		if (isinf(x2 = x * x) || (y = sqrtf_core(x2+1)) == x)
			y = x;
		if (x == y)
			y = LOG2 + logf_core(x);
		else
			y = logf_core(x + y);
	}
	else /* 0 <= x < 1 */
	{
		if ((x2 = x * x) == 0.0)
			y = 1.0;
		else
			y = sqrtf_core(x2+1);
		y = logf_core(x + y);
	}
	return sgn ? -y : y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ASINH_FLT_INTERNAL */
