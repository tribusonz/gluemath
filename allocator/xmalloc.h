/*******************************************************************************
	Wrapped C Allocator
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11
*******************************************************************************/
#ifndef GML_WRAPPED_C_ALLOCATOR_H
#define GML_WRAPPED_C_ALLOCATOR_H

#if defined(__cplusplus)
extern "C" {
#endif

// Windows CRT version
#if defined(_WIN32) || defined(_WIN64)
# include <malloc.h>
# include <stdio.h>
# include <stdlib.h>

static inline void *
xmalloc(size_t size)
{
	void *ptr;
	size_t alignment = 16;

	ptr = _aligned_malloc(size, alignment);
	if (ptr == NULL)
	{
		fprintf_s( stderr, "Error allocation aligned memory.");
		exit(EXIT_FAILURE);
	}
	return ptr;
}

static inline void *
xcalloc(size_t n, size_t size)
{
	void *ptr;
	size_t alignment = 16;
	unsigned char *v;
	
	ptr = _aligned_malloc(n * size, alignment);
	if (ptr == NULL)
	{
		fprintf_s( stderr, "Error allocation aligned memory.");
		exit(EXIT_FAILURE);
	}
	v = (unsigned char *)ptr;
	for (volatile size_t i = 0; i < n*size; i++)  *v++ = '\0';

	return ptr;
}

static inline void *
xrealloc(void *ptr, size_t size)
{
	size_t alignment = 16;

	ptr = _aligned_realloc(ptr, size, alignment);
	{
		fprintf_s( stderr, "Error re-allocation aligned memory.");
		exit(EXIT_FAILURE);
	}
	return ptr;
}

# define SAFE_FREE(ptr)  if(ptr != NULL){ _aligned_free(ptr); ptr = NULL; }
static inline void
xfree(void *ptr)
{
	SAFE_FREE(ptr);
}

#else
# include <stdio.h>
# include <stdlib.h>

/*
 * Simple version ex-alloc. (With error checking)
 */
static inline void *
xmalloc(size_t size)
{
	void *p;
	p = malloc(size);
	if (p == NULL)
	{
		fputs("Memory allocation failed.", stderr);
		exit(EXIT_FAILURE);
	}
	return p;
}

static inline void *
xcalloc(size_t n, size_t size)
{
	void *p;
	p = calloc(n, size);
	if (p == NULL)
	{
		fputs("Memory allocation failed.", stderr);
		exit(EXIT_FAILURE);
	}
	return p;
}

static inline void *
xrealloc(void *ptr, size_t size)
{
	void *ret;
	ret = realloc(ptr, size);
	if (ret == NULL)
	{
		// If the realloc function fails, the original space is left unended.
		// Call the free function ownself and exit.
		xfree(ptr);
		fputs("Memory allocation failed.", stderr);
		exit(EXIT_FAILURE);
	}
	return ret;
}

# define SAFE_FREE(ptr)  if(ptr != NULL ){ free(ptr); ptr = NULL; }
static inline void
xfree(void *ptr)
{
	SAFE_FREE(ptr);
}
#endif

#if defined(__cplusplus)
}
#endif

#endif /* GML_WRAPPED_C_ALLOCATOR_H */
