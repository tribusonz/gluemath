/*******************************************************************************
	GLUE-Math Library: Cosecant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/csc.h"

double
csc_r8(double x)
{
	return csc_core(x);
}
