/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acoshl.h"

long double
acosh_re(long double x)
{
	return acoshl_core(x);
}
