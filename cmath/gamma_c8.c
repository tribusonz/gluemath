/*******************************************************************************
	GLUE-Math Library: Complex Gamma Function

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
#include "../internal/ur/cgamma.h"

dcomplex
gml_gamma_c8(dcomplex z)
{
	return cgamma_core(z);
}
