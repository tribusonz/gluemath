/*******************************************************************************
	GLUE-Math test suite: Float info
*******************************************************************************/
#include "../sys/float/info.h"
#include "../internal/sys/primitive/float/info.h"
#include <stdio.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/float_info test/float_info.c sys/float/info.c

And Test Result (Intel 64bit):
GLUE-Math with POSIX standard
Test Suite:
  Float Info

(float type)
Denormalized Number support : true
RADIX      : 2
MANT_DIG   : 24
EPSILON    : 1.19209e-07
EPS_10_EXP : -6
DIG        : 6
MAX        : 3.40282e+38
MIN        : 1.17549e-38
TRUE_MIN   : 1.4013e-45
MAX_EXP    : 128
MIN_EXP    : -125
MAX_10_EXP : 38
MIN_10_EXP : -37
----
RADIX      equal?  true
MANT_DIG   equal?  true
EPSILON    equal?  true
DIG        equal?  true
MAX        equal?  true
MIN        equal?  true
MAX_EXP    equal?  true
MIN_EXP    equal?  true
MAX_10_EXP equal?  true
MIN_10_EXP equal?  true

(double type)
Denormalized Number support : true
RADIX      : 2
MANT_DIG   : 53
EPSILON    : 2.22045e-16
EPS_10_EXP : -9
DIG        : 15
MAX        : 1.79769e+308
MIN        : 2.22507e-308
TRUE_MIN   : 4.94066e-324
MAX_EXP    : 1024
MIN_EXP    : -1021
MAX_10_EXP : 308
MIN_10_EXP : -307
----
RADIX      equal?  true
MANT_DIG   equal?  true
EPSILON    equal?  true
DIG        equal?  true
MAX        equal?  true
MIN        equal?  true
MAX_EXP    equal?  true
MIN_EXP    equal?  true
MAX_10_EXP equal?  true
MIN_10_EXP equal?  true

(long double type)
Denormalized Number support : true
RADIX      : 2
MANT_DIG   : 64
EPSILON    : 1.0842e-19
EPS_10_EXP : -13
DIG        : 18
MAX        : 1.18973e+4932
MIN        : 3.3621e-4932
TRUE_MIN   : 3.6452e-4951
MAX_EXP    : 16384
MIN_EXP    : -16381
MAX_10_EXP : 4932
MIN_10_EXP : -4931
----
RADIX      equal?  true
MANT_DIG   equal?  true
EPSILON    equal?  true
DIG        equal?  true
MAX        equal?  true
MIN        equal?  true
MAX_EXP    equal?  true
MIN_EXP    equal?  true
MAX_10_EXP equal?  true
MIN_10_EXP equal?  true

The quad precision is:
$ gcc -Wall -Wextra -O3 -mlong-double-128 -o bin/float_info test/float_info.c sys/float/info.c

(long double type)
Denormalized Number support : true
RADIX      : 2
MANT_DIG   : 113
EPSILON    : 0
EPS_10_EXP : -13
DIG        : 33
MAX        : nan  // can't meassure the printf() function
MIN        : 0    // can't meassure the printf() function
TRUE_MIN   : 3.6452e-4951
MAX_EXP    : 16384
MIN_EXP    : -16381
MAX_10_EXP : 4932
MIN_10_EXP : -4931
----
RADIX      equal?  true
MANT_DIG   equal?  true
EPSILON    equal?  true
DIG        equal?  true
MAX        equal?  true
MIN        equal?  true
MAX_EXP    equal?  true
MIN_EXP    equal?  true
MAX_10_EXP equal?  true
MIN_10_EXP equal?  true
*******************************************************************************/

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Float Info");
	puts("");
	puts("(float type)");
	get_flt_info();
	printf("Denormalized Number support : %s\n", flt_info.has_subnorm ? "true" : "false");
    printf("RADIX      : %d\n", flt_info.radix);
    printf("MANT_DIG   : %d\n", flt_info.mant_dig);
    printf("EPSILON    : %g\n", flt_info.epsilon);
    printf("EPS_10_EXP : %d\n", flt_info.eps_10_exp);
    printf("DIG        : %d\n", flt_info.dig);
    printf("MAX        : %g\n", flt_info.max);
    printf("MIN        : %g\n", flt_info.min);
    printf("TRUE_MIN   : %g\n", flt_info.true_min);
    printf("MAX_EXP    : %d\n", flt_info.max_exp);
    printf("MIN_EXP    : %d\n", flt_info.min_exp);
    printf("MAX_10_EXP : %d\n", flt_info.max_10_exp);
    printf("MIN_10_EXP : %d\n", flt_info.min_10_exp);
    puts("----");
    printf("RADIX      equal?  %s\n", flt_radix() == FLT_RADIX ? "true" : "false");
    printf("MANT_DIG   equal?  %s\n", flt_mant_dig() == FLT_MANT_DIG ? "true" : "false"); 
    printf("EPSILON    equal?  %s\n", flt_epsilon() == FLT_EPSILON ? "true" : "false"); 
    printf("DIG        equal?  %s\n", flt_dig() == FLT_DIG ? "true" : "false"); 
    printf("MAX        equal?  %s\n", flt_max() == FLT_MAX ? "true" : "false"); 
    printf("MIN        equal?  %s\n", flt_min() == FLT_MIN ? "true" : "false"); 
    printf("MAX_EXP    equal?  %s\n", flt_max_exp() == FLT_MAX_EXP ? "true" : "false"); 
    printf("MIN_EXP    equal?  %s\n", flt_min_exp() == FLT_MIN_EXP ? "true" : "false"); 
    printf("MAX_10_EXP equal?  %s\n", flt_max_10_exp() == FLT_MAX_10_EXP ? "true" : "false"); 
    printf("MIN_10_EXP equal?  %s\n", flt_min_10_exp() == FLT_MIN_10_EXP ? "true" : "false"); 
	puts("");
	puts("(double type)");
	get_dbl_info();
	printf("Denormalized Number support : %s\n", dbl_info.has_subnorm ? "true" : "false");
    printf("RADIX      : %d\n", dbl_info.radix);
    printf("MANT_DIG   : %d\n", dbl_info.mant_dig);
    printf("EPSILON    : %g\n", dbl_info.epsilon);
    printf("EPS_10_EXP : %d\n", dbl_info.eps_10_exp);
    printf("DIG        : %d\n", dbl_info.dig);
    printf("MAX        : %g\n", dbl_info.max);
    printf("MIN        : %g\n", dbl_info.min);
    printf("TRUE_MIN   : %g\n", dbl_info.true_min);
    printf("MAX_EXP    : %d\n", dbl_info.max_exp);
    printf("MIN_EXP    : %d\n", dbl_info.min_exp);
    printf("MAX_10_EXP : %d\n", dbl_info.max_10_exp);
    printf("MIN_10_EXP : %d\n", dbl_info.min_10_exp);
    puts("----");
    printf("RADIX      equal?  %s\n", dbl_radix() == FLT_RADIX ? "true" : "false");
    printf("MANT_DIG   equal?  %s\n", dbl_mant_dig() == DBL_MANT_DIG ? "true" : "false"); 
    printf("EPSILON    equal?  %s\n", dbl_epsilon() == DBL_EPSILON ? "true" : "false"); 
    printf("DIG        equal?  %s\n", dbl_dig() == DBL_DIG ? "true" : "false"); 
    printf("MAX        equal?  %s\n", dbl_max() == DBL_MAX ? "true" : "false"); 
    printf("MIN        equal?  %s\n", dbl_min() == DBL_MIN ? "true" : "false"); 
    printf("MAX_EXP    equal?  %s\n", dbl_max_exp() == DBL_MAX_EXP ? "true" : "false"); 
    printf("MIN_EXP    equal?  %s\n", dbl_min_exp() == DBL_MIN_EXP ? "true" : "false"); 
    printf("MAX_10_EXP equal?  %s\n", dbl_max_10_exp() == DBL_MAX_10_EXP ? "true" : "false"); 
    printf("MIN_10_EXP equal?  %s\n", dbl_min_10_exp() == DBL_MIN_10_EXP ? "true" : "false"); 
	puts("");
	puts("(long double type)");
	get_ldbl_info();
	printf("Denormalized Number support : %s\n", ldbl_info.has_subnorm ? "true" : "false");
    printf("RADIX      : %d\n", ldbl_info.radix);
    printf("MANT_DIG   : %d\n", ldbl_info.mant_dig);
    printf("EPSILON    : %Lg\n", ldbl_info.epsilon);
    printf("EPS_10_EXP : %d\n", ldbl_info.eps_10_exp);
    printf("DIG        : %d\n", ldbl_info.dig);
    printf("MAX        : %Lg\n", ldbl_info.max);
    printf("MIN        : %Lg\n", ldbl_info.min);
    printf("TRUE_MIN   : %Lg\n", ldbl_info.true_min);
    printf("MAX_EXP    : %d\n", ldbl_info.max_exp);
    printf("MIN_EXP    : %d\n", ldbl_info.min_exp);
    printf("MAX_10_EXP : %d\n", ldbl_info.max_10_exp);
    printf("MIN_10_EXP : %d\n", ldbl_info.min_10_exp);
    puts("----");
    printf("RADIX      equal?  %s\n", ldbl_radix() == FLT_RADIX ? "true" : "false");
    printf("MANT_DIG   equal?  %s\n", ldbl_mant_dig() == LDBL_MANT_DIG ? "true" : "false"); 
    printf("EPSILON    equal?  %s\n", ldbl_epsilon() == LDBL_EPSILON ? "true" : "false"); 
    printf("DIG        equal?  %s\n", ldbl_dig() == LDBL_DIG ? "true" : "false"); 
    printf("MAX        equal?  %s\n", ldbl_max() == LDBL_MAX ? "true" : "false"); 
    printf("MIN        equal?  %s\n", ldbl_min() == LDBL_MIN ? "true" : "false"); 
    printf("MAX_EXP    equal?  %s\n", ldbl_max_exp() == LDBL_MAX_EXP ? "true" : "false"); 
    printf("MIN_EXP    equal?  %s\n", ldbl_min_exp() == LDBL_MIN_EXP ? "true" : "false"); 
    printf("MAX_10_EXP equal?  %s\n", ldbl_max_10_exp() == LDBL_MAX_10_EXP ? "true" : "false"); 
    printf("MIN_10_EXP equal?  %s\n", ldbl_min_10_exp() == LDBL_MIN_10_EXP ? "true" : "false"); 

    return 0;
}
