/*******************************************************************************
	GLUE-Math Library: Common Logarithm (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/log10f.h"

float
log10_r4(float x)
{
	return log10f_core(x);
}
