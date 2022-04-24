/*******************************************************************************
	GLUE-Math Library: Bessel Function (the 1st kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/j1.h"

double
j1_r8(double x)
{
	return j1_core(x);
}
