/*******************************************************************************
	GLUE-Math Library: Bernoulli Number Macros

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_BERNOULLI_NUMB_MACRO
#define GML_BERNOULLI_NUMB_MACRO

#if defined(__cplusplus)
extern "C" {
#endif

#define B0  1                 /* 以下はBernoulli数 */
#define B1  (-1.0 / 2.0)
#define B2  ( 1.0 / 6.0)
#define B4  (-1.0 / 30.0)
#define B6  ( 1.0 / 42.0)
#define B8  (-1.0 / 30.0)
#define B10 ( 5.0 / 66.0)
#define B12 (-691.0 / 2730.0)
#define B14 ( 7.0 / 6.0)
#define B16 (-3617.0 / 510.0)

#if defined(__cplusplus)
}
#endif

#endif /* GML_BERNOULLI_NUMB_MACRO */
