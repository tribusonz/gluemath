/*******************************************************************************
	GLUE-Math Library: Incomplete Gamma Function
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#include <math.h> /* exp() */
#include <float.h> /* DBL_MIN_10_EXP */
#define gamma_max 171

// 2nd kind of integer a
double
gamma_inta(int a, double x)
{
	double expmx, xs, s = 0, b = 0, bi = 1;
	
	if (a <= 0 || a > gamma_max)
		return HUGE_VAL;
	
	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return x > 0 ? 0.0 : NAN; // Gamma(a, -Infinity) is undefined
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:  // don't use denormalized number
		for (volatile int i = 0; i < a; i++)
		{
#if 1
			b = bi;
			for (volatile int j = 0; j < (a-i-1); j++)
				bi = bi + b;
			bi = bi - b;
		}
		return b;
#else
		return factorial(a - 1);
#endif
		break;
	default:
		break;
	}
	
	switch (fpclassify(expmx = exp(-x))) {
	case FP_NAN:
	case FP_INFINITE:
		return a % 2 ? HUGE_VAL : -HUGE_VAL;  // Negative direction overflow.
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:
		return 0.0;  // Positive direction underflow.
		break;
	default:
		break;
	}
	
	switch (a) {
	case 1:
		return expmx;
		break;
	case 2:
		return (expmx * (x * x + x)) / x;
		break;
	case 3:
		return (expmx * (x * x * x +
		                 2 * x * x + 2 * x)) / x;
		break;
	case 4:
		return (expmx * (x * x * x * x +
		                 3 * x * x * x +
		                 6 * x * x + 6 * x)) / x;
		break;
	case 5:
		return (expmx * (x * x * x * x * x +
		                 4 * x * x * x * x +
		                 12 * x * x * x +
		                 24 * x * x + 24 * x)) / x;
		break;
	case 6:
		return (expmx * (x * x * x * x * x * x +
		                 5 * x * x * x * x * x +
		                 20 * x * x * x * x +
		                 60 * x * x * x +
		                 120 * x * x + 120 * x)) / x;
		break;
	case 7:
		return (expmx * (x * x * x * x * x * x * x +
		                 6 * x * x * x * x * x * x +
		                 30 * x * x * x * x * x +
		                 120 * x * x * x * x +
		                 360 * x * x * x +
		                 720 * x * x + 720 * x)) / x;
		break;
	case 8:
		return (expmx * (x * x * x * x * x * x * x * x +
		                 7 * x * x * x * x * x * x * x +
		                 42 * x * x * x * x * x * x +
		                 210 * x * x * x * x * x +
		                 840 * x * x * x * x +
		                 2520 * x * x * x +
		                 5040 * x * x + 5040 * x)) / x;
		break;
	default:
		for (volatile int i = 0; i < a; i++)
		{
			xs = x;  b = bi;
			for (volatile int j = 0; j < (a-i-1); j++)
				{  xs = xs * x; bi = bi + b;  }
			s = s + b * xs;  bi = bi - b;
		}
		return (1 / x) * expmx * s;
		break;
	}
}

/* 参考: The 1st kind */
/*
a = 1:
1 - expmx;

a = 2:
-expmx * x - expmx + 1;

a = 3:
expmx * (-x * x - 2 * x - 2) + 2;

a = 4:
expmx * (-x * x * x - 3 * x * x - 6 * x - 6) + 6;
*/

double
gamma_inta1(int a, double x)
{
	double amax;
#if 1
	amax = gamma_inta(a, 0);
#else
	amax = factorial(a - 1);
#endif
	
	switch (fpclassify(x)) {
	case FP_NAN:
		return NAN;
		break;
	case FP_INFINITE:
		return x > 0 ? amax : NAN; // gamma(a, -Infinity) is undefined
		break;
	case FP_ZERO:
	case FP_SUBNORMAL:  // don't use denormalized number
		return 0.0;
		break;
	default:
		break;
	}

	return amax - gamma_inta(a, x);
}

#include <stdio.h>
int
main(void)
{
	int a;
	puts("(Non-regularized) Incomplete Gamma Function test");
	for (a = 1; a <= 9; a++)
	{
		printf("Gamma(%d, x)\n", a);
		for (volatile int i = -20; i <= 20; i += 2)
		{
			const double x = i / 10.0;
			printf("% 1.1f  %15.15f\n", x, gamma_inta(a, x));
		}
		puts("");
	}
		return 0;
}
