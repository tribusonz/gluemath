/*******************************************************************************
	GLUE-Math Library: RNG -- Uniform Distribution

	Author: Hironobu Inatsuka aka tribusonz
*******************************************************************************/
#ifndef GML_RNG_UNIFORM_INTERNAL
#define GML_RNG_UNIFORM_INTERNAL

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../sys/random/random.h"

static inline double
uniform_core(void)
{
    static int check=0;
    if( check==0 ){ init_genrand(10000); check=1; }

	return genrand_res53();
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_RNG_UNIFORM_INTERNAL */
