/*******************************************************************************
	GLUE-Math Library: Riemann Zeta Function

	Author:
	  Haruhiko Okumura (Original Algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI Modify)
	License:
	  GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_RIEMANN_ZETA_DBL_INTERNAL
#define GML_RIEMANN_ZETA_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "pow.h"

static inline double ur_riemann_zeta(double);


static inline double
riemann_zeta_core(double x)
{
	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return x < 0 ? NAN : 1;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return -0.5;
		break;
	default:
		return ur_riemann_zeta(x);
		break;
	}
}

static inline double
ur_riemann_zeta(double x)
{
	static const int N = 8;
	static double coef[20] =
	{
		 8.333333333333333333333333333e-2,  /*  1/12 */
		-1.388888888888888888888888889e-3,  /* -1/720 */
		 3.306878306878306878306878307e-5,  /*  1/30240 */
		-8.267195767195767195767195767e-7,  /* -1/1209600 */
		 2.087675698786809897921009032e-8,  /*  1/47900160 */
		-5.284190138687493184847682202e-10,
		 1.338253653068467883282698098e-11,
		-3.389680296322582866830195391e-13,
		 8.586062056277844564135905450e-15,
		-2.174868698558061873041516424e-16,
		 5.509002828360229515202652609e-18,
		-1.395446468581252334070768626e-19,
		 3.534707039629467471693229977e-21,
		-8.953517427037546850402611251e-23,
		 2.267952452337683060310950058e-24,
		-5.744790668872202445263829503e-26,
		 1.455172475614864901866244572e-27,
		-3.685994940665310178130050728e-29,
		 9.336734257095044668660153106e-31,
		-2.365022415700629886484029550e-32
	};
	double powNx, w, z, zprev = 0;
	
	z = 1;
	for (volatile int i = 2; i < N; i++)
	{
		zprev = z;
		z += pow_core(i, -x);
		if (z == zprev)  return z;
	}
	powNx = pow_core(N, x);
	w = x / (N * powNx);
	z += 0.5 / powNx + N / ((x - 1) * powNx) + coef[0] * w;
	for (volatile int i = 1; i < 20 && z != zprev; i++)
	{
		w *= (x + 2 * i - 1) * (x + 2 * i) / (N * N);
		zprev = z;
		z += coef[i] * w;
	}
	return z;
}

#if defined(__cplusplus)
}
#endif

#endif
