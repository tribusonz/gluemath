/*******************************************************************************
	GLUE-Math Library: Common Logarithm
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/log10.h"

double
legacy_log10(double x)
{
	return log10_core(x);
}
