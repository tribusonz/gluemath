/*******************************************************************************
	GLUE-Math Library: Riemann Zeta Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/riemann_zeta.h"

double
riemann_zeta_r8(double x)
{
	return riemann_zeta_core(x);
}
