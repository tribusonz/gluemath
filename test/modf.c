/*******************************************************************************
	GLUE-Math Test Routine: modf()

*******************************************************************************/
#include "../legacy/legacy.h"
#include "../sys/random/random.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/modf test/modf.c legacy/modf.c legacy/modfl.c legacy/modff.c

And test result:
modf()
modf( 0.530777460739838) = [ 0,  0.530777460739838]
modf( 1.103592189207546) = [ 1,  0.103592189207546]
modf(-2.521337439668223) = [-2, -0.521337439668223]
modf(-1.134454167031979) = [-1, -0.134454167031979]
modf(-0.154670604872628) = [-0, -0.154670604872628]
modf(-2.598872844878535) = [-2, -0.598872844878535]
modf( 11.624446502525295) = [ 11,  0.624446502525295]
modf(-15.405181748442963) = [-15, -0.405181748442963]
modf( 15.977390703941566) = [ 15,  0.977390703941566]
modf( 13.390830713534587) = [ 13,  0.390830713534585]
modf(-0.506676681735634) = [-0, -0.506676681735634]
modf(-3.815591936546099) = [-3, -0.815591936546099]
modf(-24.459657357822756) = [-24, -0.459657357822756]
modf( 8.746649031007628) = [ 8,  0.746649031007628]
modf( 8.336723781604626) = [ 8,  0.336723781604626]

modfl()
modfl( 0.228829957936438788) = [ 0,  0.228829957936438788]
modfl( 0.319956414935019140) = [ 0,  0.319956414935019140]
modfl(-2.114463001468983805) = [-2, -0.114463001468983805]
modfl(-0.944219367717288094) = [-0, -0.944219367717288094]
modfl(-3.025101893705286926) = [-3, -0.025101893705286926]
modfl( 12.233402229902413438) = [ 12,  0.233402229902413438]
modfl(-3.118180741360863095) = [-3, -0.118180741360863095]
modfl(-13.732042855678386672) = [-13, -0.732042855678386672]
modfl(-15.649967209889659614) = [-15, -0.649967209889659615]
modfl(-2.920941793552170651) = [-2, -0.920941793552170651]
modfl(-0.912125643534551500) = [-0, -0.912125643534551500]
modfl( 12.462007163957295575) = [ 12,  0.462007163957295575]
modfl( 24.275504390578348080) = [ 24,  0.275504390578348078]
modfl( 12.882247512064886052) = [ 12,  0.882247512064886052]
modfl( 21.453361776195556843) = [ 21,  0.453361776195556843]

modff()
modff( 7.035174) = [ 7,  0.035174]
modff( 0.508824) = [ 0,  0.508824]
modff(-0.355748) = [-0, -0.355748]
modff( 4.744947) = [ 4,  0.744947]
modff( 4.520064) = [ 4,  0.520064]
modff( 1.947083) = [ 1,  0.947083]
modff(-10.062777) = [-10, -0.062777]
modff( 1.571145) = [ 1,  0.571145]
modff( 3.874734) = [ 3,  0.874734]
modff( 14.117312) = [ 14,  0.117313]
modff(-19.328598) = [-19, -0.328598]
modff(-15.940167) = [-15, -0.940167]
modff( 6.213227) = [ 6,  0.213227]
modff(-24.818739) = [-24, -0.818739]
modff( 9.688903) = [ 9,  0.688903]
*******************************************************************************/

static void modf_dbl_test(void);
static void modf_ldbl_test(void);
static void modf_flt_test(void);

int
main(void)
{
	init_genrand(time(NULL));

	puts("modf()");
	modf_dbl_test();
	puts("");
	puts("modfl()");
	modf_ldbl_test();
	puts("");
	puts("modff()");
	modf_flt_test();

	return 0;
}

static void
modf_dbl_test(void)
{
	double x, ip, frac;

	for (volatile int i = 0; i < 5; i++)
	{
		x = (genrand_res53() -0.5) * 16;
		frac = modf(x, &ip);
		printf("modf(% 15.15f) = [% g, % 15.15f]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (genrand_res53() -0.5) * 32;
		frac = modf(x, &ip);
		printf("modf(% 15.15f) = [% g, % 15.15f]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (genrand_res53() -0.5) * 64;
		frac = modf(x, &ip);
		printf("modf(% 15.15f) = [% g, % 15.15f]\n", x, ip, frac);
	}
}

static void
modf_ldbl_test(void)
{
	long double x, ip, frac;

	for (volatile int i = 0; i < 5; i++)
	{
		x = (long double)(genrand_res53() - 0.5) * 16;
		frac = modfl(x, &ip);
		printf("modfl(% 18.18Lf) = [% Lg, % 18.18Lf]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (long double)(genrand_res53() - 0.5) * 32;
		frac = modfl(x, &ip);
		printf("modfl(% 18.18Lf) = [% Lg, % 18.18Lf]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (long double)(genrand_res53() - 0.5) * 64;
		frac = modfl(x, &ip);
		printf("modfl(% 18.18Lf) = [% Lg, % 18.18Lf]\n", x, ip, frac);
	}
}

static void
modf_flt_test(void)
{
	float x, ip, frac;

	for (volatile int i = 0; i < 5; i++)
	{
		x = (float)(genrand_res53() -0.5) * 16;
		frac = modff(x, &ip);
		printf("modff(% 6.6f) = [% g, % 6.6f]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (float)(genrand_res53() -0.5) * 32;
		frac = modff(x, &ip);
		printf("modff(% 6.6f) = [% g, % 6.6f]\n", x, ip, frac);
	}
	for (volatile int i = 0; i < 5; i++)
	{
		x = (float)(genrand_res53() -0.5) * 64;
		frac = modff(x, &ip);
		printf("modff(% 6.6f) = [% g, % 6.6f]\n", x, ip, frac);
	}
}
