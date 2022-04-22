/*******************************************************************************
	GLUE-Math Library: Sine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_SIN_LDBL_INTERNAL
#define GML_SIN_LDBL_INTERNAL

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
sinl_core(register long double x)
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
			return 0.L;
			break;
		default:
			if (x < (-pi * 2) || x > (pi * 2))
			{
				x = x < 0 ? fmodl_core(x, -pi * 2) : fmodl_core(x, pi * 2);
				continue;
			}
			break;
		}
		break;
	}
	switch (fpclassify(fmodl_core(x, pi))) {
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0.L;
		break;
	default:
		break;
	}

	t = ur_tanl(x / 2, &k);
	t = 2 * t / (1 + t * t);
	if (k % 2 == 0) return  t;
	/* else */      return -t;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SIN_LDBL_INTERNAL */
