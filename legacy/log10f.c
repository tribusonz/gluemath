/*******************************************************************************
	GLUE-Math Library: Common Logarithm (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/log10f.h"

float
legacy_log10f(float x)
{
	return log10f_core(x);
}
