/*******************************************************************************
	GLUE-Math Library: Logarithm of Gamma Function (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/lgamma.h"

float
lgamma_r4(float x)
{
	return (float)lgamma_core((double)x);
}
