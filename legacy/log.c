/*******************************************************************************
	GLUE-Math Library: Natural Logarithm
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/log.h"

double
legacy_log(double x)
{
	return log_core(x);
}
