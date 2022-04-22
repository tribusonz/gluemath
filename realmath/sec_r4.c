/*******************************************************************************
	GLUE-Math Library: Secant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/secf.h"

float
sec_r4(float x)
{
	return secf_core(x);
}
