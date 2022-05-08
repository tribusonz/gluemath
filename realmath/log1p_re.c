/*******************************************************************************
	GLUE-Math Library: log1p() (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/log1pl.h"

long double
log1p_re(long double x)
{
	return log1pl_core(x);
}
