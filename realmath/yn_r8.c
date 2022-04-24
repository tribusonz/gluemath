/*******************************************************************************
	GLUE-Math Library: Bessel Function (the 2nd kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/yn.h"

double
yn_r8(int n, double x)
{
	return yn_core(n, x);
}
