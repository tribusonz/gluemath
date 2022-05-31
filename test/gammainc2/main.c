#include "../../internal/ur/gammainc2.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	double a, x;
	
	printf("a x ? ");  scanf("%lf%lf", &a, &x);
	
	printf("Gamma(%.15g, %.15g) = %.15g\n",
	       a, x, gammainc2_core(a, x));
	
	return 0;
}
