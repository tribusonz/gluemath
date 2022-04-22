/*******************************************************************************
	GLUE-Math Library: IEEE-754 quietNaN Generators

*******************************************************************************/
#include "../internal/sys/arch/endianness.h"
#include "../internal/sys/ieee754/unionhack.h"
#include "../internal/sys/ieee754/binary_nan.h"
#include "../tuning/fenv.h"
/*******************************************************************************
MinGW 64bit gcc builds (Intel Core i7 64bit)

$ gcc -Wall -Wextra -O3 -mlong-double-64 -o bin/nan test/nan.c
----
float NaN: (workable)
double NaN: (workable)
long double NaN: (workable)
----

$ gcc -Wall -Wextra -O3 -mlong-double-80 -o bin/nan test/nan.c
----
float NaN: (workable)
double NaN: (workable)
long double NaN: (workable)
----

$ gcc -Wall -Wextra -O3 -mlong-double-128 -o bin/nan test/nan.c
----
float NaN: (workable)
double NaN: (workable)
long double NaN: (workable)
----

Build with -mlong-double-64 option in MinGW gcc, 
Segmentation fault occur when printf() refers to long double.
*******************************************************************************/

static float
qnan_binary32(void)
{
	static union uflt u = {0.0};
	if (u.f == 0.0)  u.i = 0x7ff80000;
	return u.f;
}

float
qnanf(void)
{
	check_flt_is_binary32();
	if (flt_is_binary32)
		return qnan_binary32();
	return 0.0/0.0;
}

static double
qnan_binary64(void)
{
	static union udbl u = {0.0};
	if (u.d == 0.0)  u.l = 0x7ff8000000000000;
	return u.d;
}

double
qnand(void)
{
	check_dbl_is_binary64();
	if (dbl_is_binary64)
		return qnan_binary64();
	return 0.0/0.0;
}

long double
qnanld(void)
{
	static union uldbl u = {0.0L};
	check_ldbl_type();
#if ldbl_type == 1
	if (u.ld == 0.0L)
	{
		switch (endian()) {
		case 1:
			// IEEE-754 binary64 little endian
			for (int i = 0; i < (int)sizeof(nan_binary64_le); i++)
				u.s[i] = nan_binary64_le[i];
			break;
		case 2:
			// IEEE-754 binary64 big endian
			for (int i = 0; i < (int)sizeof(nan_binary64_le); i++)
				u.s[i] = nan_binary64_be[i];
			break;
		default:
			u.ld = 0.0/0.0;
			break;
		}
	}
#elif ldbl_type == 2
	if (u.ld == 0.0L)
	{
		switch (endian()) {
		case 1:
			// IEEE-754 binary80 little endian
			for (int i = 0; i < (int)sizeof(nan_binary80_le); i++)
				u.s[i] = nan_binary80_le[i];
			break;
		case 2:
			// IEEE-754 binary80 big endian
			for (int i = 0; i < (int)sizeof(nan_binary80_le); i++)
				u.s[i] = nan_binary80_be[i];
			break;
		default:
			u.ld = 0.0/0.0;
			break;
		}
	}
#elif ldbl_type == 3
	if (u.ld == 0.0L)
	{
		switch (endian()) {
		case 1:
			// IEEE-754 binary128 little endian
			for (int i = 0; i < (int)sizeof(nan_binary128_le); i++)
				u.s[i] = nan_binary128_le[i];
			break;
		case 2:
			// IEEE-754 binary128 big endian
			for (int i = 0; i < (int)sizeof(nan_binary128_le); i++)
				u.s[i] = nan_binary128_be[i];
			break;
		default:
			u.ld = 0.0/0.0;
			break;
		}
	}
#else
	if (u.ld == 0.0L) u.ld = 0.L/0.L;
#endif
	return u.ld;
}

#include <stdio.h>

int
main(void)
{
	float fltnan;
	double dblnan;
	long double ldblnan;
	
	fltnan = qnanf();
	dblnan = qnand();
	ldblnan = qnanld();
	
	printf("float NaN: %s\n", fltnan != fltnan ? "(workable)" : "(not workable)");
	printf("double NaN: %s\n", dblnan != dblnan ? "(workable)" : "(not workable)");
	printf("long double NaN: %s\n", ldblnan != ldblnan ? "(workable)" : "(not workable)");
	return 0;
}
