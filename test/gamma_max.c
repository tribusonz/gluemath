/*******************************************************************************
	GLUE-Math test suite: Gamma function's calculation bounds
*******************************************************************************/
#include "../tuning/constexpr_gamma.h"
#include <stdio.h>
/*******************************************************************************
MinGW 64bit gcc build (Intel 64bit)
$ gcc -Wall -Wextra -O3 -o bin/gamma_max test/gamma_max.c

And test result:
GLUE-Math with POSIX standard
Test Suite:
  Gamma function's calculation bounds

max of double: 171
max of long double: 1755
max of float: 34
*******************************************************************************/
int
main(void)
{
	get_gamma_const();
	get_gammal_const();
	get_gammaf_const();
	
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Gamma function's calculation bounds");
	puts("");
	
	printf("max of double: %d\n", gamma_max);
	printf("max of long double: %d\n", gammal_max);
	printf("max of float: %d\n", gammaf_max);
	
	return 0;
}
