/*******************************************************************************
	GLUE-Math Library -- Student's t-Distribution CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "dist.h"
#include "../tuning/spmax.h"
#include "../internal/ur/tcdf_int.h"
#include "../internal/ur/tcdf.h"
#include "../sys/float/huge_val_nan.h"

double
gml_tcdfc(double t, double nu)
{
	if (nu < 1 || nu != nu || t != t)
		;
	else if (nu < 100) // Integer DF routine
		return 1 - tcdf_int_core(t, (int)nu);
	else if (nu <= STAT_PARAM_MAX) // Incomplete Beta routine
		return tcdfc_core(t, (int)nu);
	return NAN;
}
