/*******************************************************************************
	GLUE-Math Library: Modified Bessel Function (the 2nd kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/kn.h"

double
kn_r8(int n, double x)
{
	return kn_core(n, x);
}
