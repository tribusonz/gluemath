/*******************************************************************************
	Architecture -- Radix Complementation Method (float)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef RADIX_COMPLEMENTATION_METHOD_FLT_INTERNAL
#define RADIX_COMPLEMENTATION_METHOD_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Used Math Library: isnan(), isinf(), fabsf(), 
#include "foo.h"
#include "../../../sys/float/absolute.h"
#include "../../../sys/float/info.h"
#include "../primitive/float/info.h"
#include "../../../sys/float/fpclassify.h"
#include "../primitive/float/fpclassify.h"

// Radix Complementation Method
static inline float
rcm2f_core(register float x, int *exp)
{
	register int i, exp_val, have_sign;
	register float fra;
	//Radix table
	static const int radix_tab[5] = { 0, 1, 2, 4, 8 };
	//Resolution Table
	static const float reso_tab[5] =
		{
			1.0 / 2.0, 1.0 / 4.0, 1.0 / 16.0,
			1.0 / 256.0, 1.0 / 65536.0
		};
	
	if (isnan(x) || isinf(x))  { *exp = 0; return x; }
	if (x < 0)  { fra = rcm2f_core(x, exp); return -fra; } /* Recursive call. Recommend do not use */
	
	exp_val = 0;
	fra = fabsf(x);
	if (fra == 0.0) { *exp = 0; return 0; } /* Recommend do not use */
	else if (fra >=	1.0) { fra = foo(1 / fra); have_sign = 0; }
	else  have_sign = 1;
	for (;;) {
		// Binary search
		if (fra == 1.0) break; /* Exit the loop if the mantissa is equal to 1.0 */
		else if (reso_tab[0] <= fra)  i = 0;
		else if (reso_tab[1] <= fra)  i = 1;
		else if (reso_tab[2] <= fra)  i = 2;
		else if (reso_tab[3] <= fra)  i = 3;
		else if (reso_tab[4] <= fra)  i = 4;
		else                          i = 4;
		
		 // Exception when mantissa was 0.0 (i.e. exponent up 1)
		if (!have_sign && fra ==  reso_tab[0])  i++;
		exp_val += radix_tab[i]; // Add
		
		// If the complement factor is 0, exit the loop
		if (radix_tab[i] == 0)
		{
			fra = (!have_sign) ? foo(1 / fra) : foo(fra * 2);
			break;
		}
		foo(fra /= reso_tab[i-1]); // Weighting
	}
	
	
	if (have_sign) 	exp_val = ~exp_val;
	*exp = exp_val;
	return fra;
}

#if defined(__cplusplus)
}
#endif

#endif /* RADIX_COMPLEMENTATION_METHOD_FLT_INTERNAL */

