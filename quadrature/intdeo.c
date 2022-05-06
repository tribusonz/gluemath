/*******************************************************************************
	GLUE-Math Library: DE-rule
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "../internal/ur/intdeo.h"

void
intdeo(integrand f, double a, double omega, double *i, double *err)
{
	intdeo_core(f, a, omega, i, err);
}
