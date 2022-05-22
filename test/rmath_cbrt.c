/*******************************************************************************
	GLUE-Math test suite: Cubic Root
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Cubic Root");

	printf("  %3.3s   %-*.*s  %-*.*s  %-*.*s\n", "(x)",
	       FLT_DIG + 2, FLT_DIG + 2, "float",
	       DBL_DIG + 2, DBL_DIG + 2, "double",
	       LDBL_DIG + 2, LDBL_DIG + 2, "long double");
	for (volatile int i = -20; i <= 20; i++)
		printf("  % 3d  % *.*f % *.*f % *.*Lf\n", i,
		    FLT_DIG, FLT_DIG, cbrt_r4(i),
		    DBL_DIG, DBL_DIG, cbrt_r8(i),
		    LDBL_DIG, LDBL_DIG, cbrt_re(i));

	return 0;
}
