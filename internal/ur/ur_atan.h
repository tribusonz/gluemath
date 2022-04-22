/*******************************************************************************
    GLUE Math Library: Inverse Trigonometric Function

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_UR_ATAN_DBL_INTERNAL
#define GML_UR_ATAN_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

static inline double
ur_atan(register double x)
{
	static const int N = 24;
	static const double PI = 3.14159265358979323846264;
	register int sgn;
	register double a;

	if      (x >  1) {  sgn =  1;  x = 1 / x;  }
	else if (x < -1) {  sgn = -1;  x = 1 / x;  }
	else                sgn =  0;
	a = 0;
	for (volatile int i = N; i >= 1; i--)
		a = (i * i * x * x) / (2 * i + 1 + a);
	if (sgn > 0) return  PI / 2 - x / (1 + a);
	if (sgn < 0) return -PI / 2 - x / (1 + a);
	/* else */   return           x / (1 + a);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_UR_ATAN_DBL_INTERNAL */
