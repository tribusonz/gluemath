/*******************************************************************************
	GLUE-Math Library: Load exponent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/ldexp.h"

double
ldexp_r8(double x, int exp)
{
	return ldexp_core(x, exp);
}
