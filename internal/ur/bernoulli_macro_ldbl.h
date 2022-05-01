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
#ifndef GML_BERNOULLI_NUMB_LDBL_MACRO
#define GML_BERNOULLI_NUMB_LDBL_MACRO

#if defined(__cplusplus)
extern "C" {
#endif

#define B0l  1.L                 /* à»â∫ÇÕBernoulliêî */
#define B1l  (-1.L / 2.L)
#define B2l  ( 1.L / 6.L)
#define B4l  (-1.L / 30.L)
#define B6l  ( 1.L / 42.L)
#define B8l  (-1.L / 30.L)
#define B10l ( 5.L / 66.L)
#define B12l (-691.L / 2730.L)
#define B14l ( 7.L / 6.L)
#define B16l (-3617.L / 510.L)

#if defined(__cplusplus)
}
#endif

#endif /* GML_BERNOULLI_NUMB_LDBL_MACRO */
