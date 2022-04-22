/*******************************************************************************
	GLUE-Math Library -- Radix Complementation Method (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "arch.h"
#include "../internal/sys/arch/rcm10f.h"

float
gml_rcm10f(float x, int *exp)
{
	return rcm10f_core(x, exp);
}
