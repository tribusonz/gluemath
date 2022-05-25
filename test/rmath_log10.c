/*******************************************************************************
	GLUE-Math test suite: Common Logarithm
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>

int
main(void)
{
	rmath_title_print("Common Logarithm");

	rmath_calctest_title_print();

	rmath_polympatt_print("Real variable", "Complex solution");
	rmath_methname_print("log10(x)");
	listiter_tabname_print("(x)");
	for (int i = 0; i <= 20; i++)
	{
		const double x = i / 5.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 1, log10_r4(x), log10_r8(x),log10_re(x));
	}

	puts("");

	rmath_pole_title_print();

	rmath_check_pole1(log10_r4, log10_r8, log10_re);

	return 0;
}
