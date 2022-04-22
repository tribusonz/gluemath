/*******************************************************************************
	GLUE-Math Library: Exponential Integral

	Author:
	  William H. Press, Saul A. Teukolsky, William T. Vetterling, Brian P. Flannery
	  Hironobu Inatsuka aka tribusonz
	License:
	  GPL + X11(MIT)
	Reference:
	  Numerical Recipes in C; 3rd edition
*******************************************************************************/
#ifndef GML_EI_POS_INTERNAL
#define GML_EI_POS_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/absolute.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "exp.h"
#include "log.h"

// Ei(x), 0 < x < Infinity.
static inline double
ei_pos(register double x)
{
	static const int MAXIT = 100;
	static const double EULER = 0.577215664901533;
	volatile int k;
	register double fact, prev, sum, term;

	get_dbl_info();

	if (x < 0.0 || x != x)   return NAN;
	if (x < dbl_info.min / dbl_info.epsilon) return log_core(x) + EULER;
	if (x <= -log_core(dbl_info.epsilon))
	{
		sum = 0.0;
		fact = 1.0;
		for (k = 1; k <= MAXIT; k++)
		{
			fact *= x / k;
			term = fact / k;
			sum += term;
			if (term < dbl_info.epsilon * sum)  break;
		}
		if (k > MAXIT)  return NAN;
		return sum + log_core(x) + EULER;
	}
	else
	{
		sum = 0.0;
		term = 1.0;
		for (k = 1; k <= MAXIT; k++)
		{
			prev = term;
			term *= k / x;
			if (term < dbl_info.epsilon)  break;
			if (term < prev)  sum += term;
			else {            sum -= prev; break; }
		}
		return exp_core(x) * (1.0 + sum) / x;
	}
}


#if defined(__cplusplus)
}
#endif

#endif /* GML_EI_INTERNAL */
