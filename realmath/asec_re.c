/*******************************************************************************
	GLUE-Math Library: Arcsecant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/asecl.h"

long double
asec_re(long double x)
{
	return asecl_core(x);
}
