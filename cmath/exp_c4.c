/*******************************************************************************
	GLUE-Math Library: Complex Exponential Function (float)

	Author:
	  Hironobu Inatsuka aka tribusonz
	License:
	  GPL + X11(MIT)
*******************************************************************************/
#include "cmath.h"
#include "../internal/ur/cexpf.h"

fcomplex
exp_c4(fcomplex z)
{
	return cexpf_core(z);
}
