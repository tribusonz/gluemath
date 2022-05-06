/*******************************************************************************
	GLUE-Math Library: DE-rule
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "../internal/ur/intdei.h"

void
intdei(integrand f, double a, double *i, double *err)
{
	intdei_core(f, a, i, err);
}
