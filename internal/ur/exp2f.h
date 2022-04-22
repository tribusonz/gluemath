/*******************************************************************************
	GLUE-Math Library: Exponential Function (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_EXP2_FLT_INTERNAL
#define GML_EXP2_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../tuning/constexpr_exp.h"
#include "ur_ipowf.h"
#include "expxtf.h"
#include "nnint_macro.h"
#ifndef INT_FLOOR_INLINE
# define INT_FLOOR_INLINE(x) ((x) < 0 ? -INLINE_CEIL(-(x)) : INLINE_FLOOR(x))
#endif

static inline float
exp2f_core(register float x)
{
	static const float LOG2 = 0.6931471805599453;
	register int floorx;
	register float vexp, vfra;
	get_exp2f_const();

	if (x != x)  return NAN;
	else if (x >= exp2f_min && x <= exp2f_max)
	{
		floorx = INT_FLOOR_INLINE(x); vfra = x - floorx;
		vexp = ur_ipowf(2, floorx);
		if (vfra == 0.0)  return vexp;
		return vexp * expxtf(vfra, LOG2);
	}
	/* else */ return (x < 0) ? 0.0 : HUGE_VALF;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXP2_FLT_INTERNAL */

