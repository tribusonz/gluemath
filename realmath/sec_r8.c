/*******************************************************************************
	GLUE-Math Library: Secant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/sec.h"

double
sec_r8(double x)
{
	return sec_core(x);
}
