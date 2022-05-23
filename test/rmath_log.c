/*******************************************************************************
	GLUE-Math test routine: Natural Logarithm
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>

int
main(void)
{
	rmath_title_print("Natural Logarithm");

	puts("Polymorphism Pattern: Real variable -> Real solution");
	rmath_methname_print("log(x)");
	listiter_tabname_print("(x)");
	for (int i = 0; i <= 20; i++)
	{
		const double x = i / 5.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 1, log_r4(x), log_r8(x),log_re(x));
	}

	return 0;
}
