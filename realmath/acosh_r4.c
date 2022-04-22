/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acoshf.h"

float
acosh_r4(float x)
{
	return acoshf_core(x);
}
