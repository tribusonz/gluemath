/*******************************************************************************
	GLUE-Math Library: Complex Complementary Error Function

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
#include "../internal/ur/cerfc.h"

dcomplex
erfc_c8(dcomplex z)
{
	return cerfc_core(z);
}
