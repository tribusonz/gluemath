/*******************************************************************************
	GLUE-Math test suite: HUGE_VAL & NAN
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#include <stdio.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/hugeval_nan test/hugeval_nan.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  HUGE_VAL & NAN

HUGE_VAL = inf
-HUGE_VAL = -inf
HUGE_VALL = inf
-HUGE_VALL = -inf
HUGE_VALF = inf
-HUGE_VALF = -inf
DBL_MAX < HUGE_VAL ? true
NAN = nan
-NAN = nan
-0.0/-0.0 = nan
NAN == NAN ? false
NAN == NAN + 999 ? false
*******************************************************************************/

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  HUGE_VAL & NAN");
	puts("");
	printf("HUGE_VAL = %f\n", HUGE_VAL);
	printf("-HUGE_VAL = %f\n", -HUGE_VAL);
	printf("HUGE_VALL = %Lf\n", HUGE_VALL);
	printf("-HUGE_VALL = %Lf\n", -HUGE_VALL);
	printf("HUGE_VALF = %f\n", HUGE_VALF);
	printf("-HUGE_VALF = %f\n", -HUGE_VALF);
	
	printf("DBL_MAX < HUGE_VAL ? %s\n", DBL_MAX < HUGE_VAL ? "true" : "false");
	
	printf("NAN = %f\n", NAN);
	printf("-NAN = %f\n", -NAN);
	printf("-0.0/-0.0 = %f\n", -0.0/-0.0);
	
	printf("NAN == NAN ? %s\n", NAN == NAN ? "true" : "false");
	printf("NAN == NAN + 999 ? %s\n", NAN == NAN + 999 ? "true" : "false");
	
	return 0;
}
