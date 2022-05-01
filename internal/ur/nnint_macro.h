/*******************************************************************************
	GLUE-Math Library: Macro of Nearest Neighbor Integer

	Author:
	  Haruhiko Okumura (Original algorithm)
	  Hironobu Inatsuka aka tribusonz (ABI modify)
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GML_NNINT_MACRO_INTERNAL
#define GML_NNINT_MACRO_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#define INLINE_FLOOR(x) ((int)(x) > (x) ? (int)(x) - 1 : (int)(x))
#define INLINE_CEIL(x)  ((int)(x) < (x) ? (int)(x) + 1 : (int)(x))

#if defined(__cplusplus)
}
#endif

#endif /* GML_NNINT_MACRO_INTERNAL */
