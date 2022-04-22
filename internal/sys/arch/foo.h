/*******************************************************************************
	Architecture -- Optimization Obstruct
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	
	Reference:
		C gengo ni yoru Hyoujun Algorithm Jiten (Japanese)
		Handbook of the Standard Algorithms in C
		- Haruhiko Okumura
*******************************************************************************/
#ifndef OPTIMIZATION_OBSTRUCT_INTERNAL
#define OPTIMIZATION_OBSTRUCT_INTERNAL

#if defined(__cplusplus)
extern "C"{
#endif

// Obstructs for FP optimazation ;P
static inline float
foof(float x)
{
	return x;
}

static inline double
foo(double x)
{
	return x;
}

static inline long double
fool(long double x)
{
	return x;
}

#if defined(__cplusplus)
}
#endif

#endif /* OPTIMIZATION_OBSTRUCT_INTERNAL */
