/*******************************************************************************
	GLUE-Math Library: Cosecant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/cscf.h"

float
csc_r4(float x)
{
	return cscf_core(x);
}
