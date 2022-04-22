/*******************************************************************************
	GLUE-Math Library: Quadrant
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/quadrant.h"

double
quadrant_r8(double x, double y)
{
	return quadrant_core(x, y);
}
