/*******************************************************************************
	GLUE-Math Library: Fraction and Exponent (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/frexpl.h"

long double
legacy_frexpl(long double x, int *exp)
{
	return frexpl_core(x, exp);
}
