/*******************************************************************************
	GLUE-Math Library -- Binary Logarithm
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Programming in Oberon Tutorial
			- Niklaus Wirth and his team
*******************************************************************************/
#ifndef RCM_OBERON_FLT_INTERNAL
#define RCM_OBERON_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Use library: flt_info.epsilon
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"

// for t, e is ln(x), 2 is log_2(x), 10 is log_10(x)
static inline float
logxtf(register float x, register float t)
{
	register float a, b, s;
	get_flt_info();
	a = x; b = 1.0; s = 0.0;
	do {
		a = a * a;  b = 0.5 * b;
		if (a >= t) {	s = s + b; a = a / t; }
	} while (b >= flt_info.epsilon);
	return s;
}

#if defined(__cplusplus)
}
#endif

#endif /* RCM_OBERON_FLT_INTERNAL */
