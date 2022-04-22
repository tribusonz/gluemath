/*******************************************************************************
	Radix Converter

	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "../sys/radconv/radconv.h"
#include <stdio.h>
#include <stdlib.h>
/*******************************************************************************
test build:
$ gcc -Wall -Wextra -O2 -o bin/radconv test/radconv.c sys/radconv/radconvn.c sys/radconv/radconvr.c sys/radconv/radconvtos.c

*******************************************************************************/

int
main(void)
{
	int x, m1, m2, m3;
	static char x1[RADCONV_MAX_DECIMAL], x2[RADCONV_MAX_DECIMAL], x3[RADCONV_MAX_DECIMAL];

	printf("x = ");  scanf("%d", &x);

	m1 = radconvn(x, 8, RADCONV_MAX_DECIMAL, x1);
	if (m1 < 0) {
		printf("radconv.new(): error\n");  return 1;
	}

	printf("8進(octal): %s\n", radconvtos(RADCONV_DOWNCASE, RADCONV_UNARY_AUTO, m1, x1));

	m2 = radconvr(8, m1, x1, 2, RADCONV_MAX_DECIMAL, x2);
	if (m1 < 0) {
		printf("radconv.replace(): error\n");  return 1;
	}

	printf("2進(binary): %s\n", radconvtos(RADCONV_DOWNCASE, RADCONV_UNARY_AUTO, m2, x2));

	m3 = radconvr(2, m2, x2, 16, RADCONV_MAX_DECIMAL, x3);
	if (m1 < 0) {
		printf("radconv.replace(): error\n");  return 1;
	}

	printf("16進(hex): %s\n", radconvtos(RADCONV_DOWNCASE, RADCONV_UNARY_AUTO, m3, x3));

	return 0;
}
