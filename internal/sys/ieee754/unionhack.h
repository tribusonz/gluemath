/*******************************************************************************
	GLUE-Math Library: FP Unionhack
*******************************************************************************/
#ifndef GML_IEEE754_UNIONHACK_INTERNAL
#define GML_IEEE754_UNIONHACK_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>  // uint32_t, uint64_t

typedef union {
	float f;
	uint32_t i;
} uflt_t;

typedef union {
	double d;
	uint64_t l;
} udbl_t;

typedef union {
	long double ld;
	unsigned char s[sizeof(long double)];
} uldbl_t;

#if defined(__cplusplus)
}
#endif

#endif /* GML_IEEE754_UNIONHACK_INTERNAL */
