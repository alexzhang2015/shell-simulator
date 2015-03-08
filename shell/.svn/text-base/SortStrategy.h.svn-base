/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

#ifndef SHELL_SORT_STRATEGY_H_
#define SHELL_SORT_STRATEGY_H_
#pragma once

#include "base/Factory.h"
#include "shell/Sort.h"

/**
 * Provide sort interface ,Use Strategy Pattern 
 */

class SortStrategy : virtual public Factory<SortStrategy> {
public:
	
	/**
	 * Constructor function.
	 * @param base_sort Sort object ,dynamic binding to
	 * the derived Sort class objects.
	 */
	SortStrategy();
	explicit SortStrategy(Sort *base_sort);

	~SortStrategy();

	/**
	 * Sort interface .Use the Sort object combination strategy.
	 */
	void sort(Vector<int> &arrary, int length);
	void sort(Vector<int> &arrary, int start, int end);
	void sort(int *arrary, int length);
	void sort(int *arrary, int start, int end);

protected:

	/* Sort object pointer */
	Sort *base_sort;

};

#endif /* SHELL_SORT_STRATEGY_H_ */