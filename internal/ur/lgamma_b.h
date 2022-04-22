/*******************************************************************************
	GLUE-Math Library: Logarithm of Gamma Function
		- Asymptotic expansion by Bernoulli series

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_LGAMMA_B_DBL_INTERNAL
#define GML_LGAMMA_B_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: log(), fabs(), isinf(), NAN
#include "log.h"
#include "../../sys/float/absolute.h"
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "bernoulli_macro.h"

static inline double
loggamma_b(register double x, int *signp)
{
	register double v, w;
	static const double LOG_2PI = 1.83787706640934548;
	static const int N = 8;
	
	v = 1;
	if (x >= 0)
	{
		while (x < N) {  v *= x;  x++;  }
		v = log_core(v);
	}
	else
	{
		while (x < N) {
			if (isinf(v *= x))  return NAN;
			x++;
		}
		v = log_core(fabs(v));
	}
	w = 1 / (x * x);

	if (x < 0)  *signp = -1;
	else        *signp =  1;

	return ((((((((B16 / (16 * 15))  * w + (B14 / (14 * 13))) * w
	            + (B12 / (12 * 11))) * w + (B10 / (10 *  9))) * w
	            + (B8  / ( 8 *  7))) * w + (B6  / ( 6 *  5))) * w
	            + (B4  / ( 4 *  3))) * w + (B2  / ( 2 *  1))) / x
	            + 0.5 * LOG_2PI - v - x + (x - 0.5) * log_core(fabs(x));
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LGAMMA_B_DBL_INTERNAL */
