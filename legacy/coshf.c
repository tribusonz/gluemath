/*******************************************************************************
	GLUE-Math Library: Hyperbolic Cosine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/coshf.h"

float
legacy_coshf(float x)
{
	return coshf_core(x);
}
