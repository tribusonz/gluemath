/*******************************************************************************
	GLUE-Math Library: Arcsine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asin.h"

double
asin_r8(double x)
{
	return asin_core(x);
}
