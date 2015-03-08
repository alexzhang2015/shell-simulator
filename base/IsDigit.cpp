/*
 * Shell Simulator
 * 2010.09.14 by alex
 */

#include "base/IsDigit.h"

bool IsDigit(const char *p)
{
	if (p == NULL)
	{
		return false;
	}

	if (*p ==  '-')
	{
		p++;
	}

	for (; *p != '\0'; p++)
	{
		if (*p > '9' ||  *p < '0')
		{
			/* Not a digit */
			return false;
		}
	}
	/* Is a digit */
	return true;
}