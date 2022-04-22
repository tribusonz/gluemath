/*******************************************************************************
	GLUE-Math Library: Arcsecant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asec.h"

double
asec_r8(double x)
{
	return asec_core(x);
}
