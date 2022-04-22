/*******************************************************************************
	GLUE-Math Library -- Chi-Square Distribution CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "dist.h"
#include "../tuning/spmax.h"
#include "../internal/ur/chisqcdfc_int.h"
#include "../internal/ur/chisqcdf.h"
#include "../sys/float/huge_val_nan.h"

double
gml_chisqcdf(double z, double nu)
{
	if (nu < 1 || nu != nu)
		;
	else if (nu < 100) // Integer DF routine
		return z > 0 ? 1 - chisqcdfc_int_core(z, (int)nu) : z != z ? z : 0;
	else if (nu <= STAT_PARAM_MAX) // Incomplete Gamma routine
		return chisqcdf_core(z, (int)nu);
	return NAN;
}
