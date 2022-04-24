/*******************************************************************************
	GLUE-Math test suite: Complex Natural Logarithm
*******************************************************************************/
#include "../cmath/cmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // isinf(), isnan()
#include <float.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/c_log test/c_log.c cmath/log_c4.c cmath/log_c8.c cmath/log_ce.c

And test result:
GLUE-Math with POSIX standard
Test Suite:
  Natural Logarithm

for float complex
imaginary = 1
real   log(z)
-1.00  (0.346574+2.35619i)
-0.95  (0.321584+2.33056i)
-0.90  (0.296663+2.30361i)
-0.85  (0.271888+2.27529i)
-0.80  (0.247348+2.24554i)
-0.75  (0.223144+2.2143i)
-0.70  (0.199388+2.18152i)
-0.65  (0.176208+2.14717i)
-0.60  (0.153742+2.11122i)
-0.55  (0.132143+2.07364i)
-0.50  (0.111572+2.03444i)
-0.45  (0.0922013+1.99365i)
-0.40  (0.07421+1.9513i)
-0.35  (0.0577792+1.90747i)
-0.30  (0.0430889+1.86225i)
-0.25  (0.0303123+1.81578i)
-0.20  (0.0196104+1.76819i)
-0.15  (0.0111253+1.71969i)
-0.10  (0.00497508+1.67046i)
-0.05  (0.00124848+1.62075i)
 0.00  (0.0+1.5708i)
 0.05  (0.00124848+1.52084i)
 0.10  (0.00497508+1.47113i)
 0.15  (0.0111253+1.42191i)
 0.20  (0.0196104+1.3734i)
 0.25  (0.0303123+1.32582i)
 0.30  (0.0430889+1.27934i)
 0.35  (0.0577792+1.23412i)
 0.40  (0.07421+1.19029i)
 0.45  (0.0922013+1.14794i)
 0.50  (0.111572+1.10715i)
 0.55  (0.132143+1.06795i)
 0.60  (0.153742+1.03038i)
 0.65  (0.176208+0.994421i)
 0.70  (0.199388+0.96007i)
 0.75  (0.223144+0.927295i)
 0.80  (0.247348+0.896055i)
 0.85  (0.271888+0.866302i)
 0.90  (0.296663+0.837981i)
 0.95  (0.321584+0.811034i)
 1.00  (0.346574+0.785398i)

for double complex
imaginary = 1
real   log(z)
-1.00  (0.346573590279973+2.35619449019234i)
-0.95  (0.321584405376852+2.33055908167067i)
-0.90  (0.296663422638867+2.3036114285814i)
-0.85  (0.271888361952838+2.27529039103711i)
-0.80  (0.247348120918053+2.24553726901845i)
-0.75  (0.22314355131421+2.21429743558818i)
-0.70  (0.199388059978684+2.18152229118411i)
-0.65  (0.176207943509174+2.14717154738608i)
-0.60  (0.15374234987398+2.11121582706548i)
-0.55  (0.132142747322692+2.07363953772276i)
-0.50  (0.111571775657105+2.0344439357957i)
-0.45  (0.0922013614988895+1.99365025292784i)
-0.40  (0.0742100025591366+1.95130270390726i)
-0.35  (0.0577791703171361+1.90747114618162i)
-0.30  (0.043088848120526+1.86225312127276i)
-0.25  (0.0303123109082175+1.81577498992176i)
-0.20  (0.0196103565766406+1.76819188664478i)
-0.15  (0.0111253044674098+1.71968627440439i)
-0.10  (0.00497516542658394+1.67046497928606i)
-0.05  (0.00124844009929359+1.62075472251684i)
 0.00  (0.0+1.5707963267949i)
 0.05  (0.00124844009929359+1.52083793107295i)
 0.10  (0.00497516542658394+1.47112767430373i)
 0.15  (0.0111253044674098+1.4219063791854i)
 0.20  (0.0196103565766406+1.37340076694502i)
 0.25  (0.0303123109082175+1.32581766366803i)
 0.30  (0.043088848120526+1.27933953231703i)
 0.35  (0.0577791703171361+1.23412150740817i)
 0.40  (0.0742100025591366+1.19028994968253i)
 0.45  (0.0922013614988895+1.14794240066196i)
 0.50  (0.111571775657105+1.10714871779409i)
 0.55  (0.132142747322692+1.06795311586704i)
 0.60  (0.15374234987398+1.03037682652431i)
 0.65  (0.176207943509174+0.994421106203713i)
 0.70  (0.199388059978684+0.960070362405688i)
 0.75  (0.22314355131421+0.927295218001612i)
 0.80  (0.247348120918053+0.896055384571344i)
 0.85  (0.271888361952838+0.866302262552679i)
 0.90  (0.296663422638867+0.83798122500839i)
 0.95  (0.321584405376852+0.811033571919126i)
 1.00  (0.346573590279973+0.785398163397448i)

for long double complex
imaginary = 1
real   log(z)
-1.00  (0.346573590279972655+2.35619449019234493i)
-0.95  (0.321584405376851902+2.33055908167066743i)
-0.90  (0.2966634226388672+2.30361142858140322i)
-0.85  (0.271888361952838281+2.27529039103711432i)
-0.80  (0.247348120918053549+2.24553726901844931i)
-0.75  (0.223143551314209756+2.21429743558818101i)
-0.70  (0.199388059978683866+2.18152229118410521i)
-0.65  (0.176207943509174477+2.14717154738608032i)
-0.60  (0.15374234987398031+2.11121582706548076i)
-0.55  (0.132142747322692484+2.07363953772275748i)
-0.50  (0.111571775657104878+2.03444393579570274i)
-0.45  (0.0922013614988896009+1.99365025292783734i)
-0.40  (0.0742100025591366466+1.95130270390726152i)
-0.35  (0.0577791703171361463+1.90747114618162378i)
-0.30  (0.0430888481205261631+1.8622531212727637i)
-0.25  (0.0303123109082174213+1.81577498992176077i)
-0.20  (0.0196103565766406502+1.76819188664477739i)
-0.15  (0.0111253044674098785+1.71968627440439386i)
-0.10  (0.00497516542658404189+1.67046497928605865i)
-0.05  (0.00124844009929359957+1.62075472251683938i)
 0.00  (0.0+1.57079632679489662i)
 0.05  (0.00124844009929359957+1.52083793107295386i)
 0.10  (0.00497516542658404189+1.47112767430373459i)
 0.15  (0.0111253044674098785+1.42190637918539937i)
 0.20  (0.0196103565766406502+1.37340076694501585i)
 0.25  (0.0303123109082174213+1.32581766366803247i)
 0.30  (0.0430888481205261631+1.27933953231702954i)
 0.35  (0.0577791703171361463+1.23412150740816946i)
 0.40  (0.0742100025591366466+1.19028994968253171i)
 0.45  (0.0922013614988896009+1.1479424006619559i)
 0.50  (0.111571775657104878+1.1071487177940905i)
 0.55  (0.132142747322692484+1.06795311586703576i)
 0.60  (0.15374234987398031+1.03037682652431248i)
 0.65  (0.176207943509174477+0.994421106203712924i)
 0.70  (0.199388059978683866+0.960070362405688033i)
 0.75  (0.223143551314209756+0.927295218001612233i)
 0.80  (0.247348120918053549+0.896055384571343929i)
 0.85  (0.271888361952838281+0.866302262552678916i)
 0.90  (0.2966634226388672+0.837981225008390015i)
 0.95  (0.321584405376851902+0.811033571919125814i)
 1.00  (0.346573590279972655+0.78539816339744831i)
*******************************************************************************/


extern int c_isnan(dcomplex);
extern int c_isinf(dcomplex);
extern char *c_ftosi(fcomplex);
extern char *c_dtosi(dcomplex);
extern char *c_ldtosi(lcomplex);

static void log_c4_print(float);
static void log_c8_print(double);
static void log_ce_print(long double);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Natural Logarithm");
	puts("");
	puts("for float complex");
	log_c4_print(1);
	puts("");
	puts("for double complex");
	log_c8_print(1);
	puts("");
	puts("for long double complex");
	log_ce_print(1);
	
	return 0;
}



static void
log_c4_print(float imag)
{
	printf("imaginary = %g\n", imag);
	puts("real   log(z)");
	for (volatile int i = -20; i <= 20; i++)
	{
		const float real = i / 20.0;
		const fcomplex z = { real, imag };
		printf("% 1.2f  %s\n", real, c_ftosi(log_c4(z)));
	}
}

static void
log_c8_print(double imag)
{
	printf("imaginary = %g\n", imag);
	puts("real   log(z)");
	for (volatile int i = -20; i <= 20; i++)
	{
		const double real = i / 20.0;
		const dcomplex z = { real, imag };
		printf("% 1.2f  %s\n", real, c_dtosi(log_c8(z)));
	}
}

static void
log_ce_print(long double imag)
{
	printf("imaginary = %Lg\n", imag);
	puts("real   log(z)");
	for (volatile int i = -20; i <= 20; i++)
	{
		const long double real = i / 20.0;
		const lcomplex z = { real, imag };
		printf("% 1.2Lf  %s\n", real, c_ldtosi(log_ce(z)));
	}
}


/******************************************************************************/

/*
 * 複素数版isnan()。実部または虚部が非数であるかどうかを検査する。
 */
int
c_isnan(dcomplex z)
{
	return z.real != z.real || z.imag != z.imag;
}

/*
 *  複素数版isinf()。引数が無限複素量であるかどうかを検査する。大概は実部で判断する。
 *  実部または虚部が非数であった場合、無限複素量とはみなされない。
 *  実部が有限であって虚部が無限であった場合、複素量は無限積であるとし、実部の符号を返す。
 */
int
c_isinf(dcomplex z)
{
	int y = 0;
	if (z.real != z.real || z.imag != z.imag)
		y = 0;
	else if (isinf(z.imag))
		y = z.real < 0 ? -1 : 1;
	else
		y = isinf(z.real);
	return y;
}

/* 単精度複素数型を虚数i単位で文字列に変換する。 */
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

/* long double複素数型を虚数i単位で文字列に変換する。 */
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
