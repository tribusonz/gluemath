/*******************************************************************************
	GLUE-Math Tuning: Allocator

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
*******************************************************************************/
#ifndef GML_TUNING_ALLOCATOR
#define GML_TUNING_ALLOCATOR

#if defined(__cplusplus)
extern "C" {
#endif

// Prototype Declaration of Common Standards for Custom Allocators
#ifdef _USE_CUSTOM_ALLOCATOR
static const int use_custom_allocator = 1;
static inline void *xmalloc(size_t);
static inline void *xcalloc(size_t n, size_t size);
static inline void *xrealloc(void*, size_t);
static inline void xfree(void*);

#else
static const int use_custom_allocator = 0;
# include "../allocator/xmalloc.h"
#endif

#if defined(__cplusplus)
}
#endif

#endif /* GML_TUNING_ALLOCATOR */
