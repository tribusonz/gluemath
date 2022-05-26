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

	puts("  This function is not as the cube root sqrt3(x),");
	puts("  returns the solution in the form of x^1/3.");
	puts("");

	rmath_calctest_title_print();

	rmath_polympatt_print("Real variable", "Real solution");
	rmath_methname_print("cbrt(x)");
	listiter_tabname_print("(x)");
	for (int i = -20; i <= 20; i++)
	{
		const double x = i / 5.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 1, cbrt_r4(x), cbrt_r8(x), cbrt_re(x));
	}

	puts("");

	rmath_pole_title_print();

	rmath_check_pole1(cbrt_r4, cbrt_r8, cbrt_re);

	return 0;
}
