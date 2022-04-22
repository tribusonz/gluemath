/*******************************************************************************
	GLUE-Math Library: Arctangent
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/atan.h"

double
atan_r8(double x)
{
	return atan_core(x);
}
