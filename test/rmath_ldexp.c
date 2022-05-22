/*******************************************************************************
	GLUE-Math test suite: Load Exponent
*******************************************************************************/
#include "../realmath/realmath.h"
#include "../sys/random/random.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>

int
main(void)
{
	init_genrand(time(NULL));
	
	rmath_title_print("Load Exponent");

	puts("for double:");
	for (volatile int i = 0; i < 5; i++)
	{
		const double frav = genrand_res53() * 2;
		const int    expv = genrand_int32() % 10;
		printf("exp:%2d fra: %*.*f = %g\n",
		       expv, DBL_DIG, DBL_DIG, frav, ldexp_r8(frav, expv));
	}
	puts("for long double:");
	for (volatile int i = 0; i < 5; i++)
	{
		const long double frav = (long double)genrand_res53() * 2;
		const int         expv = genrand_int32() % 10;
		printf("exp:%2d fra: %*.*Lf = %Lg\n",
		       expv, LDBL_DIG, LDBL_DIG, frav, ldexp_re(frav, expv));
	}
	puts("for float:");
	for (volatile int i = 0; i < 5; i++)
	{
		const float frav = (float)genrand_res53() * 2;
		const int   expv = genrand_int32() % 10;
		printf("exp:%2d fra: %*.*f = %g\n",
		       expv, FLT_DIG, FLT_DIG, frav, ldexp_r4(frav, expv));
	}
	return 0;
}
