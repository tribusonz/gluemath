/*******************************************************************************
	GLUE-Math Library: Fraction and Exponent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/frexpf.h"

float
frexp_r4(float x, int *exp)
{
	return frexpf_core(x, exp);
}
