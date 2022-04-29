/*******************************************************************************
	GLUE-Math Library: 1-Cosine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_COS1_LDBL_INTERNAL
#define GML_COS1_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: fpclassify(), fmodl(), fabsl()
#include "../../sys/float/absolute.h"
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "fmodl.h"
#include "m_pi.h"
#include "ur_tanl.h"

static inline long double
cos1l_core(register long double x)
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
			return x < 0 ? 0 : 2;
			break;
		case FP_ZERO:
		case FP_SUBNORMAL:
			return 0.L;
			break;
		default:
			if (x > (pi * 2))
			{
				x = fmodl_core(x, pi * 2);
				continue;
			}
			break;
		}
		break;
	}

	t = ur_tanl(fabsl(x / 2), &k);  t *= t;
	if (k % 2 == 0) return 2 * t / (1 + t);
	/* else */      return 2     / (1 + t);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COS1_LDBL_INTERNAL */
