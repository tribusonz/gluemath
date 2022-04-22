/*******************************************************************************
	GLUE-Math Library: Fraction and Exponent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/frexpf.h"

float
legacy_frexpf(float x, int *exp)
{
	return frexpf_core(x, exp);
}
