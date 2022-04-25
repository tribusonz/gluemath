/*******************************************************************************
	GLUE-Math Library: Complex Natural Logarithm (long double)

	Author:
	  John Burkardt (Original Source)
	  Hironobu Inatsuka aka tribusonz (Part of modify)
	License:
	  John Burkardt's (Original C Source)
	  GPL + X11(MIT) (ABI part)
	Reference:
	  David Collens,
	  Algorithm 243: Logarithm of a Complex Number,
	  Communications of the Association for Computing Machinery,
	  Volume 7, Number 11, November 1964, page 660.
*******************************************************************************/
#include "cmath.h"
#include "../internal/ur/clogl.h"

lcomplex
log_ce(lcomplex z)
{
	return clogl_core(z);
}
