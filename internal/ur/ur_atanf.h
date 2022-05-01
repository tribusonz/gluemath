/*******************************************************************************
    GLUE Math Library: Inverse Trigonometric Function (float)

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_UR_ATAN_FLT_INTERNAL
#define GML_UR_ATAN_FLT_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

static inline float
ur_atanf(register float x)
{
	static const int N = 24;
	static const float PI = 3.14159265358979323846264;
	register int sgn;
	register float a;

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

#endif /* GML_UR_ATAN_FLT_INTERNAL */
