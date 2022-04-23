/*******************************************************************************
	GLUE-Math Library: Modified Bessel Function (the 1st kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/in.h"

double
in_r8(int n, double x)
{
	return in_core(n, x);
}
