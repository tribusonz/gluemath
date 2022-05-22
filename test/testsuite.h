#ifndef GML_TESTSUITE_H
#define GML_TESTSUITE_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdio.h>
#include <string.h>


static inline void
rmath_title_print(const char *title)
{
	puts("GLUE-Math with POSIX standard");
	puts("Test Suite:");
	printf("  %*s\n", (int)strlen(title), title);
	puts("");
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_TESTSUITE_H */
