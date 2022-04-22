/*******************************************************************************
	GLUE-Math Library: Exponential Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_EXP2_DBL_INTERNAL
#define GML_EXP2_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../tuning/constexpr_exp.h"
#include "ur_ipow.h"
#include "expxt.h"
#include "nnint_macro.h"
#ifndef INT_FLOOR_INLINE
# define INT_FLOOR_INLINE(x) ((x) < 0 ? -INLINE_CEIL(-(x)) : INLINE_FLOOR(x))
#endif

static inline double
exp2_core(register double x)
{
	static const double LOG2 = 0.6931471805599453;
	register int floorx;
	register double vexp, vfra;
	get_exp2_const();

	if (x != x)  return NAN;
	else if (x >= exp2_min && x <= exp2_max)
	{
		floorx = INT_FLOOR_INLINE(x); vfra = x - floorx;
		vexp = ur_ipow(2, floorx);
		if (vfra == 0.0)  return vexp;
		return vexp * expxt(vfra, LOG2);
	}
	/* else */ return (x < 0) ? 0.0 : HUGE_VAL;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXP2_DBL_INTERNAL */

