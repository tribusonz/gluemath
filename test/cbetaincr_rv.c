#include "../sys/complex/class.h"
#include "../internal/ur/ur_cbetaincr_rv.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int
main(void)
{
	double x, a, b;
	dcomplex z;
	printf("x a b ? "); scanf("%lf%lf%lf", &x, &a, &b);
	z = ur_cbetaincr_rv(x, a, b);
	printf("RMath.beta(%.15g, %.15g, %.15g, regular: true)\n", x, a, b);
	if (z.imag == 0.0)
		printf("#=> %.15g\n", z.real);
	else
		printf("#=> (%.15g%+.15gi)\n", z.real, z.imag);
	return 0;
}
