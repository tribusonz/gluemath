/*******************************************************************************
	GLUE-Math Library -- Binomial Distribution CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "dist.h"
#include "../tuning/spmax.h"
#include "../internal/ur/binomcdf.h"
#include "../sys/float/huge_val_nan.h"

double
gml_binomcdf(double k, int nu, double phi)
{
	if (nu < 1 || phi != phi || k != k)
		;
	else if (k >= nu || k > STAT_PARAM_MAX || nu > STAT_PARAM_MAX)
		return 1;
	else
		return binomcdf_core(k, nu, phi);
	return NAN;
}
