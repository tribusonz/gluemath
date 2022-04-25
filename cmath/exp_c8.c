/*******************************************************************************
	GLUE-Math Library: Complex Exponential Function

	Author:
	  Hironobu Inatsuka aka tribusonz
	License:
	  GPL + X11(MIT)
*******************************************************************************/
#include "cmath.h"
#include "../internal/ur/cexp.h"

dcomplex
exp_c8(dcomplex z)
{
	return cexp_core(z);
}
