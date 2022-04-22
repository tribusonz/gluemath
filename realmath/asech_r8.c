/*******************************************************************************
	GLUE-Math Library: Hyperbolic Arcsecant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asech.h"

double
asech_r8(double x)
{
	return asech_core(x);
}
