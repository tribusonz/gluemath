/*******************************************************************************
	GLUE-Math Library: Load Exponent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/ldexpl.h"

long double
legacy_ldexpl(long double x, int exp)
{
	return ldexpl_core(x, exp);
}
