/*******************************************************************************
	GLUE-Math Library: Rectangular Window

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  "Sound-Programming Guide", Naofumi Aoki, Gijutsu Hyouron Sha
	  ISBN978-4-7741-5522-7
********************************************************************************/
#include "wfunc.h"

int
rectangularwin(int N, double w[])
{
	volatile int n;
	
	for (n = 0; n < N; n++)
		w[n] = 1.0;
	return n;
}
