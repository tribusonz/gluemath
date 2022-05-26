/*******************************************************************************
	GLUE-Math test routine: Double Exponential rule
*******************************************************************************/
#include "../quadrature/quadrature.h"
#include "../realmath/realmath.h"
#include <stdio.h>

// Declare Prototypes
static void de_test(void);
static void fresnel_sample(void);

static void sepline80_print(void);

int
main(void)
{
   	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Double Exponential Formula");
	puts("");

	sepline80_print();

	de_test();

	sepline80_print();

	fresnel_sample();

}

/*******************************************************************************
	DE-Test Part
*******************************************************************************/
int nfunc;

static void detest_summarize_print(void);

static void
de_test(void)
{
	integrand f1, f2, f3, f4, f5, f6;
	extern int nfunc;
	double i, err;
	
	detest_summarize_print();
	
	nfunc = 0;
	intde(f1, 0.0, 1.0, &i, &err);
	printf("I_1=int_0^1 1/sqrt(x) dx\n");
	printf(" I_1= % 15.15lf, err= %.15lg, N= %d\n", i, err, nfunc);
	nfunc = 0;
	intde(f2, 0.0, 2.0, &i, &err);
	printf("I_2=int_0^2 sqrt(4-x*x) dx\n");
	printf(" I_2= % 15.15lf, err= %.15lg, N= %d\n", i, err, nfunc);
	
	nfunc = 0;
	intdei(f3, 0.0, &i, &err);
	printf("I_3=int_0^infty 1/(1+x*x) dx\n");
	printf(" I_3= % 15.15lf, err= %.15lg, N= %d\n", i, err, nfunc);
	nfunc = 0;
	intdei(f4, 0.0, &i, &err);
	printf("I_4=int_0^infty exp(-x)/sqrt(x) dx\n");
	printf(" I_4= % 15.15lf, err= %.15lg, N= %d\n", i, err, nfunc);
	
	nfunc = 0;
	intdeo(f5, 0.0, 1.0, &i, &err);
	printf("I_5=int_0^infty sin(x)/x dx\n");
	printf(" I_5= % 15.15lf, err= %.15lg, N= %d\n", i, err, nfunc);
	nfunc = 0;
	intdeo(f6, 0.0, 1.0, &i, &err);
	printf("I_6=int_0^infty cos(x)/sqrt(x) dx\n");
	printf(" I_6= % 15.15lf, err= %.15lg, N= %d\n", i, err, nfunc);

	puts("");
}

static void
detest_summarize_print(void)
{
	puts("  - OOURA'S TEST SUITES -");
	puts("");
	puts("  Use the DE formula to find the integral.");
	puts("");
	fflush(stdout);
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

/*******************************************************************************
	Fresnel Integrals Samples
*******************************************************************************/
#define PI 3.14159265358979323846

static void fresnel_summarize_print(void);

static void
fresnel_sample(void)
{
	integrand fresnel_cos_quadrature, fresnel_sin_quadrature;
	double fresnel_cos(double), fresnel_sin(double);
	
	fresnel_summarize_print();
	
	printf("% 5s  %17.15s  %17.15s\n",
	       "(x)", "fresnel_cos(x)", "fresnel_sin(x)");
	for (volatile int i = -50; i <= 50; i++)
	{
		const double x = i / 10.0;  // Iterator Constant
		printf("% 5.1f  % 15.15f  % 15.15f\n",
		       x, fresnel_cos(x), fresnel_sin(x));
	}
}

static void
fresnel_summarize_print(void)
{
	puts("  - SAMPLE FOR FRESNEL INTEGRAL IMPLEMENTATION -");
	puts("");
	puts("  Find the Fresnel integral in the DE formula.");
	puts("");
	puts("  Reference: Abramowitz and Stegun");
	puts("    $C(z) = \\int_0^z \\cos(\\frac{1}{2}\\pi t^2) dt,$");
	puts("    $S(z) = \\int_0^z \\sin(\\frac{1}{2}\\pi t^2) dt,$");
	puts("");
	puts("Ruby-like coding");
	puts("```");
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
	puts("```");
	puts("");
	fflush(stdout);
}

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

/*******************************************************************************
	Test Tools
*******************************************************************************/

static void
sepline80_print(void)
{
	int i;
	for (i = 0; i < 80; i++)
		printf("-");
	puts("");
	puts("");
	fflush(stdout);
}
