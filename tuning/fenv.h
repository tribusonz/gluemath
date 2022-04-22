/*******************************************************************************
	GLUE-Math Tuning: Power calculation mode

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_TUNING_CHECK_IEEE754
#define GML_TUNING_CHECK_IEEE754

#if defined(__cplusplus)
extern "C" {
#endif

#include "../sys/float/info.h"
#include "../internal/sys/primitive/float/info.h"

static int flt_is_binary32 = 0;
static int dbl_is_binary64 = 0;
static int ldbl_type = 0;

static inline void
check_flt_is_binary32(void)
{
	static int check = 0;
	if (check == 0)
	{
		get_flt_info();
		flt_is_binary32 = (
			flt_info.radix == 2 &&
			flt_info.mant_dig == 24 &&
			flt_info.min_exp  == -125 &&
			flt_info.max_exp == 128
		);
		check = 1;
	}
}

static inline void
check_dbl_is_binary64(void)
{
	static int check = 0;
	if (check == 0)
	{
		get_dbl_info();
		dbl_is_binary64 = (
			dbl_info.radix == 2 &&
			dbl_info.mant_dig == 53 &&
			dbl_info.min_exp == -1021 &&
			dbl_info.max_exp == 1024
		);
		check = 1;
	}
}

static inline void
check_ldbl_type(void)
{
	static int check = 0;
	if (check == 0)
	{
		get_ldbl_info();
		if (
			ldbl_info.radix == 2 &&
			ldbl_info.mant_dig == 53 &&
			ldbl_info.min_exp == -1021 &&
			ldbl_info.max_exp == 1024
		)
			ldbl_type = 1; // binary64
		else if (
			ldbl_info.radix == 2 &&
			ldbl_info.mant_dig == 64 &&
			ldbl_info.min_exp == -16381 &&
			ldbl_info.max_exp == 16384
		)
			ldbl_type = 2; // binary80
		else if (
			ldbl_info.radix == 2 &&
			ldbl_info.mant_dig == 113 &&
			ldbl_info.min_exp == -16381 &&
			ldbl_info.max_exp == 16384
		)
			ldbl_type = 3; // binary128
		check = 1;
	}
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_TUNING_CHECK_IEEE754 */
