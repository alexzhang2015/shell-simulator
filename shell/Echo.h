/**
 * Shell Simulator
 * 2010.08.17 by alex
 * Echo Command.
 */

#ifndef SHELL_ECHO_H_
#define SHELL_ECHO_H_
#pragma once

#include "shell/ShellCommand.h"

namespace echo {

class Echo : public ShellCommand {
public:

	Echo();
	~Echo();

	void execute(int nparams, char **params);

	const string cmd_help();
};

} /* namespace echo */

#endif /* SHELL_ECHO_H_ */