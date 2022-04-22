/*******************************************************************************
	GLUE-Math Library: Arccosecant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acscf.h"

float
acsc_r4(float x)
{
	return acscf_core(x);
}
