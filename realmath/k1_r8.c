/*******************************************************************************
	GLUE-Math Library: Modified Bessel Function (the 2nd kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/k1.h"

double
k1_r8(double x)
{
	return k1_core(x);
}
