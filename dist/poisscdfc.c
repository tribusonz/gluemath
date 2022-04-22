/*******************************************************************************
	GLUE-Math Library: Poisson Distribution CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
******************************************************************************/
#include "dist.h"
#include "../internal/ur/poisscdfc.h"

double
gml_poisscdfc(double x, double lambda)
{
	return poisscdfc_core(x, lambda);
}
