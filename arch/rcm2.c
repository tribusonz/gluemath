/*******************************************************************************
	GLUE-Math Library -- Radix Complementation Method

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "arch.h"
#include "../internal/sys/arch/rcm2.h"

double
gml_rcm2(double x, int *exp)
{
	return rcm2_core(x, exp);
}
