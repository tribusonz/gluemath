/*******************************************************************************
	GLUE-Math Library: Hyperbolic Secant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/sechl.h"

long double
sech_re(long double x)
{
	return sechl_core(x);
}
