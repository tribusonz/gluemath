/*******************************************************************************
	GLUE-Math test routine: tanh()/atanh()
*******************************************************************************/
#include "../realmath/realmath.h"
#include "testsuite.h"
#include <stdio.h>

int
main(void)
{
	rmath_title_print("Hyperbolic Tangent and Hyperbolic Arctangent");

	puts("for double");
	puts(" (x)  atanh(x)  左のtanh");
	for (volatile int i = -100; i <= 100; i += 5)
	{
		const double x = i / 100.0;
		const double y = atanh_r8(x);
		printf("% 1.2f  % .15f | % g\n", x, y, tanh_r8(y));
	}
	puts("");
	puts("for long double");
	puts(" (x)  atanh(x)  左のtanh");
	for (volatile int i = -100; i <= 100; i += 5)
	{
		const long double x = i / 100.0;
		const long double y = atanh_re(x);
		printf("% 1.2Lf  % .18Lf | % Lg\n", x, y, tanh_re(y));
	}
	puts("");
	puts("for float");
	puts(" (x)  atanh(x)  左のtanh");
	for (volatile int i = -100; i <= 100; i += 5)
	{
		const float x = i / 100.0;
		const float y = atanh_r4(x);
		printf("% 1.2f  % .6f | % g\n", x, y, tanh_r4(y));
	}
	return 0;
}

