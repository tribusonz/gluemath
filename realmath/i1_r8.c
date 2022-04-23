/*******************************************************************************
	GLUE-Math Library: Modified Bessel Function (the 1st kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/i1.h"

double
i1_r8(double x)
{
	return i1_core(x);
}
