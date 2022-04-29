/*******************************************************************************
	GLUE-Math Library: 1-Cosine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_COS1_DBL_INTERNAL
#define GML_COS1_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fpclassify(), fmod(), fabs()
#include "../../sys/float/absolute.h"
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "fmod.h"
#include "ur_tan.h"

static inline double
cos1_core(register double x)
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
			return x < 0 ? 2 : 0;
			break;
		case FP_ZERO:
		case FP_SUBNORMAL:
			return 0.0;
			break;
		default:
			if (x > (PI * 2))
			{
				x = fmod_core(x, PI * 2);
				continue;
			}
			break;
		}
		break;
	}

	t = ur_tan(fabs(x / 2), &k);  t *= t;
	if (k % 2 == 0) return 2 * t / (1 + t);
	/* else */      return 2     / (1 + t);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COS1_DBL_INTERNAL */
