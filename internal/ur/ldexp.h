/*******************************************************************************
	GLUE-Math Library: Load Exponent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_LOADEXPONENT_DBL_INTERNAL
#define GML_LOADEXPONENT_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: (nothing)

/* Prof. Okumura's load exponent $2^{k}x$ */
static inline double
ldexp_core(register double x, register int k)
{
	register double w;

	if (k >= 0) w = 2;
	else {  w = 0.5;  k = - k;  }
	while (k) {
		if (k & 1) x *= w;
		w *= w;  k >>= 1;
	}
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LOADEXPONENT_DBL_INTERNAL */
