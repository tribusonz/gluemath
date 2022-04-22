/*******************************************************************************
	GLUE-Math Library -- Student's t-Distribution CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_TCDF_INTERNAL
#define GML_TCDF_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "p_beta.h"


/* t 分布の下側確率 */
static inline double
ur_p_t(double t, int df)
{
	return 1 - 0.5 * p_beta_core(df / (df + t * t), 0.5 * df, 0.5);
}

/* t 分布の上側確率 */
static inline double
ur_q_t(double t, int df)
{
	return 0.5 * p_beta_core(df / (df + t * t), 0.5 * df, 0.5);
}


static inline double
tcdf_core(register double t, register int nu)
{
	switch (fpclassify(t)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return t > 0 ? 1 : 0;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0.5;
		break;
	default:
		if (nu <= 0)  return NAN;
		return ur_p_t(t, nu);
		break;
	}
}

static inline double
tcdfc_core(register double t, register int nu)
{
	switch (fpclassify(t)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return t > 0 ? 0 : 1;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0.5;
		break;
	default:
		if (nu <= 0)  return NAN;
		return ur_q_t(t, nu);
		break;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_TCDF_INTERNAL */
