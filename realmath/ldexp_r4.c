/*******************************************************************************
	GLUE-Math Library: Load Exponent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/ldexpf.h"

float
ldexp_r4(float x, int exp)
{
	return ldexpf_core(x, exp);
}
