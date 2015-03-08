/*
 * Shell Simulator
 * 2010.09.05 by alex
 */

#include "shell/BubbleSort.h"

BubbleSort::BubbleSort()
{
}

BubbleSort::~BubbleSort()
{
}

/**
 * Implementation of bubble sort algorithm.
 */
void BubbleSort::sort(int *arrary, int length)
{
	int start = 0;
	int end = length -1;
	sort(arrary, start, end);
}

void BubbleSort::sort(int *arrary, int start, int end)
{
	int m = start;
	int n = end;
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j > i; j--)
		{
			if (arrary[j - 1] > arrary[j])
			{
				int temp = arrary[j];
				arrary[j] = arrary[j - 1];
				arrary[j - 1] = temp;
			}
		}
	}
}

void BubbleSort::sort(Vector<int> &arrary, int length)
{
	int start = 0;
	int end = length -1;
	sort(arrary, start, end);
}

void BubbleSort::sort(Vector<int> &arrary, int start, int end)
{
	int m = start;
	int n = end;
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j > i; j--)
		{
			if (arrary[j - 1] > arrary[j])
			{
				int temp = arrary[j];
				arrary[j] = arrary[j - 1];
				arrary[j - 1] = temp;
			}
		}
	}
}