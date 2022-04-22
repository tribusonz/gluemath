/*******************************************************************************
	GLUE-Math Library: Sine Integral
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/si.h"

double
si_r8(double x)
{
	return si_core(x);
}
