/*******************************************************************************
	GLUE-Math Library: Binary Logarithm
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/log2.h"

double
legacy_log2(double x)
{
	return log2_core(x);
}
