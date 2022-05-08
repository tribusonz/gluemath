/*******************************************************************************
	GLUE-Math Library: log1p()
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/log1p.h"

double
log1p_r8(double x)
{
	return log1p_core(x);
}
