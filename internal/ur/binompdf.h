/*******************************************************************************
	GLUE-Math Library: Binomial Distribution PDF
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
			ISBN978-4-7741-9690-9
		Handbook of Mathematical Functions
			Edited by Milton Abramowitz and Irene A. Stegun
		How to calculate binomial probabilities
			John D. Cook
*******************************************************************************/
#ifndef GML_BINOMPDF_INTERNAL
#define GML_BINOMPDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: exp(), log(), lgamma()
#include "exp.h"
#include "log.h"
#include "lgamma.h"

/* Binomial PMF, Log factorial Algorithm */
static inline double
binompmf_core(p, q, m, n)
register double p, q;
register int m, n;
{ 
	register double temp = lgamma_core(m + n + 1.0);
	temp -= lgamma_core(n + 1.0) + lgamma_core(m + 1.0);
	temp += m * log_core(p) + n * log_core(q);
	return exp_core(temp);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_BINOMPDF_INTERNAL */
