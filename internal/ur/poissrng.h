/*******************************************************************************
	GLUE-Math Library: R.N.G. -- Poisson Distribution

	Author: Hironobu Iatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_RNG_POISS_INTERNAL
#define GML_RNG_POISS_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "exp.h"
#include "uniform.h"
#include "poisscdfinv.h"

static inline int poissrng1(double);

/* Poisson (ポアソン) 分布 */
static inline int
poissrng_core(double lambda)
{
	double v;
	get_dbl_info();
	if (lambda != lambda || lambda < dbl_info.min)
		return 0;
	else if (lambda < 30.0)
		return poissrng1(lambda);
	/* else */
	v = poisscdfinv_core(uniform_core(), lambda);
	if isnan(v)  return 0;
	return (int)v;
}

static inline int
poissrng1(double lambda)
{
    int k;
	if (isinf(lambda = exp_core(lambda)))
		lambda = dbl_info.max;
    lambda *= uniform_core();
    k = 0;
    while (lambda > 1)
    	{ lambda *= uniform_core();  k++; }
    return k;
}

#if 0
// Knuth's Algorithm, for lambda <= 30.0
static inline int
poissrng1(double lambda)
{
	const double L = exp_core(-lambda);
	int k = 0;
	double p = 1.0;

	do {
		k++;
		p = p * uniform_core();
	} while (p > L);

	return k - 1;
}
#endif


#if defined(__cplusplus)
}
#endif

#endif /* GML_RNG_POISS_INTERNAL */
