/*******************************************************************************
	GLUE-Math primitive implementation: copysign

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/

#ifndef copysign
# define copysign copysign_core
static inline double
copysign_core(register double a, register double b)
{
	if (a != a || b != b)  return b;
	return a * -1 < 0 ? b * -1 < 0 ? b : -b : b * -1 < 0 ? -b : b;
}
#endif

#ifndef copysignl
# define copysignl copysignl_core
static inline long double
copysignl_core(register long double a, register long double b)
{
	if (a != a || b != b)  return b;
	return a * -1 < 0 ? b * -1 < 0 ? b : -b : b * -1 < 0 ? -b : b;
}
#endif

#ifndef copysignf
# define copysignf copysignf_core
static inline float
copysignf_core(float a, float b)
{
	if (a != a || b != b)  return b;
	return a * -1 < 0 ? b * -1 < 0 ? b : -b : b * -1 < 0 ? -b : b;
}
#endif
