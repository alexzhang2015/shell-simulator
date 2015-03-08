/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

#include "shell/SortCommand.h"

#include "base/Atoi.h"
#include "base/IsDigit.h"
#include "shell/QuickSort.h"
#include "shell/ShellSort.h"
#include "shell/MergeSort.h"
#include "shell/SortScheduler.h"
#include "shell/BubbleSort.h"

SortCommand::SortCommand() : ShellCommand("sort")
{
	scheduler = SortScheduler::instance();

	/* initializtion the scheduler */
	init_scheduler();
}

SortCommand::~SortCommand()
{
}

void SortCommand::execute(int nparams, char **params)
{
	if (nparams < 2)
	{
		usage();
		return ;
	}
	
	/**
	 * Init the Vector arrary.
	 * Vector define (VECTOR_DEFAULT_SIZE 100)
	 * if use the default construction argument 100
	 * it may cause potential problems,when Shell default
	 * argument over 100. 
	 * So appoint the Vector size in the construction.
	 */
	Vector<int> sort_arrary(nparams);


	for (int i = 1;i < nparams; i++)
	{
		if (IsDigit(params[i]))
		{
		    sort_arrary.insert(Atoi(params[i]));
		}
		else
		{
			usage();
			return ;
		}
	}
	
	/**
	 * Dynamic binding the sort algorithm.
	 * Use SortScheduler choice the sort algorithm.
	 */
	base_sort = SortScheduler::current();
	//base_sort = QuickSort::instance();
	//base_sort = MergeSort::instance();
	//base_sort = ShellSort::instance();


	/**
	 * Call the sort() interface.
	 */
	int start_num = 0;
	int end_num = sort_arrary.get_count();
	this->sort(sort_arrary, start_num, end_num - 1);

	/**
	 * Print the result.
	 */
	for (int j = 0;j < nparams-1; j++)
	{
		cout << sort_arrary[j]++
		     << "  ";
	}
	cout << endl;
}

const string SortCommand::cmd_help()
{
	return "Sort some integer number.";
}

void SortCommand::usage()
{
	cout << "usage : sort num1 num2 num3 ...";
}

void SortCommand::init_scheduler()
{
	scheduler->enqueue(QuickSort::instance());
	scheduler->enqueue(MergeSort::instance());
	scheduler->enqueue(ShellSort::instance());
	scheduler->enqueue(BubbleSort::instance());
}