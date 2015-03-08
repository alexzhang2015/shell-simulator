/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

#include "shell/SortStrategy.h"

#include <iostream>

SortStrategy::SortStrategy()
{
    this->base_sort = NULL;
}

SortStrategy::SortStrategy(Sort *base_sort)
{
	this->base_sort = base_sort;
}

SortStrategy::~SortStrategy()
{
}

void SortStrategy::sort(Vector<int> &arrary, int start, int end)
{
	base_sort->sort(arrary, start, end);
}

void SortStrategy::sort(Vector<int> &arrary, int length)
{
	base_sort->sort(arrary, length);
}

void SortStrategy::sort(int *arrary, int length)
{
	base_sort->sort(arrary, length);
}

void SortStrategy::sort(int *arrary, int start, int end)
{
    base_sort->sort(arrary, start, end);
}