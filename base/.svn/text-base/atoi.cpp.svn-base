/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

#include "base/Atoi.h"

int Atoi(char *s)
{
	int sign = 1, num = 0;
    if (*s == '-')
	{
        sign = -1;
        s++;
	}
    while((*s) != '\0')
    {
        num = num * 10 + (*s++ - '0');
        
    }   
    return num * sign;   
}