/*******************************************************************************
	GLUE-Math Library -- Powers

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_POW_DBL_INTERNAL
#define GML_POW_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../tuning/pow_bin_calc.h"
#include <limits.h>  /* INT_MAX */
// uses math library: fabs(), exp(), log(), ipow() */
#include "../../sys/float/absolute.h"
#if _POW_BINARY_CALC == 1
# include "exp2.h"
# include "log2.h"
#else
# include "exp.h"
# include "log.h"
#endif
#include "ur_ipow.h"

static inline double
pow_core(register double x, register double y)
{
	if (y <= INT_MAX && y >= -INT_MAX && y == (int)y)
		// NOTE: According to the exponential law, if the denominator is 0
		// and even one power calculation is included in the numerator,
		// it is always 1. (-1 if negative)
		return y == 0 ? x < 0 ? -1 : 1 : ur_ipow(x, y);
	else if (x > 0)
#if _POW_BINARY_CALC == 1
		return exp2_core(y * log2_core(x));
#else
		return exp_core(y * log_core(x));
#endif
	else if (x != 0 || y <= 0)
#if _POW_BINARY_CALC == 1
		return -exp2_core(y * log2_core(fabs(x)));
#else
		return -exp_core(y * log_core(fabs(x)));
#endif
	/* else */ return 0;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_POW_DBL_INTERNAL */
