/*******************************************************************************
	Exponential Decomposition Formula:
		Radix Complementation Method (log10-Variant)
		Inverse of Radix Complementation Method

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef RADIX_COMPLEMENTATION_METHOD_VARIANT_LDBL_INTERNAL
#define RADIX_COMPLEMENTATION_METHOD_VARIANT_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

/* Interfaces */
// rcm log10 variant
static inline long double rcm10l_inline(long double, int *);
// Reciprocal of Radix Complementation Method to log(x) 0 < x < 1
static inline long double rcmrl(long double, int *);

// Used Math Library: isnan(), isinf(), fabsl(), 
#include "foo.h"
#include "../../../sys/float/absolute.h"
#include "../../../sys/float/info.h"
#include "../primitive/float/info.h"
#include "../../../sys/float/fpclassify.h"
#include "../primitive/float/fpclassify.h"

/* Radix Complementation Method (for Common Logarithm), log(x) 1.0 <= x < Inf */
static inline long double
rcm10l_inline(register long double x, int *exp)
{
	register long double fra;
	register int exp_val, i;
	//Complementaly Radix Table
	static const int radix_tab[5] = { 0, 1, 2, 4, 8 };
	//Resolution Table
	static const long double reso_tab[5] =
		{
			1.0e+01, 1.0e+02, 1.0e+04, 1.0e+08, 1.0e+16
		};
	i = 0; exp_val = 0;  fra = fabsl(x);
	
	if (fra == 0.0) { *exp = 0; return 0; } /* Recommend do not use */
	for (;;) {
		//Binary Search
		if (fra == 1.0)  break; /* Exit the loop if the mantissa is equal to 1.0 */
		else if (reso_tab[0] >= fra)  i = 0;
		else if (reso_tab[1] >= fra)  i = 1;
		else if (reso_tab[2] >= fra)  i = 2;
		else if (reso_tab[3] >= fra)  i = 3;
		else if (reso_tab[4] >= fra)  i = 4;
		else                          i = 4;

		 // Exception when mantissa was 0.0 (i.e. exponent up 1)
		if (x ==  reso_tab[0])
			i++;
		
		exp_val += radix_tab[i]; // Add
		
		// If the complement factor is 0, exit the loop
		if (radix_tab[i] == 0)
			break;
		
		fool(fra /= reso_tab[i-1]); // Weighting
	}
	*exp = exp_val;
	return fra;
}

/*
 * Reciprocal of Radix Complementation Method, log(x) 0 < x < 1
 */
static inline long double
rcmrl(register long double x, int *exp)
{
	register int i, exp_val;
	register long double fra, prev;
	//Complementaly Inverse of Radix Table.
	static const int radix_tab[4] = { 100, 10, 1, 0 };
	//Decomposition Rate Table
	static const long double rate_tab[4] =
		{
			1.0e+100, 1.0e+10, 1.0e+1, 0.0e+0
		};
	i = 0; exp_val = 0; fra = x; prev = 0.0;
	for (;;)
	{
		prev = fool(fra * rate_tab[i]);
		if (prev >= 1.0)
			i += 1; // Change the decomposition rate
		// If the decomposition rate reaches outside the calculation area, exit the loop
		else if (prev == 0.0)
			break;
		else
			{ exp_val += radix_tab[i]; fra = prev; } // Add & Weighting
	}
	fra = fool(fra * 10.0); //Finally, weight to normalize to 1.0 <= x < 10.0
	*exp = ~exp_val;
	return fra;
}

// Main routine of rcm log10 variant
static inline long double
rcm10l_core(register long double x, int *exp)
{
	register long double fra = 0.L;
	if (isnan(x) || isinf(x))  { *exp = 0; return x; }
	else if (x < 0.0)
	// Note: 
	// Recursive call. recommend do not use.
	{
		fra = rcm10l_core(-x, exp);
		return -fra;
	}
	else if (x == 0.0)
	// recommend do not use.
	{
		*exp = 0;
		return 0.L;
	}
	else if (x >= 1.0)
		fra = rcm10l_inline(x, exp);
	else if (x < 1.0)
		fra = rcmrl(x, exp);
	return fra;
}

#if defined(__cplusplus)
}
#endif

#endif /* RADIX_COMPLEMENTATION_METHOD_VARIANT_LDBL_INTERNAL */
