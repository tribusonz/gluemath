/*******************************************************************************
	GLUE-Math primitive implementation: FP modulo

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/

// Implementation for Python: __mod__(self, other)

#ifndef fmod
# define fmod gml_fmod
# include "../../internal/ur/fmod.h"
static inline double
gml_fmod(double x, double y)
{
	return fmod_core(x, y);
}
#endif

#ifndef fmodf
# define fmodf gml_fmodf
# include "../../internal/ur/fmodf.h"
static inline float
gml_fmodf(float x, float y)
{
	return fmodf_core(x, y);
}
#endif

#ifndef fmodl
# define fmodl gml_fmodl
# include "../../internal/ur/fmodl.h"
static inline long double
gml_fmodl(long double x, long double y)
{
	return fmodl_core(x, y);
}
#endif
