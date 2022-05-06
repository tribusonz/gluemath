#include "../internal/ur/gammaincg.h"
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	double a, x0, x1;
	
	printf("a x0 x1 ? ");  scanf("%lf%lf%lf", &a, &x0, &x1);
	
	printf("Gamma(%.15g, %.15g, %.15g) = %.15g\n",
	       a, x0, x1, gammaincg_core(a, x0, x1));
	
	return 0;
}
