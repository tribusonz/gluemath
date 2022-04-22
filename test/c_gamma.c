/*******************************************************************************
	GLUE-Math test suite: Complex Gamma Function
*******************************************************************************/
#include "../cmath/cmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // isinf(), isnan()
#include <float.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/cgamma test/c_gamma.c cmath/gamma_c8.c

And test result:
GLUE-Math with POSIX standard
Test Suite:
  Euler Gamma Function

for double
imaginary = 0
 real   Gamma(z)
 -5.0  (-Infinity-0.0i)
 -4.5  (-0.0600196013005042-0.0i)
 -4.0  (Infinity+0.0i)
 -3.5  (0.270088205852269+0.0i)
 -3.0  (-Infinity-0.0i)
 -2.5  (-0.945308720482942-0.0i)
 -2.0  (Infinity+0.0i)
 -1.5  (2.36327180120735+0.0i)
 -1.0  (-Infinity-0.0i)
 -0.5  (-3.54490770181103-0.0i)
  0.0  (Infinity+0.0i)
  0.5  (1.77245385090551+0.0i)
  1.0  (1+0.0i)
  1.5  (0.886226925452754+0.0i)
  2.0  (1+0.0i)
  2.5  (1.32934038817913+0.0i)
  3.0  (2+0.0i)
  3.5  (3.32335097044783+0.0i)
  4.0  (6+0.0i)
  4.5  (11.6317283965674+0.0i)
  5.0  (24+0.0i)

imaginary = -1
 real   Gamma(z)
 -5.0  (-0.0024563000337025+0.00034798513016534i)
 -4.5  (0.000267569823011507+0.00571041008716417i)
 -4.0  (0.0126294852986779+0.000716374382875809i)
 -3.5  (0.0045063458836124-0.0259644152152503i)
 -3.0  (-0.0498015668118356-0.0154949828301811i)
 -2.5  (-0.0417366258078936+0.0863691073697635i)
 -2.0  (0.133909717605326+0.0962865153023789i)
 -1.5  (0.190710671889498-0.174186142616515i)
 -1.0  (-0.171532919908273-0.326482748210084i)
 -0.5  (-0.460252150450762+0.0705685420352751i)
  0.0  (-0.154949828301811+0.498015668118357i)
  0.5  (0.300694617260656+0.424967879433124i)
  1.0  (0.498015668118356+0.154949828301811i)
  1.5  (0.575315188063452-0.0882106775440938i)
  2.0  (0.652965496420167-0.343065839816545i)
  2.5  (0.774762104551084-0.707631204379592i)
  3.0  (0.962865153023788-1.33909717605326i)
  3.5  (1.22927405699812-2.54384011550006i)
  4.0  (1.54949828301811-4.98015668118356i)
  4.5  (1.75861908399334-10.1327144612483i)
  5.0  (1.21783645088887-21.4701250077523i)
*******************************************************************************/

/* 倍精度複素数型を虚数i単位で文字列に変換する。 */
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

static void gamma_c8_print(double);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Euler Gamma Function");
	puts("");
	puts("for double");
	gamma_c8_print(0);
	puts("");
	gamma_c8_print(-1);
}

static void
gamma_c8_print(double imag)
{
	dcomplex cmplx;
	
	printf("imaginary = %.15g\n", imag);
	printf("%5s %10s\n", "real", "Gamma(z)");
	for (volatile int i = -50; i <= 50; i += 5)
	{
		const double x = i / 10.0;
        cmplx.real = x; cmplx.imag = imag;
        printf("% 5.1f  %s\n", x, c_dtosi(gamma_c8(cmplx)));
	}
}
