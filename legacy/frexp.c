/*******************************************************************************
	GLUE-Math Library: Fraction and Exponent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/frexp.h"

double
legacy_frexp(double x, int *exp)
{
	return frexp_core(x, exp);
}
