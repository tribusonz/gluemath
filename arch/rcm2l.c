/*******************************************************************************
	GLUE-Math Library -- Radix Complementation Method (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "arch.h"
#include "../internal/sys/arch/rcm2l.h"

long double
gml_rcm2l(long double x, int *exp)
{
	return rcm2l_core(x, exp);
}
