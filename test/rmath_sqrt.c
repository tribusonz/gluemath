/*******************************************************************************
	GLUE-Math test suite: Square Root
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Square Root");

	printf("  %3.3s   %-*.*s  %-*.*s  %-*.*s\n", "(x)",
	       FLT_DIG + 2, FLT_DIG + 2, "float",
	       DBL_DIG + 2, DBL_DIG + 2, "double",
	       LDBL_DIG + 2, LDBL_DIG + 2, "long double");
	for (volatile int i = 0; i <= 20; i++)
		printf("  % 3d  % *.*f % *.*f % *.*Lf\n", i,
			FLT_DIG, FLT_DIG, sqrt_r4(i), 
		    DBL_DIG, DBL_DIG, sqrt_r8(i),
		    LDBL_DIG, LDBL_DIG, sqrt_re(i));
	return 0;
}
