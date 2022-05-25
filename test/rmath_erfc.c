/*******************************************************************************
	GLUE-Math test suite: Gaussian Complementary Error Function
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Gaussian Complementary Error Function");

	rmath_calctest_title_print();

	rmath_polympatt_print("Real variable", "Real solution");
	rmath_methname_print("erfc(x)");
	listiter_tabname_print("(x)");
	for (int i = -60; i <= 60; i += 5)
	{
		const double x = i / 10.0;  // Iterator Constant
		listiter_tabitem_print(x, 5, 1, erfc_r4(x), erfc_r8(x), erfc_re(x));
	}
	puts("");
	rmath_pole_title_print();
	rmath_check_pole1(erfc_r4, erfc_r8, erfc_re);
	
	return 0;
}
