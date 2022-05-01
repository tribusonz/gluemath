/*******************************************************************************
    GLUE Math Library: Inverse Trigonometric Function (long double)

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_UR_ATAN_LDBL_INTERNAL
#define GML_UR_ATAN_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "m_pi.h"

static inline long double
ur_atanl(register long double x)
{
	static const int N = 24;
	static long double pi = 0.0;
	register int sgn;
	register long double a;
	if (pi == 0.0)  pi = m_pi_ld();

	if      (x >  1) {  sgn =  1;  x = 1 / x;  }
	else if (x < -1) {  sgn = -1;  x = 1 / x;  }
	else                sgn =  0;
	a = 0;
	for (volatile int i = N; i >= 1; i--)
		a = (i * i * x * x) / (2 * i + 1 + a);
	if (sgn > 0) return  pi / 2 - x / (1 + a);
	if (sgn < 0) return -pi / 2 - x / (1 + a);
	/* else */   return           x / (1 + a);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_UR_ATAN_LDBL_INTERNAL */
