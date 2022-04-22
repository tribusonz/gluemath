/*******************************************************************************
	GLUE-Math Library: Exponential function (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/exp2f.h"

float
exp2_r4(float x)
{
	return exp2f_core(x);
}
