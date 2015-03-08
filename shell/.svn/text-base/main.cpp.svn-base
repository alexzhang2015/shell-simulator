/*
 * Shell Simulator 
 * 2010.08.09 by alex
 * 通过Bridge模式构建基础Shell架构。
 * 2010.08.16 by alex
 * 增加命令行解析 Shell,parser() ,和ShellCommand的execute() ,增加入口参量。
 * 2010.08.17 by alex
 * 增加ATM命令模块，和Linux平台的移植。
 * 2010.08.18 by alex
 * 增加filesystem模块，history命令记录在AlexFS上，加入factary 模式，
 * observer模式。
 * 2010.08.19 by alex
 * 增加singleton 模式，结合cat命令。
 * 2010.08.20 by alex
 * 增加sort 模块，主要通过strategy模式抽象出sort接口。
 * 2010.08.21 by alex
 * 增加 smart_pointer 模板的实现。
 * 2010.08.22 by alex
 * 增加 SortScheduler sort排序中的一个调度器。
 * 2010.09.06 by alex
 * Add ping command in GNU OS.
 * 2010.09.08 by alex
 * Add sqlite database for Atm log system.
 * 2010.09.14 by alex
 * Add ChangeDirCommand .
 * 2010.09.15 by alex
 * Add extern commands /bin for Windows version.
 * 2010.09.16 by alex
 * Add Tab Completion for Linux version.
 */

#include "shell/Shell.h"

int main()
{

	/* shell run loop. */
	Shell sh;
	sh.run();
	return 0;
}
