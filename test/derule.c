/*******************************************************************************
	GLUE-Math test routine: DE-rule
*******************************************************************************/
#include "../quadrature/quadrature.h"
#include "../realmath/realmath.h"
#include <stdio.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -Iquadrature -c quadrature/intde.c
$ gcc -Wall -Wextra -O3 -Iquadrature -c quadrature/intdei.c
$ gcc -Wall -Wextra -O3 -Iquadrature -c quadrature/intdeo.c
$ gcc -Wall -Wextra -O3 -Irealmath -c realmath/exp_r8.c
$ gcc -Wall -Wextra -O3 -Irealmath -c realmath/sqrt_r8.c
$ gcc -Wall -Wextra -O3 -Irealmath -c realmath/sin_r8.c
$ gcc -Wall -Wextra -O3 -Irealmath -c realmath/cos_r8.c
$ gcc -o bin/derule test/derule.c intde.o intdei.o intdeo.o exp_r8.o sqrt_r8.o sin_r8.o cos_r8.o

And test result:
GLUE-Math with POSIX standard
Test Suite:
  DE-rule

I_1=int_0^1 1/sqrt(x) dx
 I_1= 2 , err= 8.88172e-16      , N= 67
I_2=int_0^2 sqrt(4-x*x) dx
 I_2= 3.14159265358979  , err= 1.39515e-15      , N= 57
I_3=int_0^infty 1/(1+x*x) dx
 I_3= 1.5707963267949   , err= 6.97574e-16      , N= 57
I_4=int_0^infty exp(-x)/sqrt(x) dx
 I_4= 1.77245385090552  , err= 1.57426e-15      , N= 115
I_5=int_0^infty sin(x)/x dx
 I_5= 1.5707963267949   , err= 1.4696e-15       , N= 126
I_6=int_0^infty cos(x)/sqrt(x) dx
 I_6= 1.2533141373155   , err= 6.71041e-15      , N= 135
*******************************************************************************/

int nfunc;

int
main(void)
{
	integrand f1, f2, f3, f4, f5, f6;
	extern int nfunc;
	double i, err;
	
   	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  DE-rule");
	puts("");

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

