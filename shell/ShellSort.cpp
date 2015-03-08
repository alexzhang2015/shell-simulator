/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

#include "shell/ShellSort.h"

ShellSort::ShellSort()
{
}

ShellSort::~ShellSort()
{
}

/**
 * Implementation of shell sort algorithm.
 */
void ShellSort::sort(Vector<int> &arrary, int start, int end)
{
	int length = end -start +1;
	sort(arrary, length);
}

void ShellSort::sort(Vector<int> &arrary, int length)
{
	int len = length;
	int d = len;
	while (len > 1)
	{
		len = (len + 1) / 2;
		for (int i = 0; i < d - len; i++)
		{
			if (arrary[i + len] < arrary[i])
			{
				int tmp = arrary[i+len];
				arrary[i+len] = arrary[i];
				arrary[i] = tmp;
			}
		}
	}
}

void ShellSort::sort(int *arrary, int start, int end)
{
	int length = end - start +1;
	sort(arrary, length);
}

void ShellSort::sort(int *arrary, int length)
{
	int len = length;
	int d = len;
	while (len > 1)
	{
		len = (len + 1) / 2;
		for (int i = 0; i < d - len; i++)
		{
			if (arrary[i + len] < arrary[i])
			{
				int tmp = arrary[i+len];
				arrary[i+len] = arrary[i];
				arrary[i] = tmp;
			}
		}
	}
}