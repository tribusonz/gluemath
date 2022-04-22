/*******************************************************************************
	RNG -- Binomial Distribution

	Authors:
	  Barry Brown, James Lovato (Original FORTRAN77 version)
	  John Burkardt (C version, Modify)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License:
	  GPL + X11(MIT) (Part of modified)
	  John Burkardt's (Original source)
	Reference:
	  John Burkardt's Home Page
*******************************************************************************/
#include "dist.h"
#include "../internal/ur/binomrng.h"
#include "../tuning/spmax.h"

int
gml_binomrng(int nu, double phi)
{
	int v;
	v = binomrng_core(nu, phi);
	return v > STAT_PARAM_MAX ? STAT_PARAM_MAX : v; // fmin(v, STAT_PARAM_MAX)
}
