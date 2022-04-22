/*******************************************************************************
	GLUE-Math Library: Exponential Integral
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/ei.h"

double
ei_r8(double x)
{
	return ei_core(x);
}
