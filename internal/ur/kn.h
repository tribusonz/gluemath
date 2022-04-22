/*******************************************************************************
	GLUE-Math Library: Modified Bessel Function (the 2nd kind)

	Author:
	  William H. Press (Original Algorithm)
	  Saul A. Teukolsky (Original Algorithm)
	  William T. Vetterling (Original Algorithm)
	  Brian P. Flannery (Original Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  Numerical Recipes in C; 3rd Edition
*******************************************************************************/
#ifndef GML_BESSEL_KN_DBL_INTERNAL
#define GML_BESSEL_KN_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "k0.h"
#include "k1.h"

static inline double ur_bessel_kn(int, double);


static inline double
kn_core(int n, double x)
{
#define odd(x)   ((x) & 1)            /* äÔêî? */
	if (x != x)
		return x;
	else if (x < 0)
		return NAN;
	else if (n < 0)
	{
        if (odd(n)) return -ur_bessel_kn(-n, x);
        /* else */  return  ur_bessel_kn(-n, x);
	}
	else
		return ur_bessel_kn(n, x);
#undef odd
}


static inline double
ur_bessel_kn(int n, double x)
{
	double bk, bkm, bkp, tox;
	if (n == 0)  return k0_core(x);
	if (n == 1) return k1_core(x);
	tox = 2.0 / x;
	bkm = k0_core(x); 
	bk = k1_core(x);
	for (volatile int j = 1; j < n; j++)
	{
		bkp = bkm + j * tox * bk;
		bkm = bk;
		bk = bkp;
	}
	return bk;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_BESSEL_KN_DBL_INTERNAL */
