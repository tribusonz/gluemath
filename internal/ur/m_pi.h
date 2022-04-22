/*******************************************************************************
	GLUE-Math library: PI (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_CONST_PI_LDBL
#define GML_CONST_PI_LDBL

#if defined(__cplusplus)
extern "C" {
#endif

/* Machin's formula */
static inline long double
m_pi_ld(void)
{
	register int k;
	register long double p, t, last;

	p = 0;  k = 1;  t = 16.0L / 5.0L;
	do {
		last = p;  p += t / k;  t /= -5.0L*5.0L;  k += 2;
	} while (p != last);
	k = 1;  t = 4.0L / 239.0L;
	do {
		last = p;  p -= t / k;  t /= -239.0L*239.0L;  k += 2;
	} while (p != last);
	return p;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CONST_PI_LDBL */
