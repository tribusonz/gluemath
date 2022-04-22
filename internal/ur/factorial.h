/*******************************************************************************
	GLUE-Math Library: Factorial Function

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_FACTORIAL_DBL_INTERNAL
#define GML_FACTORIAL_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

static inline double
factorial_core(register int n)
{

    if (n <= 0)  return 1.0;
    return (double)n * factorial_core(n - 1);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_FACTORIAL_DBL_INTERNAL */
