/*******************************************************************************
	GLUE-Math Library: Fraction and Exponent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/frexp.h"

double
frexp_r8(double x, int *exp)
{
	return frexp_core(x, exp);
}
