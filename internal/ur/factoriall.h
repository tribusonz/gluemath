/*******************************************************************************
	GLUE-Math Library: Factorial Function (long double)

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_FACTORIAL_LDBL_INTERNAL
#define GML_FACTORIAL_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

static inline long double
factoriall_core(register int n)
{

    if (n <= 0)  return 1.0;
    return (long double)n * factoriall_core(n - 1);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_FACTORIAL_LDBL_INTERNAL */
