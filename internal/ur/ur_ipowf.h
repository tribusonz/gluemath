/*******************************************************************************
	GLUE-Math Library: Integer Power (float)
	
	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_INTPOWER_FLT_INTERNAL
#define GML_INTPOWER_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h>  /* abs() */

/* Integer power */
// Note:
// This is a subroutine for internal operations, not an interface.
// For example, x^|INT_MIN| the behavior is undefined.
static inline float
ur_ipowf(register float x, register int n)
{
	register int abs_n;
	register float r;

	abs_n = abs(n);  r = 1;
	while (abs_n != 0) {
		if (abs_n & 1) r *= x;
		x *= x;  abs_n >>= 1;
	}
	if (n >= 0) return r;  else return 1 / r;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_INTPOWER_FLT_INTERNAL */

