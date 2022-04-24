/*******************************************************************************
	GLUE-Math primitive implementation: copysign

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/

#include "huge_val_nan.h"
#include "absolute.h"

#ifndef copysign
# define copysign copysign_core
static inline double
copysign_core(register double a, register double b)
{
	double absolute_value = a != a ? NAN : fabs(a);
	return b >= 0 ? absolute_value : -absolute_value;
}
#endif

#ifndef copysignl
# define copysignl copysignl_core
static inline long double
copysignl_core(register long double a, register long double b)
{
	long double absolute_value = a != a ? NAN : fabsl(a);
	return b >= 0 ? absolute_value : -absolute_value;
}
#endif

#ifndef copysignf
# define copysignf copysignf_core
static inline float
copysignf_core(float a, float b)
{
	float absolute_value = a != a ? NAN : fabsf(a);
	return b >= 0 ? absolute_value : -absolute_value;
}
#endif
