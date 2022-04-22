/*******************************************************************************
	GLUE-Math Library -- Chi-Square Distribution PDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Numerical Recipes in C; 3rd Edition
			by William H. Press,
			   Saul A. Teukolsky,
			   William T. Vetterling,
			   Brian P. Flannery
*******************************************************************************/
#include "dist.h"
#include "../tuning/spmax.h"
#include "../internal/ur/chisqpdf.h"
#include "../sys/float/huge_val_nan.h"

double
gml_chisqpdf(double z, double nu)
{
	if (nu < 1 || nu != nu)
		;
	else if (nu <= STAT_PARAM_MAX)
		return chisqpdf_core(z, (int)nu);
	return NAN;
}
