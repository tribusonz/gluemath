/*******************************************************************************
	GLUE-Math Library: Binomial Distribution Inverse CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Efficient evaluation of the inverse Binomial
		cumulative distribution function where the
		number of trials is large
			by Sean Moorhead
******************************************************************************/
#include "dist.h"
#include "../internal/ur/binomcdfinv.h"
#include "../tuning/spmax.h"
#include "../sys/float/huge_val_nan.h"

double
gml_binomcdfinv(double q, int nu, double phi)
{
	if (nu > STAT_PARAM_MAX)  return NAN;
	return binomcdfinv_core(q, nu, phi);
}
