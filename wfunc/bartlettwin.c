/*******************************************************************************
	GLUE-Math Library: Bartlett Window

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  "Sound-Programming Guide", Naofumi Aoki, Gijutsu Hyouron Sha
	  ISBN978-4-7741-5522-7
********************************************************************************/
#include "wfunc.h"
#include "../sys/float/absolute.h"

static inline double
__bartlett_even__(double n, int N)
{
	return 1.0 - fabs(2.0 * (n - N / 2.0) / N);
}

static inline double
__bartlett_odd__(double n, int N)
{
	return 1.0 - fabs(2.0 * ((n + 0.5) - N / 2.0) / N);
}

int
bartlettwin(int N, double w[])
{
	volatile int n;
	
	if (N % 2 == 0) /* When N is even */
		for (n = 0; n < N; n++)
			w[n] = __bartlett_even__(n, N);
	else /* When N is odd */
		for (n = 0; n < N; n++)
			w[n] = __bartlett_odd__(n, N);
	return n;
}
