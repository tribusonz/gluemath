/*******************************************************************************
	GLUE-Math Library: Hyperbolic Secant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/sech.h"

double
sech_r8(double x)
{
	return sech_core(x);
}
