/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Arctangent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/atanhl.h"

long double
atanh_re(long double x)
{
	return atanhl_core(x);
}
