/*******************************************************************************
	GLUE-Math Library: Gaussian Window

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  "Sound-Programming Guide", Naofumi Aoki, Gijutsu Hyouron Sha
	  ISBN978-4-7741-5522-7
********************************************************************************/
#include "../internal/ur/exp.h"
#include "../internal/ur/pow.h"
#include "wfunc.h"

static inline double
__gausswin_even__(double n_bias, double n_2, double sigma)
{
	return exp_core(-0.5 * pow_core(sigma * (n_bias - 0.5) / n_2, 2.0));
}

static inline double
__gausswin_odd__(double n_bias, double n_2, double sigma)
{
	return exp_core(-0.5 * pow_core(sigma * n_bias / n_2, 2.0));
}

int
gausswin(double sigma, int N, double w[])
{
	volatile int n;
	double n_bias, n_2;
	
	if (sigma < 0.0 || sigma != sigma)  return -1;
	
	n_2 = (N-1) / 2.0;
	n_bias = -n_2;
	
	if (N % 2 == 0) /* When N is even */
	{
		for (n = 0; n < N; n++)
		{
			w[n] = __gausswin_even__(n_bias, n_2, sigma);
			n_bias += 1.0;
		}
	}
	else /* When N is odd */
	{
		for (n = 0; n < N; n++)
		{
			w[n] = __gausswin_odd__(n_bias, n_2, sigma);
			n_bias += 1.0;
		}
	}
	return n;
}

