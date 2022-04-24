/*******************************************************************************
	GLUE-Math test suite: Bessel Functions
*******************************************************************************/
#include "../realmath/realmath.h"
#include <stdio.h>
#include <stdlib.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/bessel test/bessel.c realmath/jn_r8.c realmath/yn_r8.c

*******************************************************************************/
int
main(void)
{
	int x;

	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Bessel Functions");
	puts("");

	puts("J_n(x) (the 1st kind)");
	printf(" x   %-13s %-13s %-13s %-13s\n",
	    "J_0(x)", "J_1(x)", "J_2(x)", "J_3(x)");
	for (x = 0; x <= 20; x++)
			printf("%2d %13.10f %13.10f %13.10f %13.10f\n",
			    x, jn_r8(0, x), jn_r8(1, x),
			       jn_r8(2, x), jn_r8(3, x));
	puts("");
	puts("Y_n(x) (the 2nd kind)");
	printf(" x   %-13s %-13s %-13s %-13s\n",
		"Y_0(x)", "Y_1(x)", "Y_2(x)", "Y_3(x)");
	for (x = 1; x <= 20; x++)
			printf("%2d %13.10f %13.10f %13.10f %13.10f\n",
			    x, yn_r8(0, x), yn_r8(1, x),
			       yn_r8(2, x), yn_r8(3, x));
	return 0;
}
