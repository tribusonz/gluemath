/*******************************************************************************
	GLUE-Math Library: log1p() (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/log1pf.h"

float
log1p_r4(float x)
{
	return log1pf_core(x);
}
