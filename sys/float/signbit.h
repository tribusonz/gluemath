/*******************************************************************************
	Floating Point Arithmetic -- Macro of signbit()

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/

#ifndef signbit
# define signbit(x) \
    (sizeof (x) == sizeof (long double) ? signbit_ld (x) \
     : sizeof (x) == sizeof (double) ? signbit_d (x) \
     : signbit_f (x))
static inline int __signbit_f (float        x) { return x * -1 > 0; }
static inline int __signbit_d (double       x) { return x * -1 > 0; }
static inline int   signbit_ld(long double  x) { return x * -1 > 0; }

#include "../../tuning/fenv.h"


#include "../../internal/sys/ieee754/signbit_b32.h"

static inline int
signbit_f(float x)
{
	static int check = 0;
	static int(*p_func)(float) = __signbit_f;
	if (check == 0)
	{
		check_flt_is_binary32();
		if (flt_is_binary32)
			p_func = signbit_b32_core;
		check = 1;
	}
	return p_func(x);
}

#include "../../internal/sys/ieee754/signbit_b64.h"

static inline int
signbit_d(double x)
{
	static int check = 0;
	static int(*p_func)(double) = __signbit_d;
	if (check == 0)
	{
		check_dbl_is_binary64();
		if (dbl_is_binary64)
			p_func = signbit_b64_core;
		check = 1;
	}
	return p_func(x);
}

#endif


