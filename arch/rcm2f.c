/*******************************************************************************
	GLUE-Math Library -- Radix Complementation Method (float)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "arch.h"
#include "../internal/sys/arch/rcm2f.h"

float
gml_rcm2f(float x, int *exp)
{
	return rcm2f_core(x, exp);
}
