/*******************************************************************************
	GLUE-Math Library: Modified Bessel Function (the 1st kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/i0.h"

double
i0_r8(double x)
{
	return i0_core(x);
}
