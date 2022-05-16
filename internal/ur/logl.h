/*******************************************************************************
	GLUE-Math Library -- Natural Logarithm (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Programming in Oberon Tutorial
			- Niklaus Wirth and his team
*******************************************************************************/
#ifndef GML_LOG_LDBL_INTERNAL
#define GML_LOG_LDBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// Use library: fpclassify(), HUGE_VALL, NAN
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "../../sys/float/fpclassify.h"
#include "../sys/primitive/float/fpclassify.h"
#include "../sys/arch/rcm2l.h"
#include "logxtl.h"
#include "m_log2.h"

static inline long double
logl_core(register long double x)
{
	register long double fra;
	int exp_val;
	static long double m_log2 = 0;
	if (m_log2 == 0)  m_log2 = m_log2_ld();
	
	switch (fpclassify(x)) {
	case FP_NAN:
		break;
	case FP_INFINITE:
		if (x > 0)  return HUGE_VALL;
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return -HUGE_VALL;
		break;
	case FP_NORMAL:
		if (x > 0)
		{
			fra = rcm2l_core(x, &exp_val);
			return (exp_val + logxtl(fra, 2)) * m_log2;
		}
		break;
	default:
		break;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_LOG_LDBL_INTERNAL */
