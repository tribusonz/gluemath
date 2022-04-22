/*******************************************************************************
	GLUE-Math Library: Binary Logarithm
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/log2.h"

double
log2_r8(double x)
{
	return log2_core(x);
}
