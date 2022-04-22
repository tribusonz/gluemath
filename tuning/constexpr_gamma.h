/*******************************************************************************
	GLUE-Math Tuning: Constant-Expression of Gamma Function

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_CONSTEXPR_GAMMA
#define GML_CONSTEXPR_GAMMA
#if defined(__cplusplus)
extern "C" {
#endif

#include "constexpr_exp.h"
#include "../internal/ur/logfactorial.h"

/* Constant Expressions for exponent. Use in compiler */

// for gamma
// double
static inline void get_gamma_const(void);
static int gamma_max = 0;
static int gamma_const_init_pragma = 0;
// long double
static inline void get_gammal_const(void);
static int gammal_max =  0;
static int gammal_const_init_pragma = 0;
// float
static inline void get_gammaf_const(void);
static int gammaf_max =  0;
static int gammaf_const_init_pragma = 0;

// Entity
static inline void
get_gamma_const(void)
{
	if (gamma_const_init_pragma == 0)
	{
		get_exp_const();
		for (volatile int i = 0; i < 10000; i++)
		{
			if (exp_max < logfactorial_core(i))  break;
			gamma_max++;
		}
		gamma_const_init_pragma = 1;
	}
}

static inline void
get_gammal_const(void)
{
	if (gammal_const_init_pragma == 0)
	{
		get_expl_const();
		for (volatile int i = 0; i < 10000; i++)
		{
			if (expl_max < logfactorial_core(i))  break;
			gammal_max++;
		}
		gammal_const_init_pragma = 1;
	}
}

static inline void
get_gammaf_const(void)
{
	if (gammaf_const_init_pragma == 0)
	{
		get_expf_const();
		for (volatile int i = 0; i < 10000; i++)
		{
			if (expf_max < logfactorial_core(i))  break;
			gammaf_max++;
		}
		gammaf_const_init_pragma = 1;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CONSTEXPR_GAMMA */
