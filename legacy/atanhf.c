/*******************************************************************************
	GLUE-Math Library -- Hyperbolic Arctangent (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/atanhf.h"

float
legacy_atanhf(float x)
{
	return atanhf_core(x);
}
