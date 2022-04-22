/*******************************************************************************
	GLUE-Math Library -- Powers (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_POW_FLT_INTERNAL
#define GML_POW_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../tuning/pow_bin_calc.h"
#include <limits.h>  /* INT_MAX */
// uses math library: fabsf(), expf(), logf(), ipowf() */
#include "../../sys/float/absolute.h"
#if _POW_BINARY_CALC == 1
# include "exp2f.h"
# include "log2f.h"
#else
# include "expf.h"
# include "logf.h"
#endif
#include "ur_ipowf.h"

static inline float
powf_core(register float x, register float y)
{
	if (y <= INT_MAX && y >= -INT_MAX && y == (int)y)
		// NOTE: According to the exponential law, if the denominator is 0
		// and even one power calculation is included in the numerator,
		// it is always 1. (-1 if negative)
		return y == 0 ? x < 0 ? -1 : 1 : ur_ipowf(x, y);
	else if (x > 0)
#if _POW_BINARY_CALC == 1
		return exp2f_core(y * log2f_core(x));
#else
		return expf_core(y * logf_core(x));
#endif
	else if (x != 0 || y <= 0)
#if _POW_BINARY_CALC == 1
		return -exp2f_core(y * log2f_core(fabsf(x)));
#else
		return -expf_core(y * logf_core(fabsf(x)));
#endif
	/* else */ return 0;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_POW_FLT_INTERNAL */
