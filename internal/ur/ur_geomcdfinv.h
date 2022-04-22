/*******************************************************************************
	GLUE-Math Library: Geometric Distribution Inverse CDF

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Simulation and Statistical Programming Hilary Term 2020
		- Robert Davies
		- Anthony Caterini, Bobby He, Sheheryar Zaidi
		- Alan (Siu Chau)
		(University of Oxford)
*******************************************************************************/
#ifndef GML_UR_GEOMCDFINV_INTERNAL
#define GML_UR_GEOMCDFINV_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

// uses math library: round(), log()
#include "../../sys/float/huge_val_nan.h"
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "round.h"
#include "log.h"

static inline double
ur_geomcdfinv(register double u, register double q)
{
	register double x;
	get_dbl_info();
	if (u >= 0 && u <= 1 && q >= 0 && q <= 1)
	{
		if (q == 1)
			return u < dbl_info.min ? 0 : HUGE_VAL;
		x = round_core(log_core(1-u)/log_core(1-q));
		return x <= 0 ? 0 : x;
	}
	return NAN;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_UR_GEOMCDFINV_INTERNAL */
