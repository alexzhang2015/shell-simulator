/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

#include "shell/QuickSort.h"

QuickSort::QuickSort()
{
}

QuickSort::~QuickSort()
{
}

/**
 * Implementation of quick sort algorithm.
 */
void QuickSort::sort(Vector<int> &arrary, int start, int end)
{
	int m = start;
	int n = end;

	if (m < n)
	{
		int i = m;
		int j = n + 1;
		int k = arrary[m];
		int t;
		while (i < j)
		{
			for (i = i + 1; i < n; i++)
			{
				if (arrary[i] >= k)
					break;
			}
			for (j = j - 1; j > m; j--)
			{
				if (arrary[j] <= k)
					break;
			}
			if (i < j)
			{
				t = arrary[i];
				arrary[i] = arrary[j];
				arrary[j] = t;
			}
		}
		t = arrary[m];
		arrary[m] = arrary[j];
		arrary[j] = t;

		sort(arrary,m,j-1);
		sort(arrary,i,n);
	}
}

void QuickSort::sort(Vector<int> &arrary, int length)
{
	int start = 0;
	int end = length -1;
	sort(arrary, start, end);
}

void QuickSort::sort(int *arrary, int start, int end)
{
	int m = start;
	int n = end;

	if (m < n)
	{
		int i = m;
		int j = n + 1;
		int k = arrary[m];
		int t;
		while (i < j)
		{
			for (i = i + 1; i < n; i++)
			{
				if (arrary[i] >= k)
					break;
			}
			for (j = j - 1; j > m; j--)
			{
				if (arrary[j] <= k)
					break;
			}
			if (i < j)
			{
				t = arrary[i];
				arrary[i] = arrary[j];
				arrary[j] = t;
			}
		}
		t = arrary[m];
		arrary[m] = arrary[j];
		arrary[j] = t;

		sort(arrary,m,j-1);
		sort(arrary,i,n);
	}	
}

void QuickSort::sort(int *arrary, int length)
{
	int start = 0;
	int end = length -1;
	sort(arrary, start, end);
}
