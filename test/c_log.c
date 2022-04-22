/*******************************************************************************
	GLUE-Math Library: Complex Natural Logarithm

	Author:
	  John Burkardt (Original Source)
	  Hironobu Inatsuka aka tribusonz (Part of modify)
	License:
	  John Burkardt's (Original C Source)
	  GPL + X11(MIT) (ABI part)
	Reference:
	  David Collens,
	  Algorithm 243: Logarithm of a Complex Number,
	  Communications of the Association for Computing Machinery,
	  Volume 7, Number 11, November 1964, page 660.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "../cmath/cmath.h"

extern int c_isnan(dcomplex);
extern int c_isinf(dcomplex);
extern char *c_dtosi(dcomplex);

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

/* 倍精度複素数型を虚数i単位で文字列に変換する。 */
char *
c_dtosi(dcomplex z)
{
	static char s[0x200];
	if (isnan(z.imag) || isinf(z.imag))
		snprintf(s, 0x200, "(%g%+g*i)", z.real, z.imag);
	else
		snprintf(s, 0x200, "(%g%+gi)", z.real, z.imag);
	return s;
}

int
main(void)
{
	dcomplex z;
	printf("re im ? "); scanf("%lf %lf", &z.real, &z.imag);
	printf("ln%s = ", c_dtosi(z));
	z = clog_c8(z);
	printf("%s\n", c_dtosi(z));
	return 0;
}
