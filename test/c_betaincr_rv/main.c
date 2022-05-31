#include "../../sys/complex/class.h"
#include "../../internal/ur/ur_cbetaincr_rv.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
/*******************************************************************************
builds:
Python-like:
gcc -Wall -Wextra -O3 -D_PYTHONLIKE test/cbetaincr_rv/main.c
Ruby-like:
gcc -Wall -Wextra -O3 -D_RUBYLIKE test/cbetaincr_rv/main.c


*******************************************************************************/

int
main(void)
{
	double x, a, b;
	dcomplex z;
	printf("x a b ? "); scanf("%lf%lf%lf", &x, &a, &b);
	z = ur_cbetaincr_rv(x, a, b);
#if defined(_PYTHONLIKE)
	printf(">>> RMath.beta(%.15g, %.15g, %.15g, regular: true)\n", x, a, b);
	if (z.imag == 0.0)
		printf("%.15g\n", z.real);
	else
		printf("(%.15g%+.15gi)\n", z.real, z.imag);
#elif defined(_RUBYLIKE)
	printf("RMath.beta(%.15g, %.15g, %.15g, regular: true)\n", x, a, b);
	if (z.imag == 0.0)
		printf("=> %.15g\n", z.real);
	else
		printf("=> (%.15g%+.15gi)\n", z.real, z.imag);
#elif defined(_WOLFRAM)
	printf("BetaRegularized(%.15g, %.15g, %.15g) = ", x, a, b);
	if (z.imag == 0.0)
		printf("%.15g\n", z.real);
	else
		printf("(%.15g%+.15gi)\n", z.real, z.imag);
#else
	printf("I_%.15g(%.15g, %.15g) = ", x, a, b);
	if (z.imag == 0.0)
		printf("%.15g\n", z.real);
	else
		printf("(%.15g%+.15gi)\n", z.real, z.imag);
#endif
	return 0;
}
