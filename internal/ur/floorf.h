/*******************************************************************************
	GLUE-Math Library: Floor Function (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_FLOOR_FLT_INTERNAL
#define GML_FLOOR_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: (nothing)
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "ur_floorf.h"
#include "ur_ceilf.h"
#if defined(_USE_NNINT_MACRO)
# include "nnint_macro.h"
# include <limits.h> // INT_MAX
#endif

static inline float
floorf_core(register float x)
{
	if (isfinite(x))
	{
#if defined(_USE_NNINT_MACRO)
		if (x > -INT_MAX && x < INT_MAX)
			return (float)(x < 0 ? -INLINE_CEIL(-x) : INLINE_FLOOR(x));
#endif
		return x < 0 ? -ur_ceilf(-x) : ur_floorf(x);
	}
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_FLOOR_FLT_INTERNAL */