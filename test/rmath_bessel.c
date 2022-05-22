/*******************************************************************************
	GLUE-Math test suite: Bessel Functions
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int x;

	rmath_title_print("Bessel Functions");

	puts("J_n(x) Bessel Function the 1st kind");
	printf(" x   %-13s %-13s %-13s %-13s\n",
	    "J_0(x)", "J_1(x)", "J_2(x)", "J_3(x)");
	for (x = 0; x <= 20; x++)
			printf("%2d %13.10f %13.10f %13.10f %13.10f\n",
			    x, jn_r8(0, x), jn_r8(1, x),
			       jn_r8(2, x), jn_r8(3, x));
	puts("Solution for j0(), j1()");
	printf(" x   %-13s %-13s\n",
	    "J_0(x)", "J_1(x)");
	for (x = 0; x <= 20; x++)
			printf("%2d %13.10f %13.10f\n",
			    x, j0_r8(x), j1_r8(x));
	puts("");
	puts("Y_n(x) Bessel Function the 2nd kind");
	printf(" x   %-13s %-13s %-13s %-13s\n",
		"Y_0(x)", "Y_1(x)", "Y_2(x)", "Y_3(x)");
	for (x = 1; x <= 20; x++)
			printf("%2d %13.10f %13.10f %13.10f %13.10f\n",
			    x, yn_r8(0, x), yn_r8(1, x),
			       yn_r8(2, x), yn_r8(3, x));
	puts("Solution for y0(), y1()");
	printf(" x   %-13s %-13s\n",
		"Y_0(x)", "Y_1(x)");
	for (x = 1; x <= 20; x++)
			printf("%2d %13.10f %13.10f\n",
			    x, y0_r8(x), y1_r8(x));
	puts("I_n(x) Modified Bessel Function the 1st kind");
	printf(" x   %-13s %-13s %-13s %-13s\n",
		"I_0(x)", "I_1(x)", "I_2(x)", "I_3(x)");
	for (x = 0; x <= 6; x++)
			printf("%2d %13.10f %13.10f %13.10f %13.10f\n",
				x, in_r8(0, x), in_r8(1, x),
				   in_r8(2, x), in_r8(3, x));
	puts("");
	puts("K_n(x) Modified Bessel Function the 2nd kind");
	printf(" x   %-13s %-13s %-13s %-13s\n",
		"K_0(x)", "K_1(x)", "K_2(x)", "K_3(x)");
	for (x = 1; x <= 20; x++)
			printf("%2d %13.10f %13.10f %13.10f %13.10f\n",
				x, kn_r8(0, x), kn_r8(1, x),
				   kn_r8(2, x), kn_r8(3, x));
	return 0;
}
