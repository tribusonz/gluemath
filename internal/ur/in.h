/*******************************************************************************
	GLUE-Math Library: Modified Bessel Function (the 1st kind)

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
#ifndef GML_BESSEL_IN_DBL_INTERNAL
#define GML_BESSEL_IN_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

static inline double ur_bessel_in(int, double);

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/absolute.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "sqrt.h"
#include "frexp.h"
#include "ldexp.h"
#include "i0.h"
#include "i1.h"


static inline double
in_core(int n, double x)
{
	if (x != x)  return NAN;

	if (n < 0)  n = -n;

	return  ur_bessel_in(n, x);
}


static inline double
ur_bessel_in(int n, double x)
{
	static const double ACC = 200.0; 
	static int IEXP = 0;
	int j, k;
	double bi, bim, bip, dum, tox, ans;
	
	get_dbl_info();
	if (IEXP == 0)  IEXP = dbl_info.max_exp / 2;

	
	if (n == 0)  return i0_core(x);
	if (n == 1)  return i1_core(x);
	if (x * x <= 8.0 * dbl_info.min)  return 0.0;
	else
	{
		tox = 2.0 / fabs(x);
		bip = ans = 0.0;
		bi = 1.0;
		for (j = 2 * (n + (int)sqrt_core(ACC * n)); j > 0; j--)
		{
			bim = bip + j * tox * bi;
			bip = bi;
			bi = bim;
			dum = frexp_core(bi, &k);
			if (k > IEXP)
			{
				ans = ldexp_core(ans, -IEXP);
				bi = ldexp_core(bi, -IEXP);
				bip = ldexp_core(bip, -IEXP);
			}
			if (j == n)  ans = bip;
		}
		ans *= i0_core(x) / bi;
		return x < 0.0 && (n & 1) ? -ans : ans;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_BESSEL_IN_DBL_INTERNAL */
