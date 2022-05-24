/*******************************************************************************
	GLUE-Math test suite: Gamma Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>


int
main(void)
{
	rmath_title_print("Euler Gamma Function");

	puts("Polymorphism Pattern: Real variable -> Real solution");
	rmath_methname_print("gamma(x)");
	listiter_tabname_print("(x)");
	for (int i = -50; i <= 50; i += 2)
	{
		const double x = i / 10.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 1, gamma_r4(x), gamma_r8(x), gamma_re(x));
	}

	return 0;
}
