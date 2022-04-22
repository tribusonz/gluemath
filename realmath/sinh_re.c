/*******************************************************************************
	GLUE-Math Library: Hyperbolic Sine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/sinhl.h"

long double
sinh_re(long double x)
{
	return sinhl_core(x);
}
