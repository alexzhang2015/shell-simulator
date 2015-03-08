/*
 * Shell Simulator
 * 2010.09.06 by alex ,All rights reserved.
 * This source code is governed by GNU GENERAL PUBLIC LICENSE
 */

#ifndef SHELL_PING_COMMAND_H_
#define SHELL_PING_COMMAND_H_
#pragma once

#include "base/Macro.h"
#include "base/Singleton.h"
#include "shell/ShellCommand.h"

#ifdef OS_GNU

class PingCommand : public ShellCommand,
	                public Singleton<PingCommand> {
public:
	PingCommand();
	~PingCommand();

	void execute(int nparams, char **params);

	const string cmd_help();

	//friend void usage(void);
};

#endif /* OS_GNU */
#endif /* SHELL_PING_COMMAND_H_ */
