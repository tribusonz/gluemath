/*******************************************************************************
	GLUE-Math test suite: Quadrant / atan2()
*******************************************************************************/
#include "../sys/float/huge_val_nan.h"
#if defined(_CMATH_TEST)
# include "../legacy/legacy.h"
# define quadrant_r8 atan2
# define quadrant_re atan2l
# define quadrant_r4 atan2f
#else
# include "../realmath/realmath.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -D_CMATH_TEST -o bin/quadrant test/quadrant.c legacy/atan2.c legacy/atan2l.c legacy/atan2f.c
$ gcc -Wall -Wextra -O3 -o bin/quadrant test/quadrant.c realmath/quadrant_r8.c realmath/quadrant_re.c realmath/quadrant_r4.c

And test result:
GLUE-Math with POSIX standard
Test Suite:
  Quadrant / atan2()

for float:
complex argument switched by zero
  quadrant( 0.0,  1.0) =  0.00000
  quadrant( 1.0,  0.0) =  1.57079
  quadrant( 0.0, -1.0) =  3.14159
  quadrant(-1.0,  1.0) = -0.78539
  quadrant( 0.0,  inf) =  0.00000
  quadrant( 0.0, -inf) =  3.14159

quadrant switched by finite
  quadrant( 1.0,  1.0) =  0.78539
  quadrant( 1.0, -1.0) =  2.35619
  quadrant(-1.0, -1.0) = -2.35619
  quadrant(-1.0,  1.0) = -0.78539

radian switched by infinite
     0deg:  quadrant( 1.0,  inf) =  0.00000
            quadrant(-1.0,  inf) = -0.00000
    45deg:  quadrant( inf,  inf) =  0.78539
    90deg:  quadrant( inf,  1.0) =  1.57079
            quadrant( inf, -1.0) =  1.57079
   135deg:  quadrant( inf, -inf) =  2.35619
   180deg:  quadrant( 1.0, -inf) =  3.14159
   -45deg:  quadrant(-inf,  inf) = -0.78539
   -90deg:  quadrant(-inf,  1.0) = -1.57079
            quadrant(-inf, -1.0) = -1.57079
  -135deg:  quadrant(-inf, -inf) = -2.35619
  -180deg:  quadrant(-1.0, -inf) = -3.14159

for double:
complex argument switched by zero
  quadrant( 0.0,  1.0) =  0.00000000000000
  quadrant( 1.0,  0.0) =  1.57079632679489
  quadrant( 0.0, -1.0) =  3.14159265358979
  quadrant(-1.0,  1.0) = -0.78539816339744
  quadrant( 0.0,  inf) =  0.00000000000000
  quadrant( 0.0, -inf) =  3.14159265358979

quadrant switched by finite
  quadrant( 1.0,  1.0) =  0.78539816339744
  quadrant( 1.0, -1.0) =  2.35619449019234
  quadrant(-1.0, -1.0) = -2.35619449019234
  quadrant(-1.0,  1.0) = -0.78539816339744

radian switched by infinite
     0deg:  quadrant( 1.0,  inf) =  0.00000000000000
            quadrant(-1.0,  inf) = -0.00000000000000
    45deg:  quadrant( inf,  inf) =  0.78539816339744
    90deg:  quadrant( inf,  1.0) =  1.57079632679489
            quadrant( inf, -1.0) =  1.57079632679489
   135deg:  quadrant( inf, -inf) =  2.35619449019234
   180deg:  quadrant( 1.0, -inf) =  3.14159265358979
   -45deg:  quadrant(-inf,  inf) = -0.78539816339744
   -90deg:  quadrant(-inf,  1.0) = -1.57079632679489
            quadrant(-inf, -1.0) = -1.57079632679489
  -135deg:  quadrant(-inf, -inf) = -2.35619449019234
  -180deg:  quadrant(-1.0, -inf) = -3.14159265358979

for long double:
complex argument switched by zero
  quadrant( 0.0,  1.0) =  0.00000000000000000
  quadrant( 1.0,  0.0) =  1.57079632679489661
  quadrant( 0.0, -1.0) =  3.14159265358979323
  quadrant(-1.0,  1.0) = -0.78539816339744831
  quadrant( 0.0,  inf) =  0.00000000000000000
  quadrant( 0.0, -inf) =  3.14159265358979323

quadrant switched by finite
  quadrant( 1.0,  1.0) =  0.78539816339744831
  quadrant( 1.0, -1.0) =  2.35619449019234492
  quadrant(-1.0, -1.0) = -2.35619449019234492
  quadrant(-1.0,  1.0) = -0.78539816339744831

radian switched by infinite
     0deg:  quadrant( 1.0,  inf) =  0.00000000000000000
            quadrant(-1.0,  inf) = -0.00000000000000000
    45deg:  quadrant( inf,  inf) =  0.78539816339744831
    90deg:  quadrant( inf,  1.0) =  1.57079632679489661
            quadrant( inf, -1.0) =  1.57079632679489661
   135deg:  quadrant( inf, -inf) =  2.35619449019234492
   180deg:  quadrant( 1.0, -inf) =  3.14159265358979323
   -45deg:  quadrant(-inf,  inf) = -0.78539816339744831
   -90deg:  quadrant(-inf,  1.0) = -1.57079632679489661
            quadrant(-inf, -1.0) = -1.57079632679489661
  -135deg:  quadrant(-inf, -inf) = -2.35619449019234492
  -180deg:  quadrant(-1.0, -inf) = -3.14159265358979323
*******************************************************************************/

#define A_SIZE 6
#define B_SIZE 4
#define C_SIZE 12

// List
static const char at[] = "complex argument switched by zero";
static const char bt[] = "quadrant switched by finite";
static const char ct[] = "radian switched by infinite";
static const double ax[A_SIZE]  = { 0.0, 1.0, 0.0, -1.0, 0.0, 0.0 };
static const double ay[A_SIZE]  = { 1.0, 0.0, -1.0, 1.0, HUGE_VAL, -HUGE_VAL };
static const double bx[B_SIZE]  = { 1.0, 1.0, -1.0, -1.0 };
static const double by[B_SIZE]  = { 1.0, -1.0, -1.0, 1.0 };
static const double cx[C_SIZE] =
{
	1.0, -1.0, HUGE_VAL, HUGE_VAL, HUGE_VAL, HUGE_VAL,
	1.0, -HUGE_VAL, -HUGE_VAL, -HUGE_VAL, -HUGE_VAL, -1.0
};
static const double cy[C_SIZE] =
{
	HUGE_VAL, HUGE_VAL, HUGE_VAL, 1.0, -1.0, -HUGE_VAL,
	-HUGE_VAL, HUGE_VAL, 1.0, -1.0, -HUGE_VAL, -HUGE_VAL
};
static const char cs[C_SIZE][9] =
{
	{' ', ' ', ' ', '0', 'd', 'e', 'g', ':', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', '4', '5', 'd', 'e', 'g', ':', ' '},
	{' ', ' ', '9', '0', 'd', 'e', 'g', ':', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', '1', '3', '5', 'd', 'e', 'g', ':', ' '},
	{' ', '1', '8', '0', 'd', 'e', 'g', ':', ' '},
	{' ', '-', '4', '5', 'd', 'e', 'g', ':', ' '},
	{' ', '-', '9', '0', 'd', 'e', 'g', ':', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'-', '1', '3', '5', 'd', 'e', 'g', ':', ' '},
	{'-', '1', '8', '0', 'd', 'e', 'g', ':', ' '}
};

// Prototypes
static char *eval_print(double, double);
static char *quadrant_r4_print(float, float);
static char *quadrant_r8_print(double, double);
static char *quadrant_re_print(long double, long double);
static void quadrant_r4_list_print(void);
static void quadrant_r8_list_print(void);
static void quadrant_re_list_print(void);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Quadrant / atan2()");
	puts("");
	puts("for float:");
	quadrant_r4_list_print();
	puts("");
	puts("for double:");
	quadrant_r8_list_print();
	puts("");
	puts("for long double:");
	quadrant_re_list_print();

	return 0;
}


static char *
quadrant_r4_print(float x, float y)
{
	static char s[0x100];

	snprintf(s, 0x100, "% *.*f\n", FLT_DIG, FLT_DIG, quadrant_r4(x, y));

	return s;
}

static char *
quadrant_r8_print(double x, double y)
{
	static char s[0x100];

	snprintf(s, 0x100, "% *.*f\n", DBL_DIG, DBL_DIG, quadrant_r8(x, y));

	return s;
}

static char *
quadrant_re_print(long double x, long double y)
{
	static char s[0x100];

	snprintf(s, 0x100, "% *.*Lf\n", LDBL_DIG, LDBL_DIG, quadrant_re(x, y));

	return s;
}

static char *
eval_print(const double x, const double y)
{
	static char s[0x100];
	
	snprintf(s, 0x100, "quadrant(% 1.1f, % 1.1f)", x, y);

	return s;
}

static void
quadrant_r4_list_print(void)
{
	printf("%s\n", at);
	for (volatile int i = 0; i < A_SIZE; i++)
	{
		const double quadrant_x = ax[i];
		const double quadrant_y = ay[i];
		printf("  %20.22s = %*.*s\n", eval_print(quadrant_x, quadrant_y),
		       FLT_DIG + 2, FLT_DIG + 2, quadrant_r4_print(quadrant_x, quadrant_y));
	}
	puts("");
	printf("%s\n", bt);
	for (volatile int i = 0; i < B_SIZE; i++)
	{
		const double quadrant_x = bx[i];
		const double quadrant_y = by[i];
		printf("  %20.22s = %*.*s\n", eval_print(quadrant_x, quadrant_y),
		       FLT_DIG + 2, FLT_DIG + 2, quadrant_r8_print(quadrant_x, quadrant_y));
	}
	puts("");
	printf("%s\n", ct);
	for (volatile int i = 0; i < C_SIZE; i++)
	{
		const double quadrant_x = cx[i];
		const double quadrant_y = cy[i];
		printf("  ");
		for (volatile int j = 0; j < 9; j++)
			printf("%c", cs[i][j]);
		printf(" ");
		printf("%20.22s = %*.*s\n", eval_print(quadrant_x, quadrant_y),
		       FLT_DIG + 2, FLT_DIG + 2, quadrant_r8_print(quadrant_x, quadrant_y));
	}
}

static void
quadrant_r8_list_print(void)
{
	printf("%s\n", at);
	for (volatile int i = 0; i < A_SIZE; i++)
	{
		const double quadrant_x = ax[i];
		const double quadrant_y = ay[i];
		printf("  %20.22s = %*.*s\n", eval_print(quadrant_x, quadrant_y),
		       DBL_DIG + 2, DBL_DIG + 2, quadrant_r8_print(quadrant_x, quadrant_y));
	}
	puts("");
	printf("%s\n", bt);
	for (volatile int i = 0; i < B_SIZE; i++)
	{
		const double quadrant_x = bx[i];
		const double quadrant_y = by[i];
		printf("  %20.22s = %*.*s\n", eval_print(quadrant_x, quadrant_y),
		       DBL_DIG + 2, DBL_DIG + 2, quadrant_r8_print(quadrant_x, quadrant_y));
	}
	puts("");
	printf("%s\n", ct);
	for (volatile int i = 0; i < C_SIZE; i++)
	{
		const double quadrant_x = cx[i];
		const double quadrant_y = cy[i];
		printf("  ");
		for (volatile int j = 0; j < 9; j++)
			printf("%c", cs[i][j]);
		printf(" ");
		printf("%20.22s = %*.*s\n", eval_print(quadrant_x, quadrant_y),
		       DBL_DIG + 2, DBL_DIG + 2, quadrant_r8_print(quadrant_x, quadrant_y));
	}
}

static void
quadrant_re_list_print(void)
{
	printf("%s\n", at);
	for (volatile int i = 0; i < A_SIZE; i++)
	{
		const double quadrant_x = ax[i];
		const double quadrant_y = ay[i];
		printf("  %20.22s = %*.*s\n", eval_print(quadrant_x, quadrant_y),
		       LDBL_DIG + 2, LDBL_DIG + 2, quadrant_re_print(quadrant_x, quadrant_y));
	}
	puts("");
	printf("%s\n", bt);
	for (volatile int i = 0; i < B_SIZE; i++)
	{
		const double quadrant_x = bx[i];
		const double quadrant_y = by[i];
		printf("  %20.22s = %*.*s\n", eval_print(quadrant_x, quadrant_y),
		       LDBL_DIG + 2, LDBL_DIG + 2, quadrant_re_print(quadrant_x, quadrant_y));
	}
	puts("");
	printf("%s\n", ct);
	for (volatile int i = 0; i < C_SIZE; i++)
	{
		const double quadrant_x = cx[i];
		const double quadrant_y = cy[i];
		printf("  ");
		for (volatile int j = 0; j < 9; j++)
			printf("%c", cs[i][j]);
		printf(" ");
		printf("%20.22s = %*.*s\n", eval_print(quadrant_x, quadrant_y),
		       LDBL_DIG + 2, LDBL_DIG + 2, quadrant_re_print(quadrant_x, quadrant_y));
	}
}

