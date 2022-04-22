/*******************************************************************************
	Radix Converter

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "radconv.h"

// radconv.new(), for unsigned long long
int
radconvnull(unsigned long long x, int d, int m, char c[])
{
	volatile int i;
	if (d < RADCONV_VALID_RADIX_MIN || d > RADCONV_VALID_RADIX_MAX)
		return -2;  /* 基数が不正 */
	for (i = 0; x != 0 && i < m; i++) {
		c[i] = x % d;  x /= d;
	}
	if (x == 0) return i;   /* 桁数 */
	else        return -1;  /* エラー */
}
