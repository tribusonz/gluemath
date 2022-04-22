/*******************************************************************************
	GLUE-Math Library: Arcsine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asinf.h"

float
asin_r4(float x)
{
	return asinf_core(x);
}
