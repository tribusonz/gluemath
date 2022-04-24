/*******************************************************************************
	GLUE-Math Library: Bessel Function (the 1st kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/jn.h"

double
jn_r8(int n, double x)
{
	return jn_core(n, x);
}
