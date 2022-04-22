/*******************************************************************************
	GLUE-Math Library: Poisson Distribution PMF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
******************************************************************************/
#include "dist.h"
#include "../internal/ur/poisspmf.h"

double
gml_poisspmf(int x, double lambda)
{
	return poisspmf_core(x, lambda);
}
