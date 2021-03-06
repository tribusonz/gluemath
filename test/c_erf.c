/*******************************************************************************
	GLUE-Math test suite: Complex Error Function
*******************************************************************************/
#include "../cmath/cmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // isinf(), isnan()
#include <float.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/c_erf test/c_erf.c cmath/erf_c4.c cmath/erf_c8.c cmath/erf_ce.c

And test result:
GLUE-Math with POSIX standard
Test Suite:
  Gaussian Error Function

for double
imaginary = 0
 real     erf(z)
 -2.0  (-0.995322-0.0i)
 -1.9  (-0.99279-0.0i)
 -1.8  (-0.989091-0.0i)
 -1.7  (-0.98379-0.0i)
 -1.6  (-0.976348-0.0i)
 -1.5  (-0.966105-0.0i)
 -1.4  (-0.952285-0.0i)
 -1.3  (-0.934008-0.0i)
 -1.2  (-0.910314-0.0i)
 -1.1  (-0.880205-0.0i)
 -1.0  (-0.842701-0.0i)
 -0.9  (-0.796908-0.0i)
 -0.8  (-0.742101-0.0i)
 -0.7  (-0.677801-0.0i)
 -0.6  (-0.603856-0.0i)
 -0.5  (-0.5205-0.0i)
 -0.4  (-0.428392-0.0i)
 -0.3  (-0.328627-0.0i)
 -0.2  (-0.222703-0.0i)
 -0.1  (-0.112463-0.0i)
  0.0  (0.0+0.0i)
  0.1  (0.112463+0.0i)
  0.2  (0.222703+0.0i)
  0.3  (0.328627+0.0i)
  0.4  (0.428392+0.0i)
  0.5  (0.5205+0.0i)
  0.6  (0.603856+0.0i)
  0.7  (0.677801+0.0i)
  0.8  (0.742101+0.0i)
  0.9  (0.796908+0.0i)
  1.0  (0.842701+0.0i)
  1.1  (0.880205+0.0i)
  1.2  (0.910314+0.0i)
  1.3  (0.934008+0.0i)
  1.4  (0.952285+0.0i)
  1.5  (0.966105+0.0i)
  1.6  (0.976348+0.0i)
  1.7  (0.98379+0.0i)
  1.8  (0.989091+0.0i)
  1.9  (0.99279+0.0i)
  2.0  (0.995322+0.0i)

imaginary = -1
 real     erf(z)
 -2.0  (-1.00361+0.011259i)
 -1.9  (-1.00862+0.0159521i)
 -1.8  (-1.01717+0.0212196i)
 -1.7  (-1.03067+0.0261865i)
 -1.6  (-1.05063+0.0292628i)
 -1.5  (-1.0784+0.0279637i)
 -1.4  (-1.11477+0.0188151i)
 -1.3  (-1.15952-0.00258429i)
 -1.2  (-1.21087-0.0412801i)
 -1.1  (-1.26508-0.102419i)
 -1.0  (-1.31615-0.190453i)
 -0.9  (-1.35595-0.308177i)
 -0.8  (-1.3747-0.455725i)
 -0.7  (-1.36192-0.629751i)
 -0.6  (-1.30782-0.82299i)
 -0.5  (-1.20485-1.0244i)
 -0.4  (-1.04918-1.21997i)
 -0.3  (-0.841901-1.39414i)
 -0.2  (-0.589524-1.53174i)
 -0.1  (-0.303677-1.62001i)
  0.0  (0.0-1.65043i)
  0.1  (0.303677-1.62001i)
  0.2  (0.589524-1.53174i)
  0.3  (0.841901-1.39414i)
  0.4  (1.04918-1.21997i)
  0.5  (1.20485-1.0244i)
  0.6  (1.30782-0.82299i)
  0.7  (1.36192-0.629751i)
  0.8  (1.3747-0.455725i)
  0.9  (1.35595-0.308177i)
  1.0  (1.31615-0.190453i)
  1.1  (1.26508-0.102419i)
  1.2  (1.21087-0.0412801i)
  1.3  (1.15952-0.00258429i)
  1.4  (1.11477+0.0188151i)
  1.5  (1.0784+0.0279637i)
  1.6  (1.05063+0.0292628i)
  1.7  (1.03067+0.0261865i)
  1.8  (1.01717+0.0212196i)
  1.9  (1.00862+0.0159521i)
  2.0  (1.00361+0.011259i)

for double
imaginary = 0
 real     erf(z)
 -2.0  (-0.995322265018953-0.0i)
 -1.9  (-0.992790429235258-0.0i)
 -1.8  (-0.989090501635731-0.0i)
 -1.7  (-0.983790458590775-0.0i)
 -1.6  (-0.976348383344644-0.0i)
 -1.5  (-0.966105146475311-0.0i)
 -1.4  (-0.952285119762649-0.0i)
 -1.3  (-0.934007944940652-0.0i)
 -1.2  (-0.910313978229635-0.0i)
 -1.1  (-0.880205069574082-0.0i)
 -1.0  (-0.842700792949715-0.0i)
 -0.9  (-0.796908212422832-0.0i)
 -0.8  (-0.74210096470766-0.0i)
 -0.7  (-0.677801193837419-0.0i)
 -0.6  (-0.603856090847926-0.0i)
 -0.5  (-0.520499877813047-0.0i)
 -0.4  (-0.428392355046669-0.0i)
 -0.3  (-0.328626759459127-0.0i)
 -0.2  (-0.222702589210478-0.0i)
 -0.1  (-0.112462916018285-0.0i)
  0.0  (0.0+0.0i)
  0.1  (0.112462916018285+0.0i)
  0.2  (0.222702589210478+0.0i)
  0.3  (0.328626759459127+0.0i)
  0.4  (0.428392355046669+0.0i)
  0.5  (0.520499877813047+0.0i)
  0.6  (0.603856090847926+0.0i)
  0.7  (0.677801193837419+0.0i)
  0.8  (0.74210096470766+0.0i)
  0.9  (0.796908212422832+0.0i)
  1.0  (0.842700792949715+0.0i)
  1.1  (0.880205069574082+0.0i)
  1.2  (0.910313978229635+0.0i)
  1.3  (0.934007944940652+0.0i)
  1.4  (0.952285119762649+0.0i)
  1.5  (0.966105146475311+0.0i)
  1.6  (0.976348383344644+0.0i)
  1.7  (0.983790458590775+0.0i)
  1.8  (0.989090501635731+0.0i)
  1.9  (0.992790429235258+0.0i)
  2.0  (0.995322265018953+0.0i)

imaginary = -1
 real     erf(z)
 -2.0  (-1.00360634272565+0.011259006028815i)
 -1.9  (-1.00862466453647+0.0159521220491018i)
 -1.8  (-1.01717285222739+0.021219616040679i)
 -1.7  (-1.03067121380235+0.0261864966146945i)
 -1.6  (-1.05063170655278+0.0292628176977342i)
 -1.5  (-1.07839920749893+0.0279637112386558i)
 -1.4  (-1.1147707282614+0.0188151412037469i)
 -1.3  (-1.15951707324425-0.00258427507607144i)
 -1.2  (-1.21086998313568-0.0412801121377294i)
 -1.1  (-1.26507671107952-0.102418705652128i)
 -1.0  (-1.31615128169795-0.190453469237835i)
 -0.9  (-1.35595420408694-0.308177014108444i)
 -0.8  (-1.37469997212768-0.455724858057631i)
 -0.7  (-1.36192179631658-0.629750614611416i)
 -0.6  (-1.30782429990576-0.822990433207713i)
 -0.5  (-1.20484755831422-1.02440088160845i)
 -0.4  (-1.04917795799206-1.21996611991407i)
 -0.3  (-0.841901518935418-1.39413971221265i)
 -0.2  (-0.589523483909095-1.53174151404833i)
 -0.1  (-0.303677347945688-1.62000751312121i)
  0.0  (0.0-1.65042575879754i)
  0.1  (0.303677347945688-1.62000751312121i)
  0.2  (0.589523483909095-1.53174151404833i)
  0.3  (0.841901518935418-1.39413971221265i)
  0.4  (1.04917795799206-1.21996611991407i)
  0.5  (1.20484755831422-1.02440088160845i)
  0.6  (1.30782429990576-0.822990433207713i)
  0.7  (1.36192179631658-0.629750614611416i)
  0.8  (1.37469997212768-0.455724858057631i)
  0.9  (1.35595420408694-0.308177014108444i)
  1.0  (1.31615128169795-0.190453469237835i)
  1.1  (1.26507671107952-0.102418705652128i)
  1.2  (1.21086998313568-0.0412801121377294i)
  1.3  (1.15951707324425-0.00258427507607144i)
  1.4  (1.1147707282614+0.0188151412037469i)
  1.5  (1.07839920749893+0.0279637112386558i)
  1.6  (1.05063170655278+0.0292628176977342i)
  1.7  (1.03067121380235+0.0261864966146945i)
  1.8  (1.01717285222739+0.021219616040679i)
  1.9  (1.00862466453647+0.0159521220491018i)
  2.0  (1.00360634272565+0.011259006028815i)

for long double
imaginary = 0
 real     erf(z)
 -2.0  (-0.995322265018952734-0.0i)
 -1.9  (-0.99279042923525747-0.0i)
 -1.8  (-0.989090501635730714-0.0i)
 -1.7  (-0.983790458590774563-0.0i)
 -1.6  (-0.976348383344644007-0.0i)
 -1.5  (-0.966105146475310725-0.0i)
 -1.4  (-0.952285119762648808-0.0i)
 -1.3  (-0.934007944940652433-0.0i)
 -1.2  (-0.910313978229635376-0.0i)
 -1.1  (-0.880205069574081694-0.0i)
 -1.0  (-0.842700792949714862-0.0i)
 -0.9  (-0.796908212422832119-0.0i)
 -0.8  (-0.742100964707660474-0.0i)
 -0.7  (-0.677801193837418459-0.0i)
 -0.6  (-0.603856090847925906-0.0i)
 -0.5  (-0.520499877813046518-0.0i)
 -0.4  (-0.428392355046668433-0.0i)
 -0.3  (-0.328626759459127402-0.0i)
 -0.2  (-0.22270258921047842-0.0i)
 -0.1  (-0.112462916018284891-0.0i)
  0.0  (0.0+0.0i)
  0.1  (0.112462916018284891+0.0i)
  0.2  (0.22270258921047842+0.0i)
  0.3  (0.328626759459127402+0.0i)
  0.4  (0.428392355046668433+0.0i)
  0.5  (0.520499877813046518+0.0i)
  0.6  (0.603856090847925906+0.0i)
  0.7  (0.677801193837418459+0.0i)
  0.8  (0.742100964707660474+0.0i)
  0.9  (0.796908212422832119+0.0i)
  1.0  (0.842700792949714862+0.0i)
  1.1  (0.880205069574081694+0.0i)
  1.2  (0.910313978229635376+0.0i)
  1.3  (0.934007944940652433+0.0i)
  1.4  (0.952285119762648808+0.0i)
  1.5  (0.966105146475310725+0.0i)
  1.6  (0.976348383344644007+0.0i)
  1.7  (0.983790458590774563+0.0i)
  1.8  (0.989090501635730714+0.0i)
  1.9  (0.99279042923525747+0.0i)
  2.0  (0.995322265018952734+0.0i)

imaginary = -1
 real     erf(z)
 -2.0  (-1.00360634272565175+0.0112590060288150257i)
 -1.9  (-1.00862466453646756+0.0159521220491018292i)
 -1.8  (-1.01717285222738695+0.0212196160406789674i)
 -1.7  (-1.03067121380234699+0.0261864966146944939i)
 -1.6  (-1.05063170655277618+0.0292628176977342333i)
 -1.5  (-1.07839920749893345+0.0279637112386558509i)
 -1.4  (-1.11477072826139655+0.0188151412037469331i)
 -1.3  (-1.15951707324424979-0.00258427507607144238i)
 -1.2  (-1.21086998313567595-0.0412801121377294514i)
 -1.1  (-1.26507671107951523-0.102418705652127981i)
 -1.0  (-1.31615128169794766-0.190453469237834697i)
 -0.9  (-1.35595420408693832-0.308177014108444552i)
 -0.8  (-1.37469997212767855-0.455724858057631151i)
 -0.7  (-1.3619217963165826-0.62975061461141574i)
 -0.6  (-1.30782429990575921-0.822990433207712961i)
 -0.5  (-1.20484755831421802-1.02440088160844594i)
 -0.4  (-1.0491779579920605-1.21996611991406958i)
 -0.3  (-0.841901518935417818-1.39413971221264907i)
 -0.2  (-0.589523483909095525-1.53174151404832633i)
 -0.1  (-0.303677347945688511-1.6200075131212138i)
  0.0  (-1.08420217248550443e-19-1.65042575879754252i)
  0.1  (0.303677347945688511-1.6200075131212138i)
  0.2  (0.589523483909095525-1.53174151404832633i)
  0.3  (0.841901518935417818-1.39413971221264907i)
  0.4  (1.0491779579920605-1.21996611991406958i)
  0.5  (1.20484755831421802-1.02440088160844594i)
  0.6  (1.30782429990575921-0.822990433207712961i)
  0.7  (1.3619217963165826-0.62975061461141574i)
  0.8  (1.37469997212767855-0.455724858057631151i)
  0.9  (1.35595420408693832-0.308177014108444552i)
  1.0  (1.31615128169794766-0.190453469237834697i)
  1.1  (1.26507671107951523-0.102418705652127981i)
  1.2  (1.21086998313567595-0.0412801121377294514i)
  1.3  (1.15951707324424979-0.00258427507607144238i)
  1.4  (1.11477072826139655+0.0188151412037469331i)
  1.5  (1.07839920749893345+0.0279637112386558509i)
  1.6  (1.05063170655277618+0.0292628176977342333i)
  1.7  (1.03067121380234699+0.0261864966146944939i)
  1.8  (1.01717285222738695+0.0212196160406789674i)
  1.9  (1.00862466453646756+0.0159521220491018292i)
  2.0  (1.00360634272565175+0.0112590060288150257i)
*******************************************************************************/

extern char *c_ftosi(fcomplex);
extern char *c_dtosi(dcomplex);
extern char *c_ldtosi(lcomplex);

static void erf_c4_print(float);
static void erf_c8_print(double);
static void erf_ce_print(long double);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Gaussian Error Function");
	puts("");
	puts("for double");
	erf_c4_print(0);
	puts("");
	erf_c4_print(-1);
	puts("");
	puts("for double");
	erf_c8_print(0);
	puts("");
	erf_c8_print(-1);
	puts("");
	puts("for long double");
	erf_ce_print(0);
	puts("");
	erf_ce_print(-1);
}

static void
erf_c4_print(float imag)
{
	fcomplex cmplx;
	
	printf("imaginary = %.6g\n", imag);
	printf("%5s %10s\n", "real", "erf(z)");
	for (volatile int i = -20; i <= 20; i++)
	{
		const float x = i / 10.0;
        cmplx.real = x; cmplx.imag = imag;
        printf("% 5.1f  %s\n", x, c_ftosi(erf_c4(cmplx)));
	}
}

static void
erf_c8_print(double imag)
{
	dcomplex cmplx;
	
	printf("imaginary = %.15g\n", imag);
	printf("%5s %10s\n", "real", "erf(z)");
	for (volatile int i = -20; i <= 20; i++)
	{
		const double x = i / 10.0;
        cmplx.real = x; cmplx.imag = imag;
        printf("% 5.1f  %s\n", x, c_dtosi(erf_c8(cmplx)));
	}
}

static void
erf_ce_print(long double imag)
{
	lcomplex cmplx;
	
	printf("imaginary = %.18Lg\n", imag);
	printf("%5s %10s\n", "real", "erf(z)");
	for (volatile int i = -20; i <= 20; i++)
	{
		const long double x = i / 10.L;
        cmplx.real = x; cmplx.imag = imag;
        printf("% 5.1Lf  %s\n", x, c_ldtosi(erf_ce(cmplx)));
	}
}

/* ?P???x???f???^??????i?P?????????????????????B */
char *
c_ftosi(fcomplex z)
{
	static char s[0x200];
	char *ptr = s;
	int size;
	
	*ptr++ = '(';
	switch (fpclassify(z.real)) {
	case FP_NAN:
		*ptr++ = 'N'; *ptr++ = 'a'; *ptr++ = 'N';
		break;
	case FP_INFINITE:
		if (z.real < 0)  *ptr++ = '-';
		*ptr++ = 'I'; *ptr++ = 'n'; *ptr++ = 'f';
		*ptr++ = 'i'; *ptr++ = 'n'; *ptr++ = 'i';
		*ptr++ = 't'; *ptr++ = 'y';
		break;
	case FP_ZERO:
		if (signbit(z.real))  *ptr++ = '-';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	default:
		size = snprintf(ptr, 0x200, "%.*g", FLT_DIG, z.real);
		for (volatile int i = 0; i < size; i++)  *ptr++;
		break;
	}
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		*ptr++ = '+';
		*ptr++ = 'N'; *ptr++ = 'a'; *ptr++ = 'N';
		*ptr++ = '*';
		break;
	case FP_INFINITE:
		if (z.real < 0)  *ptr++ = '-';
		else             *ptr++ = '+';
		*ptr++ = 'I'; *ptr++ = 'n'; *ptr++ = 'f';
		*ptr++ = 'i'; *ptr++ = 'n'; *ptr++ = 'i';
		*ptr++ = 't'; *ptr++ = 'y';
		*ptr++ = '*';
		break;
	case FP_ZERO:
		if (signbit(z.real))  *ptr++ = '-';
		else                  *ptr++ = '+';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	default:
		size = snprintf(ptr, 0x200, "%+.*g", FLT_DIG, z.imag);
		for (volatile int i = 0; i < size; i++)  *ptr++;
		break;
	}
	*ptr++ = 'i';
	*ptr++ = ')'; *ptr++ = '\0';
	return s;
}

/* ?{???x???f???^??????i?P?????????????????????B */
char *
c_dtosi(dcomplex z)
{
	static char s[0x200];
	char *ptr = s;
	int size;
	
	*ptr++ = '(';
	switch (fpclassify(z.real)) {
	case FP_NAN:
		*ptr++ = 'N'; *ptr++ = 'a'; *ptr++ = 'N';
		break;
	case FP_INFINITE:
		if (z.real < 0)  *ptr++ = '-';
		*ptr++ = 'I'; *ptr++ = 'n'; *ptr++ = 'f';
		*ptr++ = 'i'; *ptr++ = 'n'; *ptr++ = 'i';
		*ptr++ = 't'; *ptr++ = 'y';
		break;
	case FP_ZERO:
		if (signbit(z.real))  *ptr++ = '-';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	default:
		size = snprintf(ptr, 0x200, "%.*g", DBL_DIG, z.real);
		for (volatile int i = 0; i < size; i++)  *ptr++;
		break;
	}
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		*ptr++ = '+';
		*ptr++ = 'N'; *ptr++ = 'a'; *ptr++ = 'N';
		*ptr++ = '*';
		break;
	case FP_INFINITE:
		if (z.real < 0)  *ptr++ = '-';
		else             *ptr++ = '+';
		*ptr++ = 'I'; *ptr++ = 'n'; *ptr++ = 'f';
		*ptr++ = 'i'; *ptr++ = 'n'; *ptr++ = 'i';
		*ptr++ = 't'; *ptr++ = 'y';
		*ptr++ = '*';
		break;
	case FP_ZERO:
		if (signbit(z.real))  *ptr++ = '-';
		else                  *ptr++ = '+';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	default:
		size = snprintf(ptr, 0x200, "%+.*g", DBL_DIG, z.imag);
		for (volatile int i = 0; i < size; i++)  *ptr++;
		break;
	}
	*ptr++ = 'i';
	*ptr++ = ')'; *ptr++ = '\0';
	return s;
}

/* long double???f???^??????i?P?????????????????????B */
char *
c_ldtosi(lcomplex z)
{
	static char s[0x200];
	char *ptr = s;
	int size;
	
	*ptr++ = '(';
	switch (fpclassify(z.real)) {
	case FP_NAN:
		*ptr++ = 'N'; *ptr++ = 'a'; *ptr++ = 'N';
		break;
	case FP_INFINITE:
		if (z.real < 0)  *ptr++ = '-';
		*ptr++ = 'I'; *ptr++ = 'n'; *ptr++ = 'f';
		*ptr++ = 'i'; *ptr++ = 'n'; *ptr++ = 'i';
		*ptr++ = 't'; *ptr++ = 'y';
		break;
	case FP_ZERO:
		if (signbit(z.real))  *ptr++ = '-';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	default:
		size = snprintf(ptr, 0x200, "%.*Lg", LDBL_DIG, z.real);
		for (volatile int i = 0; i < size; i++)  *ptr++;
		break;
	}
	switch (fpclassify(z.imag)) {
	case FP_NAN:
		*ptr++ = '+';
		*ptr++ = 'N'; *ptr++ = 'a'; *ptr++ = 'N';
		*ptr++ = '*';
		break;
	case FP_INFINITE:
		if (z.real < 0)  *ptr++ = '-';
		else             *ptr++ = '+';
		*ptr++ = 'I'; *ptr++ = 'n'; *ptr++ = 'f';
		*ptr++ = 'i'; *ptr++ = 'n'; *ptr++ = 'i';
		*ptr++ = 't'; *ptr++ = 'y';
		*ptr++ = '*';
		break;
	case FP_ZERO:
		if (signbit(z.real))  *ptr++ = '-';
		else                  *ptr++ = '+';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	default:
		size = snprintf(ptr, 0x200, "%+.*Lg", LDBL_DIG, z.imag);
		for (volatile int i = 0; i < size; i++)  *ptr++;
		break;
	}
	*ptr++ = 'i';
	*ptr++ = ')'; *ptr++ = '\0';
	return s;
}
