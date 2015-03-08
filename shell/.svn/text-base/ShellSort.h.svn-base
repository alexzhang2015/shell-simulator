/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

#ifndef SHELL_SHELL_QORT_H_
#define SHELL_SHELL_QORT_H_
#pragma once 

#include "base/Singleton.h"
#include "shell/Sort.h"

/**
 * ShellSort algorithm.
 * Insertion sorts.
 */
class ShellSort : public Sort, 
                  public Singleton<ShellSort> {
public:

	ShellSort();
	~ShellSort();

    void sort(Vector<int> &arrary, int start, int end);

	void sort(int *arrary, int start ,int end);

	void sort(Vector<int> &arrary, int length);

	void sort(int *arrary, int length);

};

#endif /* SHELL_SHELL_QORT_H_ */