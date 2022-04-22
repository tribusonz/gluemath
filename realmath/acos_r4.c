/*******************************************************************************
	GLUE-Math Library: Arccosine (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acosf.h"

float
acos_r4(float x)
{
	return acosf_core(x);
}
