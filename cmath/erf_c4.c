/*******************************************************************************
	GLUE-Math Library: Complex Error Function

	Author:
	  Takuya Ooura (Original Source)
	  Hironobu Inatsuka aka tribusonz (Part of modify)
	License:
	  Takuya Ooura's (Original C Source)
	  GPL + X11(MIT) (ABI part)
	Reference:
	  Ooura's Mathematical Software Packages
*******************************************************************************/
#include "cmath.h"
#include "../internal/ur/cerff.h"

fcomplex
erf_c4(fcomplex z)
{
	return cerff_core(z);
}
