/*******************************************************************************
	GLUE-Math Library: Truncate Function (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_TRUNC_LDBL_INTERNAL
#define GML_TRUNC_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: (nothing)
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "ur_floorl.h"
#if defined(_USE_NNINT_MACRO)
# include "nnint_macro.h"
# include <limits.h> // INT_MAX
#endif

static inline long double
truncl_core(register long double x)
{
	if (isfinite(x))
	{
#if defined(_USE_NNINT_MACRO)
		if (x > -INT_MAX && x < INT_MAX)
			return (long double)(x < 0 ? -INLINE_FLOOR(-x) : INLINE_FLOOR(x));
#endif
		return x < 0 ? -ur_floorl(-x) : ur_floorl(x);
	}
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_TRUNC_LDBL_INTERNAL */
