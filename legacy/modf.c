/*******************************************************************************
	GLUE-Math Library: Modf function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "legacy.h"
#include "../internal/ur/modf.h"

double
legacy_modf(double x, double *ip)
{
	return modf_core(x, ip);
}
