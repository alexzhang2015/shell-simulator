/*
 * Shell Simulator
 * 2010.08.19 by alex
 */

#ifndef SHELL_CAT_COMMAND_H_
#define SHELL_CAT_COMMAND_H_
#pragma once 

#include "base/Singleton.h"
#include "shell/ShellCommand.h"

class CatCommand : public ShellCommand,
	               public Singleton<CatCommand> {
public:
	CatCommand();
	~CatCommand();

	void execute(int nparams, char **params);

	const string cmd_help();

	void usage();
};

#endif /* SHELL_CAT_COMMAND_H_ */
