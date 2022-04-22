/*******************************************************************************
	GLUE-Math Library: Logarithmic Integral
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/li.h"

double
li_r8(double x)
{
	return li_core(x);
}
