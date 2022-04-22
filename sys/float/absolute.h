/*******************************************************************************
	GLUE-Math primitive implementation: FP absolute

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/

#ifndef fabs
# define fabs(x) gml_fabs(x)
static inline double
gml_fabs(register double x)
{
	if (x != x)  return x;
	return x * -1 > 0 ? -x : x;
}
#endif

#ifndef fabsf
# define fabsf(x) gml_fabsf(x)
static inline float
gml_fabsf(register float x)
{
	if (x != x)  return x;
	return x * -1 > 0 ? -x : x;
}
#endif

#ifndef fabsl
# define fabsl(x) gml_fabsl(x)
static inline long double
gml_fabsl(register long double x)
{
	if (x != x)  return x;
	return x * -1 > 0 ? -x : x;
}
#endif
