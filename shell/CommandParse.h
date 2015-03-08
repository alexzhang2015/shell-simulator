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
 * 使用SmartPointer 机制， 对于具体引入smart_ptr机制的实体类
 * 继承RefCount计数类，使用时对SmartPointer模板实例化，
 * SmartPointer<CommandParse> pointer = new CommandParse;
 * SmartPointer<CommandParse> pointer(new CommandParse);
 * 抽象成普通指针接口，一种优化的指针框架。
 * 1.避免内存泄漏
 * 2.自动处理内存的回收
 * 3.避免指针间的赋值引用，先释放其中一个指针，造成其他的指针
 * 悬垂，指向不复存在的对象。即解决浅拷贝指针堆空间时析构问题。
 * 处理指向公共数据堆问题。
 */
class CommandParse : public ShellCommand,
					 public RefCounted {
public:
	CommandParse();

	void execute(int nparams, char **params);

	const string cmd_help();

};

#endif /* SHELL_COMMAND_PARSE_H_ */