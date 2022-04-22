/*******************************************************************************
	Floating Point Arithmetic: Macro of HUGE_VAL/NAN

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/

/*
 * Macro of Inf (Very simple procedure)
 * Follow paper:
 * https://www.gnu.org/software/libc/manual/html_node/Infinity-and-NaN.html
 */
#ifndef HUGE_VAL
#define HUGE_VAL   (double)(1.0/0.0)
#endif
#ifndef HUGE_VALL
#define HUGE_VALL  (long double)(1.0/0.0)
#endif
#ifndef HUGE_VALF
#define HUGE_VALF  (float)(1.0/0.0)
#endif

/* Intentionally raised on those corresponding primitive */
// Note: There are several models that are not supported making NaN by dividing between zeroes.
// e.g. Linux gcc build: -nan
#ifndef NAN
#define NAN  (0.0/0.0)
#endif
