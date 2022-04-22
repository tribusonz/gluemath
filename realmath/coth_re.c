/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cotangent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/cothl.h"

long double
coth_re(long double x)
{
	return cothl_core(x);
}
