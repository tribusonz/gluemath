/*******************************************************************************
	GLUE-Math Library -- F Distribution CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_FCDF_INTERNAL
#define GML_FCDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "p_beta.h"


/* F 分布の下側確率 */
static inline double
ur_p_f(double f, int df1, int df2)
{
	if (f <= 0) return 0;
	return p_beta_core(df1 / (df1 + df2 / f), 0.5 * df1, 0.5 * df2);
}

/* F 分布の上側確率 */
static inline double
ur_q_f(double f, int df1, int df2)
{
	if (f <= 0) return 1;
	return p_beta_core(df2 / (df2 + df1 * f), 0.5 * df2, 0.5 * df1);
}

static inline double
fcdf_core(register double f, register int nu, register int mu)
{
	switch (fpclassify(f)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return f > 0 ? 1 : 0;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0;
		break;
	default:
		if (f < 0)  return 0;
		else if (nu <= 0 || mu <= 0)  return NAN;
		return ur_p_f(f, nu, mu);
		break;
	}
}

static inline double
fcdfc_core(register double f, register int nu, register int mu)
{
	switch (fpclassify(f)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return f > 0 ? 0 : 1;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 1;
		break;
	default:
		if (f < 0)  return 1;
		else if (nu <= 0 || mu <= 0)  return NAN;
		return ur_q_f(f, nu, mu);
		break;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_FCDF_INTERNAL */
