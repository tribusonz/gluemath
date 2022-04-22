/*******************************************************************************
	GLUE-Math Library: Arcsecant (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asecf.h"

float
asec_r4(float x)
{
	return asecf_core(x);
}
