/*******************************************************************************
	GLUE-Math Library: Quadrant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/atan2l.h"

long double
atan2_re(long double y, long double x)
{
	return atan2l_core(y, x);
}
