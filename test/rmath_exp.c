/***********************************************************
	GLUE-Math test suite: Exponential Function
***********************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int
main(void)
{
	int i;
	
	rmath_title_print("Exponential Function");

	puts("Polymorphism Pattern: Real variable -> Real solution");
	rmath_methname_print("exp(x)");
	listiter_tabname_print("(x)");
	for (int i = -10; i <= 10; i++)
	{
		const double x = i / 4.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 2, exp_r4(x), exp_r8(x), exp_re(x));
	}
	puts("");
	rmath_pole_title_print();
	
	rmath_check_exp(exp_r4, exp_r8, exp_re);
	
	return 0;
}
