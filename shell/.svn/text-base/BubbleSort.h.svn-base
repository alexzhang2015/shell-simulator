/*
 * Shell Simulator
 * 2010.09.05 by alex
 */

#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_
#pragma once 

#include "base/Singleton.h"
#include "shell/Sort.h"

/**
 * BubbleSort algorithm.
 * Exchange sorts.
 */
class BubbleSort : public Sort, 
                   public Singleton<BubbleSort> {
public:

	BubbleSort();
	~BubbleSort();

    void sort(Vector<int> &arrary, int start, int end);

	void sort(int *arrary, int start ,int end);

	void sort(Vector<int> &arrary, int length);

	void sort(int *arrary, int length);

};

#endif /* BUBBLESORT_H_ */