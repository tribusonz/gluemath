/*******************************************************************************
	GLUE-Math test suite: p-adic Beta Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <float.h>

// Declare Prototypes
static void p_beta_print(double a, double b);

int
main(void)
{
	rmath_title_print("p-adic Beta Function");

	puts("  The p-adic Beta Function represents the principal value of the-");
	puts("  Regularized Incomplete Beta Function I_x(a, b) when 0 <= x <= 1.");
	puts("");
	p_beta_print(0.5, 0.5);
	p_beta_print(1, 0.5);
	p_beta_print(2, 2);
	p_beta_print(5.5, 5);
	p_beta_print(10, 5);

	return 0;
}


static void
p_beta_print(double a, double b)
{
	printf("Bp(x, %g, %g)\n", a, b);
	printf(" %-5.7s  %-*.*s   %-*.*s\n", "(x)", 
	       DBL_DIG + 2, DBL_DIG + 2, "Bp(x, a, b)",
	       DBL_DIG + 2, DBL_DIG + 2, "Bq(x, a, b)");
	for (volatile int i = 0; i <= 100; i += 5)
	{
		const double x = i / 100.0;  // Iterator Constant
		printf("% 5.2f  % *.*f  % *.*f\n", x,
		       DBL_DIG, DBL_DIG, p_beta_r8(x, a, b),
		       DBL_DIG, DBL_DIG, q_beta_r8(x, a, b));
	}
	puts("");
}
