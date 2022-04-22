/*******************************************************************************
	GLUE-Math test suite: Real numbers absolute
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#include "../sys/float/absolute.h"

#include <stdio.h>

/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/fabs test/fabs.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Real numbers Absolute

|-100.0| = 100.000000
|-100.F| = 100.000000
|-100.L| = 100.000000
|-HUGE_VAL| = inf
|-HUGE_VALF| = inf
|-HUGE_VALL| = inf
*******************************************************************************/
int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Real numbers Absolute");
	puts("");

	printf("|-100.0| = %f\n", fabs(-100.0));
	printf("|-100.F| = %f\n", fabsf(-100.F));
	printf("|-100.L| = %Lf\n", fabsl(-100.L));

	printf("|-HUGE_VAL| = %f\n", fabs(-HUGE_VAL));
	printf("|-HUGE_VALF| = %f\n", fabsf(-HUGE_VALF));
	printf("|-HUGE_VALL| = %Lf\n", fabsl(-HUGE_VALL));
}
