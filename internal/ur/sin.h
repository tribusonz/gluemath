/*******************************************************************************
	GLUE-Math Library: Sine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_SIN_DBL_INTERNAL
#define GML_SIN_DBL_INTERNAL

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
sin_core(register double x)
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
			return x < 0 ? -1 : 1;
			break;
		case FP_ZERO:
		case FP_SUBNORMAL:
			return 0.0;
			break;
		default:
			if (x < (-PI * 2) || x > (PI * 2))
			{
				x = x < 0 ? fmod_core(x, -PI * 2) : fmod_core(x, PI * 2);
				continue;
			}
			break;
		}
		break;
	}
	switch (fpclassify(fmod_core(x, PI))) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0.0;
		break;
	default:
		break;
	}

	t = ur_tan(x / 2, &k);
	t = 2 * t / (1 + t * t);
	if (k % 2 == 0) return  t;
	/* else */      return -t;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SIN_DBL_INTERNAL */
