/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Tangent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/tanhl.h"

long double
legacy_tanhl(long double x)
{
	return tanhl_core(x);
}
