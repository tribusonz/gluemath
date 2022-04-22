/*******************************************************************************
	GLUE-Math Library: Hyperbolic Sine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/sinhl.h"

long double
legacy_sinhl(long double x)
{
	return sinhl_core(x);
}
