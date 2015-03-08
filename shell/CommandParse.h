/**
 *Shell Simulator
 *2010.08.09 by alex.
 */

#ifndef SHELL_COMMAND_PARSE_H_
#define SHELL_COMMAND_PARSE_H_
#pragma once

#include <iostream>
#include <string>
#include "base/SmartPtr.h"
#include "shell/ShellCommand.h"

using namespace std;

/**
 * ʹ��SmartPointer ���ƣ� ���ھ�������smart_ptr���Ƶ�ʵ����
 * �̳�RefCount�����࣬ʹ��ʱ��SmartPointerģ��ʵ������
 * SmartPointer<CommandParse> pointer = new CommandParse;
 * SmartPointer<CommandParse> pointer(new CommandParse);
 * �������ָͨ��ӿڣ�һ���Ż���ָ���ܡ�
 * 1.�����ڴ�й©
 * 2.�Զ������ڴ�Ļ���
 * 3.����ָ���ĸ�ֵ���ã����ͷ�����һ��ָ�룬���������ָ��
 * ������ָ�򲻸����ڵĶ��󡣼����ǳ����ָ��ѿռ�ʱ�������⡣
 * ����ָ�򹫹����ݶ����⡣
 */
class CommandParse : public ShellCommand,
					 public RefCounted {
public:
	CommandParse();

	void execute(int nparams, char **params);

	const string cmd_help();

};

#endif /* SHELL_COMMAND_PARSE_H_ */