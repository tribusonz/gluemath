/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsine (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_ASINH_LDBL_INTERNAL
#define GML_ASINH_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: logl(), sqrtl()
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "logl.h"
#include "sqrtl.h"
#include "m_log2.h"

static inline long double
asinhl_core(register long double x)
{
	static long double log2 = 0.L;
	register int sgn = 0;
	register long double x2 = 0.L, y = 0.L;

	if (log2 == 0.L)  log2 = m_log2_ld();

	if (isnan(x) || isinf(x))  return x;
	else if (x < 0)  { sgn = 1; x = -x; }
	if (x >= 1)
	{
		if (isinf(x2 = x * x) || (y = sqrtl_core(x2+1)) == x)
			y = x;
		if (x == y)
			y = log2 + logl_core(x);
		else
			y = logl_core(x + y);
	}
	else /* 0 <= x < 1 */
	{
		if ((x2 = x * x) == 0.L)
			y = 1.L;
		else
			y = sqrtl_core(x2+1);
		y = logl_core(x + y);
	}
	return sgn ? -y : y;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ASINH_LDBL_INTERNAL */
