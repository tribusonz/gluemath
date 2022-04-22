/*******************************************************************************
	GLUE-Math Library: Binary Logarithm (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/log2f.h"

float
legacy_log2f(float x)
{
	return log2f_core(x);
}
