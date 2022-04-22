/*******************************************************************************
	GLUE-Math Library: Ceiling Function (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_CEIL_FLT_INTERNAL
#define GML_CEIL_FLT_INTERNAL

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
ceilf_core(register float x)
{
	if (isfinite(x))
	{
#if defined(_USE_NNINT_MACRO)
		if (x > -INT_MAX && x < INT_MAX)
			return (float)(x < 0 ? -INLINE_FLOOR(-x) : INLINE_CEIL(x));
#endif
		return x < 0 ? -ur_floorf(-x) : ur_ceilf(x);
	}
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CEIL_FLT_INTERNAL */
