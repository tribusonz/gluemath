/*******************************************************************************
	GLUE-Math Library: Binary Logarithm (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/log2f.h"

float
log2_r4(float x)
{
	return log2f_core(x);
}
