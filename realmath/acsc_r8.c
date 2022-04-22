/*******************************************************************************
	GLUE-Math Library: Arccosecant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/acsc.h"

double
acsc_r8(double x)
{
	return acsc_core(x);
}
