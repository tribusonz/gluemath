/*******************************************************************************
	GLUE-Math Library: Binomial Distribution PDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
			ISBN978-4-7741-9690-9
		Handbook of Mathematical Functions
			Edited by Milton Abramowitz and Irene A. Stegun
		How to calculate binomial probabilities
			John D. Cook
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/binompdf.h"
#include "../sys/float/huge_val_nan.h"
#include "../tuning/spmax.h"

/* Entity */
double
gml_binompmf(int x, int n, double p)
{
	if (x > STAT_PARAM_MAX || n > STAT_PARAM_MAX || x < 0 || x > n)
	    return 0.0;
	if (p < 0.0 || p > 1.0)
		return NAN;
	return binompmf_core(p, 1-p, x, n-x);
}
