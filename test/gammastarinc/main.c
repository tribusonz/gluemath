/*******************************************************************************
	Incomplete Gamma Star Function (Test Build)
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "../../internal/ur/gamma.h"
#include "../../internal/ur/exp.h"
#include "../../internal/ur/pow.h"
#include "../../internal/ur/intde.h"

// Declare Prototypes
double gammaincterm(double);
double gammastar_pos(double, double);
double gammastar_neg(double, double);

static double gammainc_a, gammainc_x;

int
main(void)
{
	double a, x;
	printf("a x ? "); scanf("%lf%lf", &a, &x);
	puts("");
	if (a != a || x != x)
	{
		fprintf(stderr, "bad argument.");
		exit(1);
	}

	if (a <= 0.1) gammastar_neg(a, x);
	else          gammastar_pos(a, x);

	return 0;
}


// Incomplete Gamma Integral's Term for x > 0
double
gammaincterm(double t)
{
	return (exp_core(-t * gammainc_x) * pow_core(t, gammainc_a - 1));
}


double
gammastar_pos(double a, double x)
{
	double i, err, ans;
	gammainc_a = a; gammainc_x = x;
	intde_core(gammaincterm, 0, 1, &i, &err);

	printf("i = %.15g, err = %.15g\n", i, err);

	ans = 1 / gamma_core(a);

	printf("invgamma(%.15g) = %.15g\n", a, ans);

	ans = ans * i;

	printf("gammastar(%.15g, %.15g) = %.15g\n", a, x, ans);

	return ans;
}

double
gammastar_neg(double a, double x)
{
	double ans;
	if ((int)a == a)
	{
		puts("negative a on integer-part");
		ans = pow_core(x, a);
		printf("gammastar(%.15g, %.15g) = %.15g\n", a, x, ans);
		return ans;
	}
	return 0;
}
