/*******************************************************************************
	GLUE-Math test suite: Complex Exponential Function
*******************************************************************************/
#include "../cmath/cmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // isinf(), isnan()
#include <float.h>
/*******************************************************************************
MinGW 64bit gcc build:
$ gcc -Wall -Wextra -O3 -o bin/c_exp test/c_exp.c cmath/exp_c4.c cmath/exp_c8.c cmath/exp_ce.c

And test result:
GLUE-Math with POSIX standard
Test Suite:
  Exponential Function

for float complex
imaginary = 1
real   exp(z)
-1.00  (0.198766+0.30956i)
-0.95  (0.208957+0.325431i)
-0.90  (0.21967+0.342117i)
-0.85  (0.230933+0.359657i)
-0.80  (0.242773+0.378097i)
-0.75  (0.255221+0.397483i)
-0.70  (0.268306+0.417862i)
-0.65  (0.282063+0.439286i)
-0.60  (0.296524+0.461809i)
-0.55  (0.311727+0.485487i)
-0.50  (0.32771+0.510378i)
-0.45  (0.344512+0.536546i)
-0.40  (0.362175+0.564055i)
-0.35  (0.380745+0.592975i)
-0.30  (0.400266+0.623377i)
-0.25  (0.420788+0.655338i)
-0.20  (0.442362+0.688938i)
-0.15  (0.465043+0.724261i)
-0.10  (0.488886+0.761394i)
-0.05  (0.513951+0.800432i)
 0.00  (0.540302+0.841471i)
 0.05  (0.568004+0.884614i)
 0.10  (0.597126+0.929969i)
 0.15  (0.627742+0.97765i)
 0.20  (0.659927+1.02777i)
 0.25  (0.693762+1.08047i)
 0.30  (0.729332+1.13587i)
 0.35  (0.766725+1.1941i)
 0.40  (0.806036+1.25533i)
 0.45  (0.847363+1.31969i)
 0.50  (0.890808+1.38735i)
 0.55  (0.936481+1.45848i)
 0.60  (0.984495+1.53326i)
 0.65  (1.03497+1.61187i)
 0.70  (1.08804+1.69451i)
 0.75  (1.14382+1.78139i)
 0.80  (1.20246+1.87273i)
 0.85  (1.26412+1.96875i)
 0.90  (1.32893+2.06968i)
 0.95  (1.39706+2.1758i)
 1.00  (1.46869+2.28736i)

for double complex
imaginary = 1
real   exp(z)
-1.00  (0.198766110346413+0.309559875653112i)
-0.95  (0.208957066746271+0.325431349871873i)
-0.90  (0.219670524653871+0.342116571974933i)
-0.85  (0.230933273294371+0.359657263708495i)
-0.80  (0.242773475405877+0.37809728593843i)
-0.75  (0.255220737660954+0.397482748325293i)
-0.70  (0.268306184698729+0.417862124622486i)
-0.65  (0.282062536952701+0.439286373885896i)
-0.60  (0.296524192468869+0.461809067898073i)
-0.55  (0.311727312918763+0.485486525125597i)
-0.50  (0.32770991402246+0.510377951544573i)
-0.45  (0.344511960607684+0.536545588686412i)
-0.40  (0.362175466542693+0.564054869274084i)
-0.35  (0.380744599792835+0.592974580838001i)
-0.30  (0.400265792863465+0.623377037720679i)
-0.25  (0.420787858905393+0.655338261900256i)
-0.20  (0.442362113773192+0.68893817308504i)
-0.15  (0.465042504341559+0.724260788554405i)
-0.10  (0.488885743400603+0.761394433245753i)
-0.05  (0.513951451467359+0.800431960612865i)
 0.00  (0.54030230586814+0.841470984807897i)
 0.05  (0.568004197464493+0.88461412476761i)
 0.10  (0.597126395414681+0.929969260814162i)
 0.15  (0.627741720382655+0.977649804412105i)
 0.20  (0.659926726627645+1.02777498175612i)
 0.25  (0.693761893429686+1.0804701318986i)
 0.30  (0.729331826329732+1.13586702016259i)
 0.35  (0.766725468687585+1.1941041676237i)
 0.40  (0.806036324086619+1.25532719748494i)
 0.45  (0.84736269014144+1.31968919921064i)
 0.50  (0.890807904293128+1.38735111132976i)
 0.55  (0.936480602206666+1.45848212386614i)
 0.60  (0.984494989416681+1.53326010140158i)
 0.65  (1.03497112690078+1.61187202783006i)
 0.70  (1.08803523129451+1.69451447391475i)
 0.75  (1.14381999049872+1.7813940888174i)
 0.80  (1.2024648954684+1.87272811682884i)
 0.85  (1.26411658901275+1.96874494059286i)
 0.90  (1.32892923247855+2.0696846521818i)
 0.95  (1.39706489123387+2.1757996534518i)
 1.00  (1.46869393991588+2.28735528717884i)

for long double complex
imaginary = 1
real   exp(z)
-1.00  (0.198766110346412941+0.309559875653112198i)
-0.95  (0.208957066746271317+0.325431349871872946i)
-0.90  (0.219670524653870667+0.34211657197493332i)
-0.85  (0.230933273294371045+0.359657263708495107i)
-0.80  (0.242773475405877425+0.378097285938430428i)
-0.75  (0.25522073766095448+0.397482748325292831i)
-0.70  (0.268306184698729237+0.417862124622485846i)
-0.65  (0.282062536952701072+0.439286373885895456i)
-0.60  (0.296524192468868864+0.461809067898073353i)
-0.55  (0.31172731291876292+0.485486525125597269i)
-0.50  (0.327709914022459832+0.510377951544572805i)
-0.45  (0.344511960607683918+0.536545588686412319i)
-0.40  (0.362175466542693474+0.564054869274083912i)
-0.35  (0.380744599792835398+0.592974580838001136i)
-0.30  (0.40026579286346456+0.623377037720678743i)
-0.25  (0.420787858905392922+0.655338261900256029i)
-0.20  (0.442362113773192123+0.688938173085040131i)
-0.15  (0.465042504341559175+0.724260788554405167i)
-0.10  (0.488885743400602828+0.761394433245753234i)
-0.05  (0.513951451467359296+0.800431960612864453i)
 0.00  (0.540302305868139717+0.841470984807896507i)
 0.05  (0.56800419746449313+0.884614124767610031i)
 0.10  (0.597126395414681348+0.929969260814162322i)
 0.15  (0.627741720382655308+0.977649804412105064i)
 0.20  (0.659926726627645573+1.02777498175611917i)
 0.25  (0.693761893429685651+1.0804701318986035i)
 0.30  (0.729331826329731975+1.13586702016259219i)
 0.35  (0.766725468687585282+1.19410416762369568i)
 0.40  (0.806036324086618705+1.2553271974849422i)
 0.45  (0.847362690141439871+1.31968919921063682i)
 0.50  (0.89080790429312862+1.38735111132976336i)
 0.55  (0.936480602206665657+1.45848212386613577i)
 0.60  (0.984494989416680578+1.53326010140158455i)
 0.65  (1.03497112690077602+1.61187202783005766i)
 0.70  (1.08803523129450784+1.69451447391474973i)
 0.75  (1.14381999049871821+1.78139408881740062i)
 0.80  (1.20246489546840095+1.87272811682883718i)
 0.85  (1.26411658901274692+1.96874494059285836i)
 0.90  (1.3289292324785503+2.06968465218180462i)
 0.95  (1.39706489123387362+2.17579965345179557i)
 1.00  (1.46869393991588516+2.28735528717884239i)
*******************************************************************************/

extern int c_isnan(dcomplex);
extern int c_isinf(dcomplex);
extern char *c_ftosi(fcomplex);
extern char *c_dtosi(dcomplex);
extern char *c_ldtosi(lcomplex);

static void exp_c4_print(float);
static void exp_c8_print(double);
static void exp_ce_print(long double);

int
main(void)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	puts("  Exponential Function");
	puts("");
	puts("for float complex");
	exp_c4_print(1);
	puts("");
	puts("for double complex");
	exp_c8_print(1);
	puts("");
	puts("for long double complex");
	exp_ce_print(1);
	
	return 0;
}



static void
exp_c4_print(float imag)
{
	printf("imaginary = %g\n", imag);
	puts("real   exp(z)");
	for (volatile int i = -20; i <= 20; i++)
	{
		const float real = i / 20.0;
		const fcomplex z = { real, imag };
		printf("% 1.2f  %s\n", real, c_ftosi(exp_c4(z)));
	}
}

static void
exp_c8_print(double imag)
{
	printf("imaginary = %g\n", imag);
	puts("real   exp(z)");
	for (volatile int i = -20; i <= 20; i++)
	{
		const double real = i / 20.0;
		const dcomplex z = { real, imag };
		printf("% 1.2f  %s\n", real, c_dtosi(exp_c8(z)));
	}
}

static void
exp_ce_print(long double imag)
{
	printf("imaginary = %Lg\n", imag);
	puts("real   exp(z)");
	for (volatile int i = -20; i <= 20; i++)
	{
		const long double real = i / 20.0;
		const lcomplex z = { real, imag };
		printf("% 1.2Lf  %s\n", real, c_ldtosi(exp_ce(z)));
	}
}


/******************************************************************************/

/*
 * •¡‘f””Åisnan()BŽÀ•”‚Ü‚½‚Í‹••”‚ª”ñ”‚Å‚ ‚é‚©‚Ç‚¤‚©‚ðŒŸ¸‚·‚éB
 */
int
c_isnan(dcomplex z)
{
	return z.real != z.real || z.imag != z.imag;
}

/*
 *  •¡‘f””Åisinf()Bˆø”‚ª–³ŒÀ•¡‘f—Ê‚Å‚ ‚é‚©‚Ç‚¤‚©‚ðŒŸ¸‚·‚éB‘åŠT‚ÍŽÀ•”‚Å”»’f‚·‚éB
 *  ŽÀ•”‚Ü‚½‚Í‹••”‚ª”ñ”‚Å‚ ‚Á‚½ê‡A–³ŒÀ•¡‘f—Ê‚Æ‚Í‚Ý‚È‚³‚ê‚È‚¢B
 *  ŽÀ•”‚ª—LŒÀ‚Å‚ ‚Á‚Ä‹••”‚ª–³ŒÀ‚Å‚ ‚Á‚½ê‡A•¡‘f—Ê‚Í–³ŒÀÏ‚Å‚ ‚é‚Æ‚µAŽÀ•”‚Ì•„†‚ð•Ô‚·B
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

/* ’P¸“x•¡‘f”Œ^‚ð‹•”i’PˆÊ‚Å•¶Žš—ñ‚É•ÏŠ·‚·‚éB */
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

/* ”{¸“x•¡‘f”Œ^‚ð‹•”i’PˆÊ‚Å•¶Žš—ñ‚É•ÏŠ·‚·‚éB */
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

/* long double•¡‘f”Œ^‚ð‹•”i’PˆÊ‚Å•¶Žš—ñ‚É•ÏŠ·‚·‚éB */
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
