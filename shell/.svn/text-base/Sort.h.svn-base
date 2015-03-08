/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

#ifndef SHELL_SORT_H_
#define SHELL_SORT_H_
#pragma once

#include "base/Vector.h"

/**
 * Abstract sort class. Bridge Pattern
 */
class Sort {
public:
	
	/**
	 * Constructor function.
	 */
	Sort();

	/**
	 * Destructor function.
	 */
	virtual ~Sort();

	/**
	 * Sort interface.
	 * @param array Vector<int> type arrary .
	 * @param start most situlation 0.
	 * @param end number of the arrary.
	 */
	virtual void sort(Vector<int> &arrary, int start, int end) = 0;
    virtual void sort(int *arrary, int start ,int end) = 0;

	virtual void sort(Vector<int> &arrary, int length) = 0;
	virtual void sort(int *arrary, int length) = 0;

};

#endif /* SHELL_SORT_H_ */