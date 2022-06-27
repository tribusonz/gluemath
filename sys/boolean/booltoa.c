/*******************************************************************************
	GLUE-Math Library: booltoa()
	
	Author: Hironobu Inatsuka aka tribusonz
	License: GOL + X11(MIT)
*******************************************************************************/
#include "booltoa.h"

char *
booltoa(_Bool x)
{
	static char s[0x10];
	char *ptr = s;
	if (x == 0)
	{
		*ptr++ = 'f'; *ptr++ = 'a'; *ptr++ = 'l'; *ptr++ = 's'; *ptr++ = 'e';
	}
	else
	{
		*ptr++ = 't'; *ptr++ = 'r'; *ptr++ = 'u'; *ptr++ = 'e';
	}
	*ptr++ = '\0';
	return s;
}
