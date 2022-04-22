/*******************************************************************************
	GLUE-Math Library: Common Logarithm
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/log10.h"

double
log10_r8(double x)
{
	return log10_core(x);
}
