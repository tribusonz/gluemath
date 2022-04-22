/*******************************************************************************
	GLUE-Math Library: RNG -- Poisson Distribution

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/poissrng.h"
#include "../tuning/spmax.h"

int
gml_poissrng(double lambda)
{
	int v;
	v = poissrng_core(lambda);
	return v > STAT_PARAM_MAX ? STAT_PARAM_MAX : v; // fmin(v, STAT_PARAM_MAX)
}
