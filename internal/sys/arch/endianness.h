/*******************************************************************************
	Architecture -- Endianness Envieronment
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	
	Reference:
		C gengo ni yoru Hyoujun Algorithm Jiten (Japanese)
		Handbook of the Standard Algorithms in C
		- Haruhiko Okumura
*******************************************************************************/
#ifndef ENDIANNESS_ENVIERONMENT
#define ENDIANNESS_ENVIERONMENT

#if defined(__cplusplus)
extern "C" {
#endif

static inline int
endian(void)
{
	int i = 1;
	if (*((char *)&i))
		return 1; // little endian
	else if (*((char *)&i + (sizeof(int) - 1)))
		return 2; // big endian
    else
		return 0; // unknown
}

#if defined(__cplusplus)
}
#endif

#endif /* ENDIANNESS_ENVIERONMENT */
