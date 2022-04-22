/*******************************************************************************
	GLUE-Math Library -- Radix Complementation Method

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "arch.h"
#include "../internal/sys/arch/rcm10.h"

double
gml_rcm10(double x, int *exp)
{
	return rcm10_core(x, exp);
}
