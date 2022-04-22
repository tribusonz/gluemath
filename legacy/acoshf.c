/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/acoshf.h"

float
legacy_acoshf(float x)
{
	return acoshf_core(x);
}
