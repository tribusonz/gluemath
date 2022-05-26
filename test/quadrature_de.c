/*******************************************************************************
	GLUE-Math test routine: Double Exponential rule
*******************************************************************************/
#include "../quadrature/quadrature.h"
#include "../realmath/realmath.h"
#include <stdio.h>

// Declare Prototypes
static void de_test(void);
static void fresnel_sample(void);

int
main(void)
{
   	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Double Exponential Formula");
	puts("");

	de_test();

	puts("");

	fresnel_sample();

}

/**** DE-Test Part ****/
int nfunc;

static void
de_test(void)
{
	integrand f1, f2, f3, f4, f5, f6;
	extern int nfunc;
	double i, err;
	
	nfunc = 0;
	intde(f1, 0.0, 1.0, &i, &err);
	printf("I_1=int_0^1 1/sqrt(x) dx\n");
	printf(" I_1= %.15lg\t, err= %lg\t, N= %d\n", i, err, nfunc);
	nfunc = 0;
	intde(f2, 0.0, 2.0, &i, &err);
	printf("I_2=int_0^2 sqrt(4-x*x) dx\n");
	printf(" I_2= %.15lg\t, err= %lg\t, N= %d\n", i, err, nfunc);
	
	nfunc = 0;
	intdei(f3, 0.0, &i, &err);
	printf("I_3=int_0^infty 1/(1+x*x) dx\n");
	printf(" I_3= %.15lg\t, err= %lg\t, N= %d\n", i, err, nfunc);
	nfunc = 0;
	intdei(f4, 0.0, &i, &err);
	printf("I_4=int_0^infty exp(-x)/sqrt(x) dx\n");
	printf(" I_4= %.15lg\t, err= %lg\t, N= %d\n", i, err, nfunc);
	
	nfunc = 0;
	intdeo(f5, 0.0, 1.0, &i, &err);
	printf("I_5=int_0^infty sin(x)/x dx\n");
	printf(" I_5= %.15lg\t, err= %lg\t, N= %d\n", i, err, nfunc);
	nfunc = 0;
	intdeo(f6, 0.0, 1.0, &i, &err);
	printf("I_6=int_0^infty cos(x)/sqrt(x) dx\n");
	printf(" I_6= %.15lg\t, err= %lg\t, N= %d\n", i, err, nfunc);
}

double
f1(double x)
{
	extern int nfunc;
	
	nfunc++;
	return 1 / sqrt_r8(x);
}


double
f2(double x)
{
	extern int nfunc;
	
	nfunc++;
	return sqrt_r8(4 - x * x);
}


double
f3(double x)
{
	extern int nfunc;
	
	nfunc++;
	return 1 / (1 + x * x);
}


double
f4(double x)
{
	extern int nfunc;
	
	nfunc++;
	return exp_r8(-x) / sqrt_r8(x);
}


double
f5(double x)
{
	extern int nfunc;
	
	nfunc++;
	return sin_r8(x) / x;
}


double
f6(double x)
{
	extern int nfunc;
	
	nfunc++;
	return cos_r8(x) / sqrt_r8(x);
}

/**** Fresnel Integrals Samples ****/
#define PI 3.14159265358979323846

double
fresnel_cos_quadrature(double nu)
{
	return cos_r8(PI * nu * nu / 2);
}

double
fresnel_cos(double x)
{
	double i, err;
	intde(fresnel_cos_quadrature, 0.0, x, &i, &err);
	return i;
}

double
fresnel_sin_quadrature(double nu)
{
	return sin_r8(PI * nu * nu / 2);
}

double
fresnel_sin(double x)
{
	double i, err;
	intde(fresnel_sin_quadrature, 0.0, x, &i, &err);
	return i;
}

static void
fresnel_sample(void)
{
	puts("Sample for Fresnel Integral Implementation");
	puts("Ruby-like coding");
	puts("def fresnel_cos(x)");
	puts("  quadrand = proc do |nu|");
	puts("    RMath.cos(PI * nu * nu / 2)");
	puts("  end");
	puts("  y = Quadrature.de(quadrand, 0, x)");
	puts("  y[0]");
	puts("end");
	puts("def fresnel_sin(x)");
	puts("  quadrand = proc do |nu|");
	puts("    RMath.sin(PI * nu * nu / 2)");
	puts("  end");
	puts("  y = Quadrature.de(quadrand, 0, x)");
	puts("  y[0]");
	puts("end");
	puts("");

	printf("% 5s  %17.15s  %17.15s\n",
	       "(x)", "fresnel_cos(x)", "fresnel_sin(x)");
	for (volatile int i = -50; i <= 50; i++)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("% 5.1f  % 15.15f  % 15.15f\n",
		       x, fresnel_cos(x), fresnel_sin(x));
	}
}

