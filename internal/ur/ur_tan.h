/*******************************************************************************
	GLUE-Math Library: Trigonometric Function
	
	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_UR_TAN_DBL_INTERNAL
#define GML_UR_TAN_DBL_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

static inline double
ur_tan(register double x, int *k)
{
	static double PI = 3.1415926535897932384626433832795;
	static const int N = 19;
	static const double D = 4.4544551033807686783083602485579e-6;
	register double t, x2;

	*k = (int)(x / (PI / 2) + (x >= 0 ? 0.5 : -0.5));
	x = +(x - (3217.0 / 2048) * *k) + D * *k;
	x2 = x * x;  t = 0;
	for (volatile int i = N; i >= 3; i -= 2) t = x2 / (i - t);
	return x / (1 - t);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_UR_TAN_DBL_INTERNAL */
