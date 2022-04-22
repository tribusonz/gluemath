/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosecant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acschf.h"

float
acsch_r4(float x)
{
	return acschf_core(x);
}
