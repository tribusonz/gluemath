/*******************************************************************************
	GLUE-Math Library: Natural Logarithm
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/log.h"

double
log_r8(double x)
{
	return log_core(x);
}
