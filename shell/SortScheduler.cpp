/*
 * Shell Simulator
 * 2010.08.22 by alex
 */

#include "shell/SortScheduler.h"

std::list<Sort *> SortScheduler::queue;

SortScheduler::SortScheduler()
{

}

SortScheduler::~SortScheduler()
{
}

Sort *SortScheduler::current()
{
	Sort *base_sort = queue.front();
	queue.push_back(queue.front());
	queue.pop_front();
	return base_sort;
}

void SortScheduler::enqueue(Sort *sort_algorithm)
{
	queue.push_back(sort_algorithm);
}

void SortScheduler::dequeue(Sort *sort_algorithm)
{
	if (queue.size() > 0)
	{
		queue.remove(sort_algorithm);
	}
}