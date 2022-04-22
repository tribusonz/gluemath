/*******************************************************************************
	GLUE-Math library: Natural Logarithm of 2 (long double)
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
		Programming in Oberon Tutorial
			- Niklaus Wirth and his team
*******************************************************************************/
#ifndef GML_CONST_LOG2_LDBL
#define GML_CONST_LOG2_LDBL

#if defined(__cplusplus)
extern "C" {
#endif

// Use library: ldbl_info.epsilon, M_E
#include "../../sys/float/info.h"
#include "../sys/primitive/float/info.h"
#include "m_e.h"
#include "logxtl.h"

static inline long double
m_log2_ld(void)
{
	static long double m_e = 0;
	if (m_e == 0)  m_e = m_e_ld();
	get_ldbl_info();
	return logxtl(2.0, m_e);
}

#if defined(__cplusplus)
}
#endif

#endif /* GML_CONST_LOG2_LDBL */
