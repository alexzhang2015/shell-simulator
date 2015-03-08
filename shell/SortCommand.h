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
 * �������ڶ��ؼ̳У�����virtual base���������� ambiguous,
 * ���ڻ�����ģ����ʱ�����ǲ����У����ำֵģ�岻ͬ���ͣ�
 *                     A       (A<class T> ,fun(t) {} )
 *                    / \      
 *                   B   C     (B :vitual A, B:A(B)  , C virtual A, C:A(C) )
 *                    \ /
 *                     D       (D :A,B   ,D->fun() ����������)
 *   �������: D->A::fun() ,D->B::fun();ָ���� ��������ļ̳�
 * Singletonģ�廹�ǲ��У�D��ʼ��ʵ��ʱ�����Բ���������
 *
 *
 * �����ShellCommand ͨ����ۺϵķ�ʽ��ʹ��SortStrategy�ṩ��sort�ӿ�
 * Ҳ����ͨ��������ϵķ�ʽ��
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