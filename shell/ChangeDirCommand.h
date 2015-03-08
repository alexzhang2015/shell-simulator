/*
 * Shell Simulator
 * 2010.09.14 by alex
 */

#ifndef SHLEE_CHANGE_DIR_COMMAND_H_
#define SHLEE_CHANGE_DIR_COMMAND_H_
#pragma once 

#include "base/Singleton.h"
#include "shell/ShellCommand.h"

class ChangeDirCommand : public ShellCommand,
	               public Singleton<ChangeDirCommand> {
public:
	ChangeDirCommand();
	~ChangeDirCommand();

	void execute(int nparams, char **params);

	const string cmd_help();

	void usage();
};

#endif /* SHLEE_CHANGE_DIR_COMMAND_H_ */
