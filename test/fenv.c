/*******************************************************************************
	GLUE-Math Library: tuning: float envieronment
*******************************************************************************/
#include "../tuning/fenv.h"
#include <stdio.h>
/*******************************************************************************
MinGW 64bit test builds:
$ gcc -Wall -Wextra -O3 -mlong-double-128 -o bin/fenv test/fenv.c
----
float type is: IEEE-754 FP single precision
double type is: IEEE-754 FP double precision
long double type is: IEEE-754 FP quad precision
----

$ gcc -Wall -Wextra -O3 -mlong-double-80 -o bin/fenv test/fenv.c
----
float type is: IEEE-754 FP single precision
double type is: IEEE-754 FP double precision
long double type is: IEEE-754 FP extended double precision
----

$ gcc -Wall -Wextra -O3 -mlong-double-64 -o bin/fenv test/fenv.c
----
float type is: IEEE-754 FP single precision
double type is: IEEE-754 FP double precision
long double type is: IEEE-754 FP double precision
----
*******************************************************************************/
int
main(void)
{
	check_flt_is_binary32();
	printf("float type is: ");
	if (flt_is_binary32)
		puts("IEEE-754 FP single precision");
	else
		puts("unknown or custom");
	check_dbl_is_binary64();
	printf("double type is: ");
	if (dbl_is_binary64)
		puts("IEEE-754 FP double precision");
	else
		puts("unknown or custom");
	check_ldbl_type();
	printf("long double type is: ");
	if (ldbl_type == 1)
		puts("IEEE-754 FP double precision");
	else if (ldbl_type == 2)
		puts("IEEE-754 FP extended double precision");
	else if (ldbl_type == 3)
		puts("IEEE-754 FP quad precision");
	else
		puts("unknown or custom");	
	return 0;
}
