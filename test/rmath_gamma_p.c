/*******************************************************************************
	GLUE-Math test suite: p-adic Gamma Function
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <float.h>

// Declare Prototypes
static void p_gamma_print(double a);

int
main(void)
{
	rmath_title_print("p-adic Gamma Function");

	puts("  The p-adic Gamma Function represents the principal value of the-");
	puts("  Regularized Incomplete Gamma Function P(a, x) and Q(a, x)");
	puts("");
	p_gamma_print(0.5);
	p_gamma_print(1);
	p_gamma_print(2);
	p_gamma_print(5.5);
	p_gamma_print(10);

	return 0;
}


static void
p_gamma_print(double a)
{
	printf("Gamma_p(%g, x)\n", a);
	printf(" %-5.7s  %-*.*s   %-*.*s\n", "(x)", 
	       DBL_DIG + 2, DBL_DIG + 2, "Gamma_p(a, x)",
	       DBL_DIG + 2, DBL_DIG + 2, "Gamma_q(a, x)");
	for (volatile int i = 0; i <= 100; i += 5)
	{
		const double x = i / 100.0;  // Iterator Constant
		printf("% 5.2f  % *.*f  % *.*f\n", x,
		       DBL_DIG, DBL_DIG, p_gamma_r8(a, x),
		       DBL_DIG, DBL_DIG, q_gamma_r8(a, x));
	}
	puts("");
}
