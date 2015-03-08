/*
 * Shell Simulator
 * 2010.08.09 by alex
 * 2010.08.16 by alex
 */

#ifndef SHELL_SHELL_H_
#define SHELL_SHELL_H_
#pragma once

#include "shell/ShellCommand.h"
#include "shell/CommandHelp.h"
#include "shell/CommandParse.h"
#include "shell/AtmSimulator.h"
#include "shell/Echo.h"
#include "shell/ExitCommand.h"
#include "shell/WordCount.h"
#include "shell/History.h"
#include "shell/HistoryObserver.h"
#include "shell/CatCommand.h"
#include "shell/SortCommand.h"
#include "shell/PingCommand.h"
#include "shell/ChangeDirCommand.h"

#if defined(_WIN32)
#define OS_WIN
#include <process.h>
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <direct.h>
#elif defined(__GNUC__)
#define OS_GNU
#include <unistd.h>
#include <stdlib.h>
#endif

#define MAX_ARGV 25
#define MAX_COMMAND_LINE 1000

class Shell{
public:

	Shell();
	~Shell();

	/**
	 * Executes the Shell by entering an infinite loop.
	 * @return Never.
	 */
	int run();

	/**
	 * Executes the given command.
	 * @param cmdline Command to execute.
	 * @return Exit status of the command.
	 */
	void execute(char *cmdline);


    private:
    
	/**
	 * Fetch a command from standard input.
	 * @return Pointer to a command.
	 */
	char *getCommand();
    
	/**
	 * Output a prompt.
	 */
	void prompt();

	/**
	 * Check the command.
	 */
	int checkCommand(string cmdline);

	/**
	 * Parses an input string into separate pieces.
	 * @param cmdline Command input string.
	 * @param argv Argument list buffer.
	 * @param maxArgv Maximum number of entries in argv.
	 * @return Number of parsed arguments.
	 */	
	static int parse(char *cmdline, char **argv, int max_argv);



private:

	/* CopyRight */
	static const string CopyRight; 

	CommandHelp *m_help;

	/* SmartPoint object. */
	SmartPointer<CommandParse> m_parse;

	AtmSimulator *m_atm;
	echo::Echo * m_echo;
	ExitCommand *m_exit;
	WordCount *m_wc;

	History *m_history;
	HistoryObserver *m_history_observer;

	CatCommand *m_cat;

	SortCommand *m_sort;

	ChangeDirCommand *m_cd;

#ifdef OS_GNU
	PingCommand *m_ping;

	
#endif

};

#endif /* SHELL_SHELL_H_ */

