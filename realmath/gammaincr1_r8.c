/*******************************************************************************
	GLUE-Math Library: Regularized Incomplete Gamma Function (1st kind)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
	Following paper:
	  All about of p-adic special functions (Japanese) - Yasuo Morita
*******************************************************************************/
#include "realmath.h"
#include "../internal/ur/gammaincr.h"

double
gammaincr1_r8(double a, double x)
{
	return gammaincr1_core(a, x);
}
