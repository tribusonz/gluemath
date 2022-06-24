/*******************************************************************************
	GLUE-Math - Complex Attribute

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GLUE_PRIMITIVE_COMPLEX_ATTRIBUTE
#define GLUE_PRIMITIVE_COMPLEX_ATTRIBUTE

#if defined(__cplusplus)
extern "C" {
#endif

#include "class.h"

// Attribute Constants and ABI
#ifndef  C_IMAG_INFINITE
# define C_IMAG_INFINITE  (0x1)
#endif
#ifndef  C_IMAG_FINITE
# define C_IMAG_FINITE    (0x2)
#endif
#ifndef  C_IMAG_ONE
# define C_IMAG_ONE       (0x4)
#endif
#ifndef  C_IMAG_ZERO
# define C_IMAG_ZERO      (0x8)
#endif
#ifndef  C_IMAG_HAS_SIGN
# define C_IMAG_HAS_SIGN  (0x100)
#endif
#ifndef  C_REAL_INFINITE
# define C_REAL_INFINITE  (0x10)
#endif
#ifndef  C_REAL_FINITE
# define C_REAL_FINITE    (0x20)
#endif
#ifndef  C_REAL_ONE
# define C_REAL_ONE       (0x40)
#endif
#ifndef  C_REAL_ZERO
# define C_REAL_ZERO      (0x80)
#endif
#ifndef  C_REAL_HAS_SIGN
# define C_REAL_HAS_SIGN  (0x1000)
#endif

#ifndef complexattr
# define complexattr(x) \
    (sizeof (x) == sizeof (lcomplex) ? gml_ldblcmplx_attr (x) \
     : sizeof (x) == sizeof (dcomplex) ? gml_dblcmplx_attr (x) \
     : gml_fltcmplx_attr (x))
static inline int gml_fltcmplx_attr(fcomplex);
static inline int gml_dblcmplx_attr(dcomplex);
static inline int gml_ldblcmplx_attr(lcomplex);
#endif

#if defined(__cplusplus)
}
#endif

#endif /* GLUE_PRIMITIVE_COMPLEX_ATTRIBUTE */
