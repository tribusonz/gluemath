/*******************************************************************************
	GLUE-Math Library: 1-Cosine (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/cos1l.h"

long double
cos1_re(long double x)
{
	return cos1l_core(x);
}
