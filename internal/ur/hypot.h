/*******************************************************************************
	GLUE-Math Library: Hypotenuse

	Author:
	  Haruhiko Okumura (Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_HYPOT_DBL_INTERNAL
#define GML_HYPOT_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fabs()
#include "../../sys/float/absolute.h"

/* Moler-Morrison method */
static inline double
hypot_core(register double x, register double y)
{
	register double t;
	static const int N = 3; /* float: 2, double: 3 */
	x = fabs(x);  y = fabs(y);
	if (x < y) {  t = x;  x = y;  y = t;  }
	if (y == 0) return x;
	for (volatile int i = 0; i < N; i++)
	{
		t = y / x;  t *= t;  t /= 4 + t;
		x += 2 * x * t;  y *= t;
	}
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_HYPOT_DBL_INTERNAL */
