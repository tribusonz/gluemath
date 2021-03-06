/*******************************************************************************
	GLUE-Math test routine: Truncate function
*******************************************************************************/
#include "../legacy/legacy.h"
#include "../sys/float/nnint.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
Compile on MinGW 64bit:
$ gcc -Wall -Wextra -O3 -o bin/trunc test/trunc.c

And Test Result:
Nearest neighbor Integer Functions test
value, trunc
Value: -7.857797030825168 -> -7.000000000000000
Value:  7.759689353406429 ->  7.000000000000000
Value: -0.996826271060854 -> -0.000000000000000
Value: -0.408964626491070 -> -0.000000000000000
Value: -3.606799189466983 -> -3.000000000000000
Value: -61.345153590664268 -> -61.000000000000000
Value:  518.682651012204587 ->  518.000000000000000
Value:  134.871294700540602 ->  134.000000000000000
Value: -569.552076340187341 -> -569.000000000000000
Value: -778.597641248255968 -> -778.000000000000000
Value:  9456.493844250217080 ->  9456.000000000000000
Value: -1479.289839328266680 -> -1479.000000000000000
Value:  66084.666861926671118 ->  66084.000000000000000
Value:  106663.652744794264436 ->  106663.000000000000000
Value: -8888.483908473048359 -> -8888.000000000000000
Value:  1795899.527863215655088 ->  1795899.000000000000000
Value:  4009205.710910698398948 ->  4009205.000000000000000
Value: -751082.192218780517578 -> -751082.000000000000000
Value: -1827353.231546598486602 -> -1827353.000000000000000
Value:  5695954.370530229061842 ->  5695954.000000000000000

value, truncl
Value: -0.219365568831562996 -> -0.000000000000000000
Value:  10.309692677110433578 ->  10.000000000000000000
Value: -6.764981493353843689 -> -6.000000000000000000
Value: -0.560303369536995888 -> -0.000000000000000000
Value: -0.471976734232157469 -> -0.000000000000000000
Value:  55.416685514152050018 ->  55.000000000000000000
Value:  359.475884872488677502 ->  359.000000000000000000
Value:  65.063979097642004490 ->  65.000000000000000000
Value: -1110.054836086928844452 -> -1110.000000000000000000
Value:  793.421177040785551071 ->  793.000000000000000000
Value:  80957.105812511872500181 ->  80957.000000000000000000
Value: -11305.361218255013227463 -> -11305.000000000000000000
Value:  11070.556493374053388834 ->  11070.000000000000000000
Value:  3713.588945940136909485 ->  3713.000000000000000000
Value:  46216.201224522665143013 ->  46216.000000000000000000
Value:  272286.953150459565222263 ->  272286.000000000000000000
Value: -2383567.669626273214817047 -> -2383567.000000000000000000
Value:  16286634.998822119086980820 ->  16286634.000000000000000000
Value: -9681122.818302957341074944 -> -9681122.000000000000000000
Value:  2223147.393506518565118313 ->  2223147.000000000000000000

value, truncf
Value:  0.000000 ->  0.000000
Value: -0.171256 -> -0.000000
Value:  4.092088 ->  4.000000
Value: -9.338963 -> -9.000000
Value: -2.314069 -> -2.000000
Value:  290.912903 ->  290.000000
Value: -928.542542 -> -928.000000
Value:  413.143799 ->  413.000000
Value: -971.790466 -> -971.000000
Value:  1324.900513 ->  1324.000000
Value: -520.554382 -> -520.000000
Value:  90081.179688 ->  90081.000000
Value:  299.509430 ->  299.000000
Value:  8713.954102 ->  8713.000000
Value: -111271.148438 -> -111271.000000
Value:  7634536.500000 ->  7634536.000000
Value:  10180875.000000 ->  10180875.000000
Value: -57859.882812 -> -57859.000000
Value: -4454278.500000 -> -4454278.000000
Value: -2130375.250000 -> -2130375.000000
*******************************************************************************/


/***** ???l???? (???`?????@) ******************************/
// ????????????

#include <limits.h>
static unsigned long seed = 1;

void
init_rnd(unsigned long x)
{
    seed = x;
}

unsigned long
irnd(void)
{
    seed = seed * 1566083941UL + 1;
    return seed;
}

double
rnd(void)  /* 0 <= rnd() < 1 */
{
    return (1.0 / (ULONG_MAX + 1.0)) * irnd();
}

/**********************************************************/

int
main(void)
{
	init_rnd(123456789UL);
	
	puts("Nearest neighbor Integer Functions test");
	puts("value, trunc");
	for (volatile int i = 0; i < 5; i++)
	{
		const double x = (0.5 - rnd()) * (irnd() / 123456789UL); // Iterator Constant
		printf("Value: % *.*f -> % *.*f\n",
		       DBL_DIG, DBL_DIG, x, DBL_DIG, DBL_DIG, trunc(x));
	}
	for (volatile int i = 0; i < 5; i++)
	{
		const double x = (0.5 - rnd()) * (irnd() / 1234567UL); // Iterator Constant
		printf("Value: % *.*f -> % *.*f\n",
		       DBL_DIG, DBL_DIG, x, DBL_DIG, DBL_DIG, trunc(x));
	}
	for (volatile int i = 0; i < 5; i++)
	{
		const double x = (0.5 - rnd()) * (irnd() / 12345UL); // Iterator Constant
		printf("Value: % *.*f -> % *.*f\n",
		       DBL_DIG, DBL_DIG, x, DBL_DIG, DBL_DIG, trunc(x));
	}
	for (volatile int i = 0; i < 5; i++)
	{
		const double x = (0.5 - rnd()) * (irnd() / 123UL); // Iterator Constant
		printf("Value: % *.*f -> % *.*f\n",
		       DBL_DIG, DBL_DIG, x, DBL_DIG, DBL_DIG, trunc(x));
	}
	puts("");
	puts("value, truncl");
	for (volatile int i = 0; i < 5; i++)
	{
		const long double x = (0.5 - rnd()) * (irnd() / 123456789UL); // Iterator Constant
		printf("Value: % *.*Lf -> % *.*Lf\n",
		       LDBL_DIG, LDBL_DIG, x, LDBL_DIG, LDBL_DIG, truncl(x));
	}
	for (volatile int i = 0; i < 5; i++)
	{
		const long double x = (0.5 - rnd()) * (irnd() / 1234567UL); // Iterator Constant
		printf("Value: % *.*Lf -> % *.*Lf\n",
		       LDBL_DIG, LDBL_DIG, x, LDBL_DIG, LDBL_DIG, truncl(x));
	}
	for (volatile int i = 0; i < 5; i++)
	{
		const long double x = (0.5 - rnd()) * (irnd() / 12345UL); // Iterator Constant
		printf("Value: % *.*Lf -> % *.*Lf\n",
		       LDBL_DIG, LDBL_DIG, x, LDBL_DIG, LDBL_DIG, truncl(x));
	}
	for (volatile int i = 0; i < 5; i++)
	{
		const long double x = (0.5 - rnd()) * (irnd() / 123UL); // Iterator Constant
		printf("Value: % *.*Lf -> % *.*Lf\n",
		       LDBL_DIG, LDBL_DIG, x, LDBL_DIG, LDBL_DIG, truncl(x));
	}
	puts("");
	puts("value, truncf");
	for (volatile int i = 0; i < 5; i++)
	{
		const float x = (0.5 - rnd()) * (irnd() / 123456789UL); // Iterator Constant
		printf("Value: % *.*f -> % *.*f\n",
		       FLT_DIG, FLT_DIG, x, FLT_DIG, FLT_DIG, truncf(x));
	}
	for (volatile int i = 0; i < 5; i++)
	{
		const float x = (0.5 - rnd()) * (irnd() / 1234567UL); // Iterator Constant
		printf("Value: % *.*f -> % *.*f\n",
		       FLT_DIG, FLT_DIG, x, FLT_DIG, FLT_DIG, truncf(x));
	}
	for (volatile int i = 0; i < 5; i++)
	{
		const float x = (0.5 - rnd()) * (irnd() / 12345UL); // Iterator Constant
		printf("Value: % *.*f -> % *.*f\n",
		       FLT_DIG, FLT_DIG, x, FLT_DIG, FLT_DIG, truncf(x));
	}
	for (volatile int i = 0; i < 5; i++)
	{
		const float x = (0.5 - rnd()) * (irnd() / 123UL); // Iterator Constant
		printf("Value: % *.*f -> % *.*f\n",
		       FLT_DIG, FLT_DIG, x, FLT_DIG, FLT_DIG, truncf(x));
	}
	return 0;
}
