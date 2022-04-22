/*******************************************************************************
	GLUE-Math Library: Modified Bessel Function (the 2nd kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/k0.h"

double
k0_r8(double x)
{
	return k0_core(x);
}
