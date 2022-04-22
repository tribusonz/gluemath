/*******************************************************************************
	GLUE-Math Library: Load Exponent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/ldexpf.h"

float
legacy_ldexpf(float x, int exp)
{
	return ldexpf_core(x, exp);
}
