/*******************************************************************************
	GLUE-Math test routine: Complex Power
*******************************************************************************/
#include "../../internal/ur/cpow.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	dcomplex c1, c2, c3;
	
	printf("Re(c1) Im(c1) ? "); scanf("%lf%lf", &c1.real, &c1.imag);
	fflush(stdout);
	printf("Re(c2) Im(c2) ? "); scanf("%lf%lf", &c2.real, &c2.imag);
	fflush(stdout);
	printf("(%.15g%+.15gi) ** (%.15g%+.15gi) = ",
	       c1.real, c1.imag, c2.real, c2.imag);
	c3 = cpow_core(c1, c2);
	printf("(%.15g%+.15gi)\n", c3.real, c3.imag);
}

