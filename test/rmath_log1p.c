/*******************************************************************************
	GLUE-Math test routine: log1p()
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("log1p()");

	printf("  %3.3s   %-*.*s  %-*.*s  %-*.*s\n", "(x)",
	       FLT_DIG + 2, FLT_DIG + 2, "float",
	       DBL_DIG + 2, DBL_DIG + 2, "double",
	       LDBL_DIG + 2, LDBL_DIG + 2, "long double");
	for (int i = -10; i <= 10; i++) {
		const double x = i / 10.0;  // Iterator Constant
		printf("%5.1f  %*.*f %*.*f %*.*Lf\n",
		    x, FLT_DIG + 3, FLT_DIG, log1p_r4(x),
		    DBL_DIG + 3, DBL_DIG, log1p_r8(x),
		    LDBL_DIG + 3, LDBL_DIG, log1p_re(x));
	}
	return 0;
}
