/*******************************************************************************
	Test Suites
*******************************************************************************/
#ifndef GML_TESTSUITE_H
#define GML_TESTSUITE_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include "../sys/float/signbit.h"
#include "../sys/float/huge_val_nan.h"
#include "../sys/float/info.h"
#include "../internal/sys/primitive/float/info.h"
#include "../sys/float/fpclassify.h"
#include "../internal/sys/primitive/float/fpclassify.h"

#define UNARY_AUTO 0
#define UNARY_ENABLE 1
#define UNARY_DISABLE 2
#define UNARY_PADDING 3
#define NOTATION_E 0
#define NOTATION_F 1
#define NOTATION_G 2

static inline void rmath_title_print(const char*);
static inline void rmath_methname_print(const char*);
static inline void rmath_pole_title_print(void);
static inline void
rmath_check_exp(float ef(float), double ed(double), long double eld(long double));
static inline void listiter_tabname_print(const char*);
static inline void listiter_tabitem_print(double, int, int, float, double, long double);

static inline char *flt_inspect_f(float, int);
static inline char *dbl_inspect_f(double, int);
static inline char *ldbl_inspect_f(long double, int);

static inline char *flt_inspect_g(float, int);
static inline char *dbl_inspect_g(double, int);
static inline char *ldbl_inspect_g(long double, int);

static inline void
rmath_title_print(const char *title)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	printf("  %*s\n", (int)strlen(title), title);
	puts("");
	fflush(stdout);
}

static inline void
rmath_methname_print(const char *meth)
{
	printf(">>> RMath.%*s\n", (int)strlen(meth), meth);
	fflush(stdout);
}

static inline void
rmath_pole_title_print(void)
{
	puts("[Property of Pole]");
	fflush(stdout);
}

static inline void
rmath_check_exp(float ef(float), double ed(double), long double eld(long double))
{
	int i;

	puts("  - CHECK THE MACHINE CONSTANT IN THE ARGUMENT -");
	puts("");
	puts("  List Table Details:");
	puts("  mac_emax := Maximum exponent of the calculation bound");
	puts("  mac_emin := Minimum exponent of the calculation bound");
	puts("  arg+inf  := Solution the argument is +Infinity");
	puts("  arg-inf  := Solution the argument is -Infinity");
	puts("  arg_nan  := Solution the argument is NaN");
	puts("");

	printf("  %4.4s  %8.8s  %8.8s  %8.8s  %8.8s  %8.8s\n",
	"type", "mac_emax", "mac_emin", "arg+inf", "arg-inf", "arg_nan");

	printf("  %4.4s", "flt");
	for (i = 0; !isinf(ef(i)); i++);
	printf("  %8d", i);
	for (i = 0; 0.0 != ef(i); i--);
	printf("  %8d", i);
	printf("  %8.8s", flt_inspect_g(ef( HUGE_VALF), UNARY_AUTO));
	printf("  %8.8s", flt_inspect_g(ef(-HUGE_VALF), UNARY_AUTO));
	printf("  %8.8s", flt_inspect_g(ef(NAN), UNARY_AUTO));
	puts("");

	printf("  %4.4s", "dbl");
	for (i = 0; !isinf(ed(i)); i++);
	printf("  %8d", i);
	for (i = 0; 0.0 != ed(i); i--);
	printf("  %8d", i);
	printf("  %8.8s", dbl_inspect_g(ed( HUGE_VAL), UNARY_AUTO));
	printf("  %8.8s", dbl_inspect_g(ed(-HUGE_VAL), UNARY_AUTO));
	printf("  %8.8s", dbl_inspect_g(ed(NAN), UNARY_AUTO));
	puts("");

	printf("  %4.4s", "ldbl");
	for (i = 0; !isinf(eld(i)); i++);
	printf("  %8d", i);
	for (i = 0; 0.0 != eld(i); i--);
	printf("  %8d", i);
	printf("  %8.8s", ldbl_inspect_g(eld( HUGE_VALL), UNARY_AUTO));
	printf("  %8.8s", ldbl_inspect_g(eld(-HUGE_VALL), UNARY_AUTO));
	printf("  %8.8s", ldbl_inspect_g(eld(NAN), UNARY_AUTO));
	puts("");

	fflush(stdout);
}


static inline void
listiter_tabname_print(const char *arg)
{
	int argsize = (int)strlen(arg);
	static int check = 0;
	if (check == 0)
	{
		get_flt_info(); get_dbl_info(); get_ldbl_info();
		check = 1;
	}

	printf("  %*.*s   %-*.*s  %-*.*s  %-*.*s\n",
	       argsize, argsize, arg,
	       flt_info.dig + 2,  flt_info.dig + 2,  "float",
	       dbl_info.dig + 2,  dbl_info.dig + 2,  "double",
	       ldbl_info.dig + 2, ldbl_info.dig + 2, "long double");
	fflush(stdout);
}

static inline void
listiter_tabitem_print(
  double x, int x_int_size, int x_dec_size,
  float flt, double dbl, long double ldbl)
{
	static int check = 0;
	if (check == 0)
	{
		get_flt_info(); get_dbl_info(); get_ldbl_info();
		check = 1;
	}

	printf("% *.*f  %-*.*s %-*.*s %-*.*s\n", x_int_size, x_dec_size, x,
	        flt_info.dig + 3,  flt_info.dig + 3, flt_inspect_f(flt, UNARY_PADDING),
	        dbl_info.dig + 3,  dbl_info.dig + 3, dbl_inspect_f(dbl, UNARY_PADDING),
	        ldbl_info.dig + 3, ldbl_info.dig + 3, ldbl_inspect_f(ldbl, UNARY_PADDING));
	fflush(stdout);
}


static inline char *
__print_nan(int unary)
{
	static char s[5];
	char *ptr = s;

	if (unary == UNARY_PADDING)
		*ptr++ = ' ';
	*ptr++ = 'N'; *ptr++ = 'a'; *ptr++ = 'N';
	*ptr++ = '\0';
	return s;
}

static inline char *
__print_inf(int sign, int unary)
{
	static char s[0x200];
	char *ptr = s;
	if (sign == 1 && unary == UNARY_ENABLE)
		*ptr++ = '+';
	else if (sign == -1 && unary != UNARY_DISABLE)
		*ptr++ = '-';
	else if (unary == UNARY_PADDING)
		*ptr++ = ' ';
	*ptr++ = 'I'; *ptr++ = 'n'; *ptr++ = 'f';
	*ptr++ = 'i'; *ptr++ = 'n'; *ptr++ = 'i';
	*ptr++ = 't'; *ptr++ = 'y';
	*ptr++ = '\0';
	return s;
}

/**** Exponent form ****/

/**** (Decimal) FP form ****/

static inline char *
flt_inspect_f(float x, int unary)
{
	static char s[0x200];
	char *ptr = s;
	int size = 0;
	
	switch (fpclassify(x)) {
	case FP_NAN:
		return __print_nan(unary);
		break;
	case FP_INFINITE:
		if (x < 0)
			return __print_inf(-1, unary);
		else
			return __print_inf( 1, unary);
		break;
	case FP_ZERO:
		if (!signbit(x) && unary == UNARY_ENABLE)
			*ptr++ = '+';
		else if (signbit(x) && unary != UNARY_DISABLE)
			*ptr++ = '-';
		else if (unary == UNARY_PADDING)
			*ptr++ = ' ';
		*ptr++ = '0'; *ptr++ = '.';
		for (volatile int i = 1; i <= flt_info.dig; i++)
			*ptr++ = '0';
		break;
	case FP_SUBNORMAL:
	case FP_NORMAL:
	default:
		if (x > 0)
		{
			if (unary == UNARY_ENABLE)
				size = (int)snprintf(s+1, 0x200, "%+*.*f",
				                     flt_info.dig, flt_info.dig, x);
			else if (unary == UNARY_PADDING)
				size = (int)snprintf(s, 0x200, "% *.*f", 
				                     flt_info.dig, flt_info.dig, x);
			else
				size = (int)snprintf(s, 0x200, "%*.*f", 
				                     flt_info.dig, flt_info.dig, x);
			ptr = &s[size];
		}
		else /* if (x < 0) */
		{
			size = (int)snprintf(s, 0x200, "%+*.*f",
			                     flt_info.dig, flt_info.dig, x);
			if (unary == UNARY_DISABLE)
				{
					*ptr = '\0';
					*s += 1;
					ptr = &s[size+2];
				}
			else
				ptr = &s[size+1];
		}
		break;
	}
	*ptr++ = '\0';
	return s;
}

static inline char *
dbl_inspect_f(double x, int unary)
{
	static char s[0x200];
	char *ptr = s;
	int size = 0;
	
	switch (fpclassify(x)) {
	case FP_NAN:
		return __print_nan(unary);
		break;
	case FP_INFINITE:
		if (x < 0)
			return __print_inf(-1, unary);
		else
			return __print_inf( 1, unary);
		break;
	case FP_ZERO:
		if (!signbit(x) && unary == UNARY_ENABLE)
			*ptr++ = '+';
		else if (signbit(x) && unary != UNARY_DISABLE)
			*ptr++ = '-';
		else if (unary == UNARY_PADDING)
			*ptr++ = ' ';
		*ptr++ = '0'; *ptr++ = '.';
		for (volatile int i = 1; i <= dbl_info.dig; i++)
			*ptr++ = '0';
		break;
	case FP_SUBNORMAL:
	case FP_NORMAL:
	default:
		if (x > 0)
		{
			if (unary == UNARY_ENABLE)
				size = (int)snprintf(s+1, 0x200, "%+*.*lf",
				                     dbl_info.dig, dbl_info.dig, x);
			else if (unary == UNARY_PADDING)
				size = (int)snprintf(s, 0x200, "% *.*lf", 
				                     dbl_info.dig, dbl_info.dig, x);
			else
				size = (int)snprintf(s, 0x200, "%*.*lf", 
				                     dbl_info.dig, dbl_info.dig, x);
			ptr = &s[size];
		}
		else /* if (x < 0) */
		{
			size = (int)snprintf(s, 0x200, "%+*.*lf",
			                     dbl_info.dig, dbl_info.dig, x);
			if (unary == UNARY_DISABLE)
				{
					*ptr = '\0';
					*s += 1;
					ptr = &s[size+2];
				}
			else
				ptr = &s[size+1];
		}
		break;
	}
	*ptr++ = '\0';
	return s;
}

static inline char *
ldbl_inspect_f(long double x, int unary)
{
	static char s[0x200];
	char *ptr = s;
	int size = 0;
	
	switch (fpclassify(x)) {
	case FP_NAN:
		return __print_nan(unary);
		break;
	case FP_INFINITE:
		if (x < 0)
			return __print_inf(-1, unary);
		else
			return __print_inf( 1, unary);
		break;
	case FP_ZERO:
		if (!signbit(x) && unary == UNARY_ENABLE)
			*ptr++ = '+';
		else if (signbit(x) && unary != UNARY_DISABLE)
			*ptr++ = '-';
		else if (unary == UNARY_PADDING)
			*ptr++ = ' ';
		*ptr++ = '0'; *ptr++ = '.';
		for (volatile int i = 1; i <= ldbl_info.dig; i++)
			*ptr++ = '0';
		break;
	case FP_SUBNORMAL:
	case FP_NORMAL:
	default:
		if (x > 0)
		{
			if (unary == UNARY_ENABLE)
				size = (int)snprintf(s+1, 0x200, "%+*.*Lf",
				                     ldbl_info.dig, ldbl_info.dig, x);
			else if (unary == UNARY_PADDING)
				size = (int)snprintf(s, 0x200, "% *.*Lf", 
				                     ldbl_info.dig, ldbl_info.dig, x);
			else
				size = (int)snprintf(s, 0x200, "%*.*Lf", 
				                     ldbl_info.dig, ldbl_info.dig, x);
			ptr = &s[size];
		}
		else /* if (x < 0) */
		{
			size = (int)snprintf(s, 0x200, "%+*.*Lf",
			                     ldbl_info.dig, ldbl_info.dig, x);
			if (unary == UNARY_DISABLE)
				{
					*ptr = '\0';
					*s += 1;
					ptr = &s[size+2];
				}
			else
				ptr = &s[size+1];
		}
		break;
	}
	*ptr++ = '\0';
	return s;
}

/**** Generic Form ****/

static inline char *
flt_inspect_g(float x, int unary)
{
	static char s[0x200];
	char *ptr = s;
	int size = 0;

	switch (fpclassify(x)) {
	case FP_NAN:
		return __print_nan(unary);
		break;
	case FP_INFINITE:
		if (x < 0)
			return __print_inf(-1, unary);
		else
			return __print_inf( 1, unary);
		break;
	case FP_ZERO:
		if (!signbit(x) && unary == UNARY_ENABLE)
			*ptr++ = '+';
		else if (signbit(x) && unary != UNARY_DISABLE)
			*ptr++ = '-';
		else
			*ptr++ = ' ';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	case FP_SUBNORMAL:
	case FP_NORMAL:
	default:
		if (x > 0)
		{
			if (unary == UNARY_ENABLE)
				size = (int)snprintf(s+1, 0x200, "%+.*g", flt_info.dig, x);
			else
				size = (int)snprintf(s, 0x200, "% .*g", flt_info.dig, x);
			ptr = &s[size];
		}
		else /* if (x < 0) */
		{
			size = (int)snprintf(s, 0x200, "%.*g", flt_info.dig, x);
			if (unary == UNARY_DISABLE)
				*ptr = ' ';
			ptr = &s[size+1];
		}
		break;
	}
	*ptr++ = '\0';
	return s;
}

static inline char *
dbl_inspect_g(double x, int unary)
{
	static char s[0x200];
	char *ptr = s;
	int size = 0;

	switch (fpclassify(x)) {
	case FP_NAN:
		return __print_nan(unary);
		break;
	case FP_INFINITE:
		if (x < 0)
			return __print_inf(-1, unary);
		else
			return __print_inf( 1, unary);
		break;
	case FP_ZERO:
		if (!signbit(x) && unary == UNARY_ENABLE)
			*ptr++ = '+';
		else if (signbit(x) && unary != UNARY_DISABLE)
			*ptr++ = '-';
		else
			*ptr++ = ' ';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	case FP_SUBNORMAL:
	case FP_NORMAL:
	default:
		if (x > 0)
		{
			if (unary == UNARY_ENABLE)
				size = (int)snprintf(s+1, 0x200, "%+.*g", dbl_info.dig, x);
			else
				size = (int)snprintf(s, 0x200, "% .*g", dbl_info.dig, x);
			ptr = &s[size];
		}
		else /* if (x < 0) */
		{
			size = (int)snprintf(s, 0x200, "%.*g", dbl_info.dig, x);
			if (unary == UNARY_DISABLE)
				*ptr = ' ';
			ptr = &s[size+1];
		}
		break;
	}
	*ptr++ = '\0';
	return s;
}

static inline char *
ldbl_inspect_g(long double x, int unary)
{
	static char s[0x200];
	char *ptr = s;
	int size = 0;

	switch (fpclassify(x)) {
	case FP_NAN:
		return __print_nan(unary);
		break;
	case FP_INFINITE:
		if (x < 0)
			return __print_inf(-1, unary);
		else
			return __print_inf( 1, unary);
		break;
	case FP_ZERO:
		if (!signbit(x) && unary == UNARY_ENABLE)
			*ptr++ = '+';
		else if (signbit(x) && unary != UNARY_DISABLE)
			*ptr++ = '-';
		else
			*ptr++ = ' ';
		*ptr++ = '0'; *ptr++ = '.'; *ptr++ = '0';
		break;
	case FP_SUBNORMAL:
	case FP_NORMAL:
	default:
		if (x > 0)
		{
			if (unary == UNARY_ENABLE)
				size = (int)snprintf(s+1, 0x200, "%+.*Lg", ldbl_info.dig, x);
			else
				size = (int)snprintf(s, 0x200, "% .*Lg", ldbl_info.dig, x);
			ptr = &s[size];
		}
		else /* if (x < 0) */
		{
			size = (int)snprintf(s, 0x200, "%.*Lg", ldbl_info.dig, x);
			if (unary == UNARY_DISABLE)
				*ptr = ' ';
			ptr = &s[size+1];
		}
		break;
	}
	*ptr++ = '\0';
	return s;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_TESTSUITE_H */
