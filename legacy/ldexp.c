/*******************************************************************************
	GLUE-Math Library: Load exponent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/ldexp.h"

double
legacy_ldexp(double x, int exp)
{
	return ldexp_core(x, exp);
}
