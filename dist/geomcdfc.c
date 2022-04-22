/*******************************************************************************
	GLUE-Math Library: Geometric Distribution CDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
******************************************************************************/
#include "dist.h"
#include "../internal/ur/geomcdf.h"

double
gml_geomcdfc(double x, double phi)
{
	return 1 - geomcdf_core(x, phi);
}
