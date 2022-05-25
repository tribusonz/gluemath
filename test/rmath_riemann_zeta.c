/*******************************************************************************
	GLUE-Math test routine: Riemann Zeta Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int
main(void)
{
	rmath_title_print("Riemann Zeta Function");

	rmath_calctest_title_print();

	rmath_polympatt_print("Real variable", "Real solution");
	rmath_methname_print("riemann_zeta(s)");
	for (volatile int i = -14; i <= 20; i++)
	{
		const double s = i;
		printf("zeta(% 3.0f) = %-*.*s\n", s, 
		       DBL_DIG + 2, DBL_DIG + 2,
		       dbl_inspect_f(riemann_zeta_r8(s), UNARY_PADDING));
	}
	
	
	return 0;
}
