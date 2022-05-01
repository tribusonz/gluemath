/*******************************************************************************
	GLUE-Math Library: Sine Integral

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
********************************************************************************
	${\rm Si}(x) = \int_{0}^{x} \frac{\sin t}{t} \, dt$
	 x      Si(x)
	 1   0.94608307036718301494
	 2   1.60541297680269484858
	 3   1.84865252799946825640
	 4   1.75820313894905305811
	 5   1.54993124494467413727
	10   1.65834759421887404933
	20   1.54824170104343984016
	30   1.56675654003035111098
	40   1.58698511935478450678
	50   1.55161707248593589473
	\infty   \pi/2
*******************************************************************************/
#ifndef GML_SINE_INTEGRAL_INTERNAL
#define GML_SINE_INTEGRAL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#if 0
# include <stdio.h>
#endif

//uses math library: sin(), cos()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "sin.h"
#include "cos.h"

/* 級数展開 */
static inline double
ur_Si_series(double x)
{
	int k;
	double s, t, u;

	s = t = x;  x = - x * x;
	for (k = 3; k < 1000; k += 2) {
		t *= x / ((k - 1) * k);
		u = s;  s += t / k;
		if (s == u) return s;
	}
#if 0
	printf("Si_series(): 収束しません.\n");
	return s;
#else
	return 0.0;
#endif
}

/* 漸近展開 */
static inline double
ur_Si_asympt(register double x)
{
	register int k, flag;
	register double t, f, g, fmax, fmin, gmax, gmin;
	static const double PI = 3.14159265358979323846264338328;

	fmax = gmax = 2;  fmin = gmin = 0;
	f = g = 0;  t = 1 / x;
	k = flag = 0;
	while (flag != 15) {
		f += t;  t *= ++k / x;
		if (f < fmax) fmax = f;  else flag |= 1;
		g += t;  t *= ++k / x;
		if (g < gmax) gmax = g;  else flag |= 2;
		f -= t;  t *= ++k / x;
		if (f > fmin) fmin = f;  else flag |= 4;
		g -= t;  t *= ++k / x;
		if (g > gmin) gmin = g;  else flag |= 8;
	}
	return 0.5 * (PI - (fmax + fmin) * cos_core(x)
	                 - (gmax + gmin) * sin_core(x));
}

static inline double
si_core(register double x)
{
	static const double PI = 3.14159265358979323846264338328;
	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return x < 0 ? -PI / 2 : PI / 2;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0;
		break;
	default:
		if (x <  0) return -si_core(-x);
		if (x < 18) return ur_Si_series(x);
		return             ur_Si_asympt(x);
		break;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_SINE_INTEGRAL_INTERNAL */
