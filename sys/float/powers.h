/*******************************************************************************
	GLUE-Math primitive implementation: FP powers

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/

// Implementation for Python: __pow__(self, other)

#ifndef pow
# define pow gml_pow
# include "../../internal/ur/pow.h"
static inline double
gml_pow(double x, double y)
{
	return pow_core(x, y);
}
#endif

#ifndef powf
# define powf gml_powf
# include "../../internal/ur/powf.h"
static inline float
gml_powf(float x, float y)
{
	return powf_core(x, y);
}
#endif

#ifndef powl
# define powl gml_powl
# include "../../internal/ur/powl.h"
static inline long double
gml_powl(long double x, long double y)
{
	return powl_core(x, y);
}
#endif
