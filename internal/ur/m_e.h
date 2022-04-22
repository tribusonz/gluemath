/*******************************************************************************
	GLUE-Math library: Napier's Constant (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_CONST_E_LDBL
#define GML_CONST_E_LDBL

#if defined(__cplusplus)
extern "C" {
#endif

// e is euler's initial
static inline long double
m_e_ld(void)
{
	register int n;
	register long double e, a, prev;

	e = 0;  a = 1;  n = 1;
	do {
		prev = e;  e += a;  a /= n;  n++;
	} while (e != prev);
	return e;
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CONST_E_LDBL */
