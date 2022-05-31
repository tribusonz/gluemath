/*******************************************************************************
	GLUE-Math test routine: Polar form
*******************************************************************************/
#include "../../sys/complex/polar.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	fcomplex fz; dcomplex dz; lcomplex lz;
	double rho, theta;

	printf("rho theta ? "); scanf("%lf%lf", &rho, &theta);
	fflush(stdout);
	printf("Complex.polar(%.15g, %.15g)\n", rho, theta);
	fz = fc_polar((float)rho, (float)theta);
	printf("  (%.6g%+.6gi)\n", fz.real, fz.imag);
	dz = dc_polar(rho, theta);
	printf("  (%.15g%+.15gi)\n", dz.real, dz.imag);
	lz = lc_polar((long double)rho, (long double)theta);
	printf("  (%.18Lg%+.18Lgi)\n", lz.real, lz.imag);
}
