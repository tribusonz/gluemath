/*******************************************************************************
	GLUE-Math Library: R.N.G. -- Geometric Distribution

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_RNG_GEOM_INTERNAL
#define GML_RNG_GEOM_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library;  fmin(), ceil(), log()
#include <limits.h> // INT_MAX
#include "uniform.h"
#include "ur_geomcdfinv.h"

static inline int
geomrng_core(double p)
{
	double x;
	x = ur_geomcdfinv(uniform_core(), p);
	if (x != x)  return 0;
	return x > INT_MAX ? INT_MAX : x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_RNG_GEOM_INTERNAL */
