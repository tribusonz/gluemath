/*******************************************************************************
	GLUE-Math Library: Gamma Function (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/gammal.h"

long double
gamma_re(long double x)
{
	return gammal_core(x);
}
