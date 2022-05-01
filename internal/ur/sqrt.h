/*******************************************************************************
	GLUE-Math Library: Square Root (double)
	
	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_SQUAREROOT_DBL_INTERNAL
#define GML_SQUAREROOT_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: (nothing)
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"

/* Prof. Okumura's $\sqrt{x}$ */
static inline double
sqrt_core(register double x)
{
	register double s, last;

	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return x > 0 ? HUGE_VAL : NAN;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0.0;
		break;
	default:
		if (x > 0) {
			if (x > 1) s = x;  else s = 1;
			do {
				last = s;  s = (x / s + s) / 2;
			} while (s < last);
			return last;
		}
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SQUAREROOT_DBL_INTERNAL */
