/*******************************************************************************
	GLUE-Math Library: Modf function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/modf.h"

double
modf_r8(double x, double *ip)
{
	return modf_core(x, ip);
}
