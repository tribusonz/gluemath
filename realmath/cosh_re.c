/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/coshl.h"

long double
cosh_re(long double x)
{
	return coshl_core(x);
}
