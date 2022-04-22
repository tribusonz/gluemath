/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asinhl.h"

long double
asinh_re(long double x)
{
	return asinhl_core(x);
}
