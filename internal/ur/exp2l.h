/*******************************************************************************
	GLUE-Math Library: Exponential Function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_EXP2_LDBL_INTERNAL
#define GML_EXP2_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../tuning/constexpr_exp.h"
#include "ur_ipowl.h"
#include "expxtl.h"
#include "m_log2.h"
#include "nnint_macro.h"
#ifndef INT_FLOOR_INLINE
# define INT_FLOOR_INLINE(x) ((x) < 0 ? -INLINE_CEIL(-(x)) : INLINE_FLOOR(x))
#endif

static inline long double
exp2l_core(register long double x)
{
	static long double log2 = 0.0;
	register int floorx;
	register long double vexp, vfra;
	if (log2 == 0.0)  log2 = m_log2_ld();
	
	get_exp2l_const();

	if (x != x)  return NAN;
	else if (x >= exp2l_min && x <= exp2l_max)
	{
		floorx = INT_FLOOR_INLINE(x); vfra = x - floorx;
		vexp = ur_ipowl(2, floorx);
		if (vfra == 0.0)  return vexp;
		return vexp * expxtl(vfra, log2);
	}
	/* else */ return (x < 0) ? 0.0 : HUGE_VALL;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXP2_LDBL_INTERNAL */

