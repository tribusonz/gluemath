/*******************************************************************************
	GLUE-Math Library: Exponential Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Programming in Oberon Tutorial
			- Niklaus Wirth and his team
*******************************************************************************/
#ifndef GML_EXPXT_LDBL_INTERNAL
#define GML_EXPXT_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: dbl_info.epsilon
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"

/* Taylor expansion with Wirth's form  $t(1.0) = e, t(\ln(2)) = 2$ */
static inline long double
expxtl(register long double x, register long double t)
{
	register long double a, b, c, s;
	get_dbl_info();
	a = x * t; b = 1.0; c = 1.0; s = 1.0;
	do {
		b = b * a / c;
		if (b < ldbl_info.epsilon)  break;
		s = s + b;
		c++;
	} while (1);
	return s;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_EXPXT_LDBL_INTERNAL */

