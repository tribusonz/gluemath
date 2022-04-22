/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/acoshl.h"

long double
legacy_acoshl(long double x)
{
	return acoshl_core(x);
}
