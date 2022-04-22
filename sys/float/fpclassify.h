/*******************************************************************************
	GLUE-Math - FP Classify

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#ifndef GLUE_PRIMITIVE_FP_CLASSIFY
#define GLUE_PRIMITIVE_FP_CLASSIFY

#if defined(__cplusplus)
extern "C" {
#endif

// Classify Constants and ABI
#ifndef  FP_NAN
# define FP_NAN 0
#endif
#ifndef  FP_INFINITE
# define FP_INFINITE 1
#endif
#ifndef  FP_ZERO
# define FP_ZERO 2
#endif
#ifndef  FP_SUBNORMAL
# define FP_SUBNORMAL 3
#endif
#ifndef  FP_NORMAL
# define FP_NORMAL 4
#endif

#ifndef fpclassify
# define fpclassify(x) \
    (sizeof (x) == sizeof (long double) ? gml_ldbl_fpclassify (x) \
     : sizeof (x) == sizeof (double) ? gml_dbl_fpclassify (x) \
     : gml_flt_fpclassify (x))
static inline int gml_flt_fpclassify(float);
static inline int gml_dbl_fpclassify(double);
static inline int gml_ldbl_fpclassify(long double);
#endif

#ifndef isfinite
# define isfinite(x) \
    (sizeof (x) == sizeof (long double) ? gml_ldbl_isfinite (x) \
     : sizeof (x) == sizeof (double) ? gml_dbl_isfinite (x) \
     : gml_flt_isfinite (x))
static inline int gml_flt_isfinite(float);
static inline int gml_dbl_isfinite(double);
static inline int gml_ldbl_isfinite(long double);
#endif

#ifndef isnormal
# define isnormal(x) \
    (sizeof (x) == sizeof (long double) ? gml_ldbl_isnormal (x) \
     : sizeof (x) == sizeof (double) ? gml_dbl_isnormal (x) \
     : gml_flt_isnormal (x))
static inline int gml_flt_isnormal(float);
static inline int gml_dbl_isnormal(double);
static inline int gml_ldbl_isnormal(long double);
#endif

#ifndef isnan
# define isnan(x) \
    (sizeof (x) == sizeof (long double) ? gml_ldbl_isnan (x) \
     : sizeof (x) == sizeof (double) ? gml_dbl_isnan (x) \
     : gml_flt_isnan (x))
static inline int gml_flt_isnan(float);
static inline int gml_dbl_isnan(double);
static inline int gml_ldbl_isnan(long double);
#endif

#ifndef isinf
# define isinf(x) \
    (sizeof (x) == sizeof (long double) ? gml_ldbl_isinf (x) \
     : sizeof (x) == sizeof (double) ? gml_dbl_isinf (x) \
     : gml_flt_isinf (x))
static inline int gml_flt_isinf(float);
static inline int gml_dbl_isinf(double);
static inline int gml_ldbl_isinf(long double);
#endif

#if defined(__cplusplus)
}
#endif

#endif /* GLUE_PRIMITIVE_FP_CLASSIFY */
