/*******************************************************************************
	GLUE-Math Library: Natural Logarithm (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/logf.h"

float
log_r4(float x)
{
	return logf_core(x);
}
