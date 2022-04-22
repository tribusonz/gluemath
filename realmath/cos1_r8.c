/*******************************************************************************
	GLUE-Math Library: 1-Cosine
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/cos1.h"

double
cos1_r8(double x)
{
	return cos1_core(x);
}
