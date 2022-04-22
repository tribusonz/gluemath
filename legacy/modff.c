/*******************************************************************************
	GLUE-Math Library: Modf function (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/modff.h"

float
legacy_modff(float x, float *ip)
{
	return modff_core(x, ip);
}
