/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

#ifndef SHELL_QUICK_QORT_H_
#define SHELL_QUICK_QORT_H_
#pragma once

#include "base/Singleton.h"
#include "shell/Sort.h"

/**
 * QuickSort algorithm.
 */
class QuickSort : public Sort, 
                  public Singleton<QuickSort> {
public:

	QuickSort();
	~QuickSort();

    void sort(Vector<int> &arrary, int start, int end);

	void sort(int *arrary, int start ,int end);

	void sort(Vector<int> &arrary, int length);

	void sort(int *arrary, int length);

};

#endif /* SHELL_QUICK_QORT_H_ */