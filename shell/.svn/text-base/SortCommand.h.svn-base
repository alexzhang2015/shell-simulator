/*
 * Shell Simulator
 * 2010.08.20 by alex
 */

#ifndef SHELL_SORTCOMMAND_H_
#define SHELL_SORTCOMMAND_H_
#pragma once

#include "base/Singleton.h"
#include "shell/SortStrategy.h"
#include "shell/SortScheduler.h"
#include "shell/ShellCommand.h"

/**
 * 本来对于多重继承，采用virtual base方法，避免 ambiguous,
 * 对于基类是模板类时，还是不可行，子类赋值模板不同类型，
 *                     A       (A<class T> ,fun(t) {} )
 *                    / \      
 *                   B   C     (B :vitual A, B:A(B)  , C virtual A, C:A(C) )
 *                    \ /
 *                     D       (D :A,B   ,D->fun() 产生二义性)
 *   解决方法: D->A::fun() ,D->B::fun();指定。 对于这里的继承
 * Singleton模板还是不行，D初始化实例时二义性不可消除。
 *
 *
 * 这里的ShellCommand 通过类聚合的方式，使用SortStrategy提供的sort接口
 * 也可以通过对象组合的方式。
 */
class SortCommand : public ShellCommand, 
					virtual public Singleton<SortCommand>,
					public SortStrategy {
public:

	SortCommand();
	~SortCommand();

	void execute(int nparams, char **params);

	const string cmd_help();

	void usage();

private:

	/**
	 * Initializtion the scheduler 
	 * enqueue some sort algorithm.
	 */
	void init_scheduler();

	/* Declare a sort scheduler */
	SortScheduler *scheduler;

};

#endif /* SHELL_SORTCOMMAND_H_*/