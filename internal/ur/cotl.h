/*******************************************************************************
	GLUE-Math Library: Cotangent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_COT_LDBL_INTERNAL
#define GML_COT_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fpclassify(), fmodl()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "fmodl.h"
#include "m_pi.h"
#include "ur_tanl.h"

static inline long double
cotl_core(register long double x)
{
	static long double pi = 0.L;
	int k;
	register long double t;

	if (pi == 0.L)  pi = m_pi_ld();

	for (;;) {
		switch (fpclassify(x)) {
		case FP_NAN:
			return NAN;
			break;
		case FP_INFINITE:
			return HUGE_VALL;
			break;
		case FP_ZERO:
		case FP_SUBNORMAL:
			return x < 0 ? -HUGE_VALL : HUGE_VAL;
			break;
		default:
			if (x < 0 || x > pi)
			{
				x = fmodl_core(x, pi);
				continue;
			}
			break;
		}
		break;
	}
	switch (fpclassify(x + pi / 2)) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0.L;
		break;
	default:
		break;
	}
	
	t = ur_tanl(pi / 2 - x, &k);
	if (k % 2 == 0) return t;
	if (t != 0)     return -1 / t;
	/* overflow */  return HUGE_VALL;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COT_LDBL_INTERNAL */
