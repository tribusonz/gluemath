/*******************************************************************************
	GLUE-Math Library: Logarithm of Gamma Function (long double)
		- Asymptotic expansion by Bernoulli series

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_LGAMMA_B_LDBL_INTERNAL
#define GML_LGAMMA_B_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: logl(), fabsl(), isinf(), NAN
#include "logl.h"
#include "m_pi.h"
#include "../../sys/float/absolute.h"
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "bernoulli_macro_ldbl.h"

static inline long double
loggammal_b(register long double x, int *signp)
{
	register long double v, w;
	static long double log_2pi = 0;
	static const int N = 8;
	
	if (log_2pi == 0.0)  log_2pi = logl_core(2.L * m_pi_ld());
	
	v = 1;
	if (x >= 0)
	{
		while (x < N) {  v *= x;  x++;  }
		v = logl_core(v);
	}
	else
	{
		while (x < N) {
			if (isinf(v *= x))  return NAN;
			x++;
		}
		v = logl_core(fabsl(v));
	}
	w = 1 / (x * x);

	if (x < 0)  *signp = -1;
	else        *signp =  1;

	return ((((((((B16l / (16 * 15))  * w + (B14l / (14 * 13))) * w
	            + (B12l / (12 * 11))) * w + (B10l / (10 *  9))) * w
	            + (B8l  / ( 8 *  7))) * w + (B6l  / ( 6 *  5))) * w
	            + (B4l  / ( 4 *  3))) * w + (B2l  / ( 2 *  1))) / x
	            + 0.5 * log_2pi - v - x + (x - 0.5) * logl_core(fabsl(x));
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LGAMMA_B_LDBL_INTERNAL */
