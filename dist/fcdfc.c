/*******************************************************************************
	GLUE-Math Library -- F Distribution CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "dist.h"
#include "../tuning/spmax.h"
#include "../internal/ur/fcdfc_int.h"
#include "../internal/ur/fcdf.h"
#include "../sys/float/huge_val_nan.h"

double
gml_fcdfc(double f, double nu, double mu)
{
	if (nu < 1 || nu != nu || mu < 1 || mu != mu)
		;
	else if (nu < 100 && mu < 100) // Integer DF routine
		return f > 0 ? fcdfc_int_core(f, (int)nu, (int)mu) : f != f ? f : 1;
	else if (nu <= STAT_PARAM_MAX && mu <= STAT_PARAM_MAX) // Incomplete Beta routine
		return fcdfc_core(f, (int)nu, (int)mu);
	return NAN;
}
