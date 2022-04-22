/*******************************************************************************
	Radix Converter

	Author: Hironobu Inatsuka aka tribusonz
	License: GPL + X11(MIT)
	Reference:
	  C-gengo ni yoru Hyoujun Algorithm Jiten - Haruhiko Okumura
	  ISBN978-4-7741-9690-9
*******************************************************************************/
#include "radconv.h"
#include "radconv_tab.h"

// radconv.to_s()
char *
radconvtos(int charcase, int unary, int size, const char c[])
{
	static char s[RADCONV_MAX_DECIMAL];
	char *ptr = s;
	int i = 0;
	
	switch (unary) {
	case RADCONV_UNARY_ENABLE:
		*ptr++ = c[size-1] < 0 ? '-' : '+'; 
		break;
	case RADCONV_UNARY_DISABLE:
		break;
	case RADCONV_UNARY_AUTO:
	default:
		if (c[size-1] < 0)  *ptr++ = '-'; 
		break;
	}
	switch (charcase) {
	case RADCONV_DOWNCASE:
		for (i = size - 1; i >= 0; i--)
			*ptr++ = table_downcase[(unsigned char)c[i]];
		break;
	case RADCONV_UPCASE:
		for (i = size - 1; i >= 0; i--)
			*ptr++ = table_upcase[(unsigned char)c[i]];
		break;
	default:
		break;
	}
	*ptr = '\0';
	return s;
}
