/*******************************************************************************
	GLUE-Math Library: DE-rule
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "../internal/ur/intde.h"

void
intde(integrand f, double a, double b, double *i, double *err)
{
	intde_core(f, a, b, i, err);
}
