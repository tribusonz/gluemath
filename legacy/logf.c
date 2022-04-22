/*******************************************************************************
	GLUE-Math Library: Natural Logarithm (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/logf.h"

float
legacy_logf(float x)
{
	return logf_core(x);
}
