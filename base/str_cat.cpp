/*
 * Shell Simulator
 * 2010.09.14 by alex
 */

#include "base/alex_string.h"

char *str_cat(char *dest, const char *src)
{
    char *s = dest;

    while (*s)
	s++;

    str_cpy(s, src);
    return dest;
}