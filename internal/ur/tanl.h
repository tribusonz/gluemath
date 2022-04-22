/*******************************************************************************
	GLUE-Math Library: Tangent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_TAN_LDBL_INTERNAL
#define GML_TAN_LDBL_INTERNAL

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
tanl_core(register long double x)
{
	static long double pi = 0.L;
	int k, sgn = 0;
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
			if (x < -pi || x > pi)
			{
				x = x < 0 ? fmodl_core(x, -pi) : fmodl_core(x, pi);
				continue;
			}
			sgn = x < 0 ? -1 : 1;
			break;
		}
		break;
	}
	switch (sgn) {
	case -1:
		switch (fpclassify(x + pi / 2)) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			return -HUGE_VALL;  // atan(tan(-PI/2)) = -PI/2
			break;
		default:
			break;
		}
		break;
	case 1:
		switch (fpclassify(x - pi / 2)) {
		case FP_ZERO:
		case FP_SUBNORMAL:
			return HUGE_VALL;  // atan(tan(PI/2)) = PI/2
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	
	t = ur_tanl(x, &k);
	if (k % 2 == 0) return t;
	if (t != 0)     return -1 / t;
	/* overflow */  return HUGE_VALL;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_TAN_LDBL_INTERNAL */
