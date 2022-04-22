/*******************************************************************************
	GLUE-Math Library: Cotangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_COT_DBL_INTERNAL
#define GML_COT_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fpclassify(), fmod()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "fmod.h"
#include "ur_tan.h"

static inline double
cot_core(register double x)
{
	static const double PI = 3.1415926535897932384626433832795;
	int k;
	register double t;

	for (;;) {
		switch (fpclassify(x)) {
		case FP_NAN:
			return NAN;
			break;
		case FP_INFINITE:
			return HUGE_VAL;
			break;
		case FP_ZERO:
		case FP_SUBNORMAL:
			return x < 0 ? -HUGE_VAL : HUGE_VAL;
			break;
		default:
			if (x < 0 || x > PI)
			{
				x = fmod_core(x, PI);
				continue;
			}
			break;
		}
		break;
	}
	switch (fpclassify(x + PI / 2)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0.0;
		break;
	default:
		break;
	}
	
	t = ur_tan(PI / 2 - x, &k);
	if (k % 2 == 0) return t;
	if (t != 0)     return -1 / t;
	/* overflow */  return HUGE_VAL;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COT_DBL_INTERNAL */
