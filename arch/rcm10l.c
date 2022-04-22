/*******************************************************************************
	GLUE-Math Library -- Radix Complementation Method (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include "arch.h"
#include "../internal/sys/arch/rcm10l.h"

long double
gml_rcm10l(long double x, int *exp)
{
	return rcm10l_core(x, exp);
}
