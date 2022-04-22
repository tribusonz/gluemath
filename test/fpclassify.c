/*******************************************************************************
	GLUE-Math test suite: Macro of fpclassify()
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#include "../sys/float/info.h"
#include "../sys/float/fpclassify.h"
#include "../internal/sys/primitive/float/fpclassify.h"
#include <stdio.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/fpclassify test/fpclassify.c

And Test Result:
GLUE-Math with POSIX standard
Test Suite:
  Macro of fpclassify()

fpclassify(NAN) == FP_NAN ? true
fpclassify(HUGE_VAL) == FP_INFINITE ? true
fpclassify(0.0) == FP_ZERO ? true
fpclassify(1e-309) == FP_SUBNORMAL ? true
fpclassify(1.0) == FP_NORMAL ? true
fpclassify(-HUGE_VAL) == FP_INFINITE ? true
fpclassify(-0.0) == FP_ZERO ? true
fpclassify(-1e-309) == FP_SUBNORMAL ? true
fpclassify(-1.0) == FP_NORMAL ? true
isnan(NAN) = true
isinf(HUGE_VAL) = 1
isinf(-HUGE_VAL) = -1
isfinite(1.0) = 1
isfinite(-1.0) = -1
isnormal(1.0) = 1
isnormal(-1.0) = -1
isnormal(1e-309) = 0
*******************************************************************************/

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Macro of fpclassify()");
	puts("");

	printf("fpclassify(NAN) == FP_NAN ? %s\n", fpclassify(NAN) == FP_NAN ? "true" : "false");
	printf("fpclassify(HUGE_VAL) == FP_INFINITE ? %s\n", fpclassify(HUGE_VAL) == FP_INFINITE ? "true" : "false");
	printf("fpclassify(0.0) == FP_ZERO ? %s\n", fpclassify(0.0) == FP_ZERO ? "true" : "false");
	printf("fpclassify(1e-309) == FP_SUBNORMAL ? %s\n", fpclassify(1e-309) == FP_SUBNORMAL ? "true" : "false");
	printf("fpclassify(1.0) == FP_NORMAL ? %s\n", fpclassify(1.0) == FP_NORMAL ? "true" : "false");
	
	printf("fpclassify(-HUGE_VAL) == FP_INFINITE ? %s\n", fpclassify(-HUGE_VAL) == FP_INFINITE ? "true" : "false");
	printf("fpclassify(-0.0) == FP_ZERO ? %s\n", fpclassify(-0.0) == FP_ZERO ? "true" : "false");
	printf("fpclassify(-1e-309) == FP_SUBNORMAL ? %s\n", fpclassify(-1e-309) == FP_SUBNORMAL ? "true" : "false");
	printf("fpclassify(-1.0) == FP_NORMAL ? %s\n", fpclassify(-1.0) == FP_NORMAL ? "true" : "false");

	printf("isnan(NAN) = %s\n", isnan(NAN) ? "true" : "false");
	printf("isinf(HUGE_VAL) = %d\n", isinf(HUGE_VAL));
	printf("isinf(-HUGE_VAL) = %d\n", isinf(-HUGE_VAL));
	printf("isfinite(1.0) = %d\n", isfinite(1.0));
	printf("isfinite(-1.0) = %d\n", isfinite(-1.0));
	printf("isnormal(1.0) = %d\n", isnormal(1.0));
	printf("isnormal(-1.0) = %d\n", isnormal(-1.0));
	printf("isnormal(1e-309) = %d\n", isnormal(1e-309));

}
