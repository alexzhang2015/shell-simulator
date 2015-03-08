/*
 * Shell Simulator
 * 2010.08.21 by alex
 */

#ifndef SHELL_MERGE_SORT_H_
#define SHELL_MERGE_SORT_H_
#pragma once 

#include "base/Singleton.h"
#include "shell/Sort.h"

/**
 * MergeSort algorithm.
 * Merge sorts.
 */
class MergeSort : public Sort, 
                  public Singleton<MergeSort> {
public:

	MergeSort();
	~MergeSort();

    void sort(Vector<int> &arrary, int start, int end);

	void sort(int *arrary, int start ,int end);

	void sort(Vector<int> &arrary, int length);

	void sort(int *arrary, int length);

	void merge(int *arrary, int i1,int j1,int i2,int j2);

	void merge(Vector<int> &arrary, int i1,int j1,int i2,int j2);

};

#endif /* SHELL_MERGE_SORT_H_ */