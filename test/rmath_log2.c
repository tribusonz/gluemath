/*******************************************************************************
	GLUE-Math test suite: Binary Logarithm
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>

int
main(void)
{
	rmath_title_print("Binary Logarithm");

	puts("Polymorphism Pattern: Real variable -> Real solution");
	rmath_methname_print("log2(x)");
	listiter_tabname_print("(x)");
	for (int i = 0; i <= 20; i++)
	{
		const double x = i / 5.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 1, log2_r4(x), log2_r8(x),log2_re(x));
	}

	return 0;
}
