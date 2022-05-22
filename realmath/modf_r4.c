/*******************************************************************************
	GLUE-Math Library: Modf function (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/modff.h"

float
modf_r4(float x, float *ip)
{
	return modff_core(x, ip);
}
