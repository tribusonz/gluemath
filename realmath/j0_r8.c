/*******************************************************************************
	GLUE-Math Library: Bessel Function (the 1st kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/j0.h"

double
j0_r8(double x)
{
	return j0_core(x);
}
