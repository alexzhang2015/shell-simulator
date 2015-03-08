/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

#include "shell/ExitCommand.h"

#include <stdlib.h>
#include "base/Macro.h"

ExitCommand::ExitCommand() : ShellCommand("exit")
{
}

ExitCommand::~ExitCommand()
{
}

void ExitCommand::execute(int nparams, char **params)
{
	exit(SUCCESS);
}

const string ExitCommand::cmd_help()
{
	return "Exit the shell !";
}