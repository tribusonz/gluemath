/*******************************************************************************
	GLUE-Math test routine: signbit()

*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#include "../sys/float/signbit.h"
#include <stdio.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/signbit test/signbit.c

And Test Result:
signbit(0.0) = false
signbit(130.0) = false
signbit(HUGE_VAL) = false
signbit(NAN) = false
signbit(-130.0) = true
signbit(-HUGE_VAL) = true
signbit(-NAN) = false
for Negative zero supports OS like Windows
signbit(-0.0) = false
*******************************************************************************/

int
main(void)
{
	printf("signbit(0.0) = %s\n", signbit(0.0) ? "true" : "false");
	printf("signbit(130.0) = %s\n", signbit(130.0) ? "true" : "false");
	printf("signbit(HUGE_VAL) = %s\n", signbit(HUGE_VAL) ? "true" : "false");
	printf("signbit(NAN) = %s\n", signbit(NAN) ? "true" : "false");
	printf("signbit(-130.0) = %s\n", signbit(-130.0) ? "true" : "false");
	printf("signbit(-HUGE_VAL) = %s\n", signbit(-HUGE_VAL) ? "true" : "false");
	printf("signbit(-NAN) = %s\n", signbit(-NAN) ? "true" : "false");
	puts("for Negative zero supports OS like Windows");
	printf("signbit(-0.0) = %s\n", signbit(-0.0) ? "true" : "false");
	
	return 0;
}
