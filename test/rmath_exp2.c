/*******************************************************************************
	GLUE-Math test suite: Binary Exponent
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Binary Exponent");

	puts("Polymorphism Pattern: Real variable -> Real solution");
	rmath_methname_print("exp2(x)");
	listiter_tabname_print("(x)");
	for (int i = -10; i <= 10; i++)
	{
		const double x = i / 4.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 2, exp2_r4(x), exp2_r8(x), exp2_re(x));
	}
	puts("");
	rmath_pole_title_print();
	
	rmath_check_exp(exp2_r4, exp2_r8, exp2_re);
	
	return 0;
}
