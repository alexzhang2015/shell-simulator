/*
 * Shell Simulator
 * 2010.08.22 by alex
 */

#ifndef SHELL_SORT_SCHEDULER_H_
#define SHELL_SORT_SCHEDULER_H_
#pragma once

#include <list>
#include "base/Singleton.h"
#include "shell/Sort.h"

/**
 * A simple sort scheduler component.
 */
class SortScheduler : public Singleton<SortScheduler> {
public:
	SortScheduler();
	~SortScheduler();

	/**
	 * Get the	current sort algorithm.
	 * Use the first-come first-served schedule mechanism.
	 */
	static Sort *current();

	/**
	 * Put a sort algorithm in the scheduler.
	 * @param sort_algorithm pointer to sort algorithm.
	 */
	void enqueue(Sort *sort_algorithm);

	/**
	 * Remove a sort algorithm form the scheduler.
	 * @param sort_algorithm pointer to sort algorithm.
	 */
	void dequeue(Sort *sort_algorithm);

private:

	/* Scheduler queue instance */
	static std::list<Sort *> queue;

};

#endif /* SHELL_SORT_SCHEDULER_H_ */