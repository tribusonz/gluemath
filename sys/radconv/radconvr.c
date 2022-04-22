/*******************************************************************************
	Radix Converter

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "radconv.h"

// radconv.replace()
int
radconvr(int d1, int m1, char x1[], int d2, int m2, char x2[])
{
	int i, j, r, t;

	if (d1 < RADCONV_VALID_RADIX_MIN || d1 > RADCONV_VALID_RADIX_MAX ||
		d2 < RADCONV_VALID_RADIX_MIN || d2 > RADCONV_VALID_RADIX_MAX)
		return -2;  /* 基数が不正 */
	for (i = 0; m1 > 0 && i < m2; i++) {
		r = 0;
		for (j = m1 - 1; j >= 0; j--) {
			t = d1 * r + x1[j];  x1[j] = t / d2;  r = t % d2;
		}
		x2[i] = r;
		while (m1 > 0 && x1[m1 - 1] == 0) m1--;
	}
	if (m1 == 0) return i;   /* 桁数 */
	else         return -1;  /* エラー */
}
