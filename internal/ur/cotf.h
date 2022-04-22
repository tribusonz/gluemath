/*******************************************************************************
	GLUE-Math Library: Cotangent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_COT_FLT_INTERNAL
#define GML_COT_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fpclassify(), fmodf()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "fmodf.h"
#include "ur_tanf.h"

static inline float
cotf_core(register float x)
{
	static const float PI = 3.1415926535897932384626433832795;
	int k;
	register float t;

	for (;;) {
		switch (fpclassify(x)) {
		case FP_NAN:
			return NAN;
			break;
		case FP_INFINITE:
			return HUGE_VALF;
			break;
		case FP_ZERO:
		case FP_SUBNORMAL:
			return x < 0 ? -HUGE_VALF : HUGE_VALF;
			break;
		default:
			if (x < 0 || x > PI)
			{
				x = fmodf_core(x, PI);
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
	
	t = ur_tanf(PI / 2 - x, &k);
	if (k % 2 == 0) return t;
	if (t != 0)     return -1 / t;
	/* overflow */  return HUGE_VALF;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COT_FLT_INTERNAL */
