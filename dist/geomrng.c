/*******************************************************************************
	GLUE-Math Library: RNG -- Geometric Distribution

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/geomrng.h"
#include "../tuning/spmax.h"

int
gml_geomrng(double phi)
{
	int v;
	v = geomrng_core(phi);
	return v > STAT_PARAM_MAX ? STAT_PARAM_MAX : v; // fmin(v, STAT_PARAM_MAX)
}
