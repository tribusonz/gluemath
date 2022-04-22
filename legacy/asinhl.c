/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/asinhl.h"

long double
legacy_asinhl(long double x)
{
	return asinhl_core(x);
}
