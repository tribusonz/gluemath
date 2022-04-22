/*******************************************************************************
    GLUE Math Library: Arccosine (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_ACOS_LDBL_INTERNAL
#define GML_ACOS_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: sqrtl()
#include "../../sys/float/huge_val_nan.h"
#include "ur_atanl.h"
#include "sqrtl.h"
#include "m_pi.h"

static inline long double
acosl_core(register long double x)
{
	static long double pi2 = 0.0;
	if (pi2 == 0.0)  pi2 = m_pi_ld() / 2.L;
	if (x >= -1.L && x <= 1.L)
		return pi2 - ur_atanl(x / sqrtl_core(1 - x * x));
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_ACOS_LDBL_INTERNAL */
