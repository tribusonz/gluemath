/*******************************************************************************
	GLUE-Math test suite: Gaussian Error Function
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Gaussian Error Function");

	puts("Polymorphism Pattern: Real variable -> Real solution");
	rmath_methname_print("erf(x)");
	listiter_tabname_print("(x)");
	for (int i = -60; i <= 60; i += 5)
	{
		const double x = i / 10.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 1, erf_r4(x), erf_r8(x), erf_re(x));
	}
	puts("");
	rmath_pole_title_print();
	puts("float:");
	printf("erf(Infinity) = %s\n", flt_inspect_g(erf_r4(HUGE_VALF), UNARY_AUTO));
	printf("erf(-Infinity) = %s\n", flt_inspect_g(erf_r4(-HUGE_VALF), UNARY_AUTO));
	printf("erf(NaN) = %s\n", flt_inspect_g(erf_r4(NAN), UNARY_AUTO));
	puts("double:");
	printf("erf(Infinity) = %s\n", dbl_inspect_g(erf_r8(HUGE_VAL), UNARY_AUTO));
	printf("erf(-Infinity) = %s\n", dbl_inspect_g(erf_r8(-HUGE_VAL), UNARY_AUTO));
	printf("erf(NaN) = %s\n", dbl_inspect_g(erf_r8(NAN), UNARY_AUTO));
	puts("long double:");
	printf("erf(Infinity) = %s\n", ldbl_inspect_g(erf_re(HUGE_VALL), UNARY_AUTO));
	printf("erf(-Infinity) = %s\n", ldbl_inspect_g(erf_re(-HUGE_VALL), UNARY_AUTO));
	printf("erf(NaN) = %s\n", ldbl_inspect_g(erf_re(NAN), UNARY_AUTO));
	
	return 0;
}
