/*******************************************************************************
	GLUE-Math Library: Cosine Integral
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/ci.h"

double
ci_r8(double x)
{
	return ci_core(x);
}
