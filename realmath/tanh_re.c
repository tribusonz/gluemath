/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Tangent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/tanhl.h"

long double
tanh_re(long double x)
{
	return tanhl_core(x);
}
