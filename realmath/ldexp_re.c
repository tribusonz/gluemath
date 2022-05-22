/*******************************************************************************
	GLUE-Math Library: Load Exponent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/ldexpl.h"

long double
ldexp_re(long double x, int exp)
{
	return ldexpl_core(x, exp);
}
