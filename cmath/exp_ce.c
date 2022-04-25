/*******************************************************************************
	GLUE-Math Library: Complex Exponential Function (long double)

	Author:
	  Hironobu Inatsuka aka tribusonz
	License:
	  GPL + X11(MIT)
*******************************************************************************/
#include "cmath.h"
#include "../internal/ur/cexpl.h"

lcomplex
exp_ce(lcomplex z)
{
	return cexpl_core(z);
}
