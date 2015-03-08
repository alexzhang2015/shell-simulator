/*
 * Shell Simulator
 * 2010.09.14 by alex
 */

#include "base/alex_string.h"

char *str_cpy(char *str_dest, const char *str_src)
{
	char *address = str_dest;
	while(*str_src != '\0')
	{
		*str_dest++ = *str_src++;
	}
	*str_dest = '\0';
	return address;
}