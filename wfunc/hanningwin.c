/*******************************************************************************
	GLUE-Math Library: Hanning Window
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  "Sound-Programming Guide", Naofumi Aoki, Gijutsu Hyouron Sha
	  ISBN978-4-7741-5522-7
********************************************************************************/
#include "wfunc.h"
#include "../internal/ur/cos.h"

static inline double
__hanning_even__(double n, int N)
{
	static const double PI = 3.1415926535897932384626433832795;
	return 0.5 - 0.5 * cos_core(2.0 * PI * n / N);
}

static inline double
__hanning_odd__(double n, int N)
{
	static const double PI = 3.1415926535897932384626433832795;
	return 0.5 - 0.5 * cos_core(2.0 * PI * (n + 0.5) / N);
}

int
hanning_window(int N, double w[])
{
	volatile int n;
	
	if (N % 2 == 0) /* When N is even */
		for (n = 0; n < N; n++)
			w[n] = __hanning_even__(n, N);
	else /* When N is odd */
		for (n = 0; n < N; n++)
			w[n] = __hanning_odd__(n, N);
	return n;
}
