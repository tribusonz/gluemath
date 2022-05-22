/*******************************************************************************
	GLUE-Math test suite: Fraction and Exponent
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int
main(void)
{
	int exp;

	rmath_title_print("Fraction and Exponent");

	puts("x, frexp()");
	for (int i = 1; i <= 20; i++) {
		const double x = i / 5.0;  // Iterator Constant
		const double fra = frexp_r8(x, &exp);
		printf("%5.1f %3d %*.*f\n", x, exp, DBL_DIG + 3, DBL_DIG, fra);
	}
	puts("x, frexpl()");
	for (int i = 1; i <= 20; i++) {
		const long double x = i / 5.0L;  // Iterator Constant
		const long double fra = frexp_re(x, &exp);
		printf("%5.1Lf %3d %*.*Lf\n", x, exp, LDBL_DIG + 3, LDBL_DIG, fra);
	}
	puts("x, frexpf()");
	for (int i = 1; i <= 20; i++) {
		const float x = i / 5.0;  // Iterator Constant
		const float fra = frexp_r4(x, &exp);
		printf("%5.1f %3d %*.*f\n", x, exp, FLT_DIG + 3, FLT_DIG, fra);
	}
	return 0;
}
