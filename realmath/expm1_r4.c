/*******************************************************************************
	GLUE-Math Library: expm1() (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/expm1f.h"

float
expm1_r4(float x)
{
	return expm1f_core(x);
}
