/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

#ifndef SHELL_EXIT_COMMAND_H_
#define SHELL_EXIT_COMMAND_H_
#pragma once

#include "base/Factory.h"
#include "shell/ShellCommand.h"

class ExitCommand : public ShellCommand, 
					public Factory<ExitCommand> {
public:
	ExitCommand();
	~ExitCommand();

	void execute(int nparams, char **params);

	const string cmd_help();

};

#endif /* SHELL_EXIT_COMMAND_H_ */
