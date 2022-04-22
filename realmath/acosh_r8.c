/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arccosine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acosh.h"

double
acosh_r8(double x)
{
	return acosh_core(x);
}
