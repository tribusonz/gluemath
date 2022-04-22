/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Arctangent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/atanhl.h"

long double
legacy_atanhl(long double x)
{
	return atanhl_core(x);
}
