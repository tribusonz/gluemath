/*******************************************************************************
	GLUE-Math Library: Cosine Integral

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
********************************************************************************
	${\rm Ci}(x) = \gamma + \log x
	  + \int_{0}^{x} \frac{\cos t - 1}{t} \, dt$
	 x      Ci(x)
	 1   0.33740392290096813466
	 2   0.42298082877486499570
	 3   0.11962978600800032763
	 4  -0.14098169788693041164
	 5  -0.19002974965664387862
	10  -0.045456433004455372635
	20   0.044419820845353316540
	30  -0.033032417282071143779
	40   0.019020007896208766962
	50  -0.0056283863241163054402
*******************************************************************************/
#ifndef GML_COSINE_INTEGRAL_INTERNAL
#define GML_COSINE_INTEGRAL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#if 0
# include <stdio.h>
#endif

// uses math library: log(), sin(), cos()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "log.h"
#include "sin.h"
#include "cos.h"

/* ãâêîìWäJ */
static inline double
ur_Ci_series(register double x)
{
	register int k;
	register double s, t, u;
	/* EulerÇÃíËêî $\gamma$ */
	const double EULER  = 0.577215664901532860606512090082;

	s = EULER + log_core(x);
	x = - x * x;  t = 1;
	for (k = 2; k < 1000; k += 2) {
		t *= x / ((k - 1) * k);
		u = s;  s += t / k;
		if (s == u) return s;
	}
#if 0
	printf("Si_series(): é˚ë©ÇµÇ‹ÇπÇÒ.\n");
	return s;
#else
	return 0.0;
#endif
}

/* ëQãﬂìWäJ */
static inline double
ur_Ci_asympt(register double x)
{
	register int k, flag;
	register double t, f, g, fmax, fmin, gmax, gmin;

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
	return 0.5 * ((fmax + fmin) * sin_core(x)
	            - (gmax + gmin) * cos_core(x));
}

static inline double
ci_core(register double x)
{
	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return 0;  // Ci(-Infinity) = (0.0+PI*i), Ci(Infinity) = 0
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return -HUGE_VAL;
		break;
	default:
		if (x <  0) return ci_core(-x);
		if (x < 18) return ur_Ci_series(x);
		return             ur_Ci_asympt(x);
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_COSINE_INTEGRAL_INTERNAL */
