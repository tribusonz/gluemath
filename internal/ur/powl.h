/*******************************************************************************
	GLUE-Math Library -- Powers (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_POW_LDBL_INTERNAL
#define GML_POW_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../tuning/pow_bin_calc.h"
#include <limits.h>  /* INT_MAX */
// uses math library: fabsl(), expl(), logl(), ipowl() */
#include "../../sys/float/absolute.h"
#if _POW_BINARY_CALC == 1
# include "exp2l.h"
# include "log2l.h"
#else
# include "expl.h"
# include "logl.h"
#endif
#include "ur_ipowl.h"

static inline long double
powl_core(register long double x, register long double y)
{
	if (y <= INT_MAX && y >= -INT_MAX && y == (int)y)
		// NOTE: According to the exponential law, if the denominator is 0
		// and even one power calculation is included in the numerator,
		// it is always 1. (-1 if negative)
		return y == 0 ? x < 0 ? -1 : 1 : ur_ipowl(x, y);
	else if (x > 0)
#if _POW_BINARY_CALC == 1
		return exp2l_core(y * log2l_core(x));
#else
		return expl_core(y * logl_core(x));
#endif
	else if (x != 0 || y <= 0)
#if _POW_BINARY_CALC == 1
		return -exp2l_core(y * log2l_core(fabsl(x)));
#else
		return -expl_core(y * logl_core(fabsl(x)));
#endif
	/* else */ return 0;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_POW_LDBL_INTERNAL */
