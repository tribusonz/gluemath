/*******************************************************************************
	GLUE-Math Library -- Binomial Distribution CDF

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_BINOMCDF_INTERNAL
#define GML_BINOMCDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "p_beta.h"
#include "floor.h"

/* 2項分布 B(n,p) の X <= k の確率 */
static inline double
ur_p_binomial(double k, int n, double p)
{
	if (k != k)       return k;
	else if (k <  0)  return 0;
	else if (k >= n)  return 1;
	k = floor_core(k);
	return p_beta_core(1 - p, n - k, k + 1);
}

/* 2項分布 B(n,p) の X >= k の確率 */
static inline double
ur_q_binomial(double k, int n, double p)
{
	if (k != k)      return k;
	else if (k <= 0) return 1;
	else if (k >  n) return 0;
	k = floor_core(k);
	return p_beta_core(p, k, n - k + 1);
}

static inline double
binomcdf_core(double k, int n, double p)
{
	if (p >= 0 && p <= 1)
		return ur_p_binomial(k, n, p);
	return NAN;
}

static inline double
binomcdfc_core(double k, int n, double p)
{
	if (p >= 0 && p <= 1)
		return ur_q_binomial(k, n, p);
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_BINOMCDF_INTERNAL */
