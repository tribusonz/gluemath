/*******************************************************************************
	GLUE-Math Library: Arccosine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acos.h"

double
acos_r8(double x)
{
	return acos_core(x);
}
