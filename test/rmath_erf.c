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

	rmath_calctest_title_print();

	rmath_polympatt_print("Real variable", "Real solution");
	rmath_methname_print("erf(x)");
	listiter_tabname_print("(x)");
	for (int i = -60; i <= 60; i += 5)
	{
		const double x = i / 10.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 1, erf_r4(x), erf_r8(x), erf_re(x));
	}
	puts("");
	rmath_pole_title_print();
	rmath_check_pole1(erf_r4, erf_r8, erf_re);

	return 0;
}
