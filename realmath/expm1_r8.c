/*******************************************************************************
	GLUE-Math Library: expm1()
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/expm1.h"

double
expm1_r8(double x)
{
	return expm1_core(x);
}
