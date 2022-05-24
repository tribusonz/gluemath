/*******************************************************************************
	GLUE-Math test suite: Logarithm of Gamma Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	rmath_title_print("Logarithm of Euler Gamma Function");


	puts("Polymorphism Pattern: Real variable -> Complex solution (without Imaginary number)");
	rmath_methname_print("lgamma(x)");
	listiter_tabname_print("(x)");
	for (int i = -50; i <= 50; i += 2)
	{
		const double x = i / 10.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 1, lgamma_r4(x), lgamma_r8(x), lgamma_re(x));
	}

	return 0;
}

