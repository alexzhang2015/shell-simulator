/**
 * Shell Simulator
 * 2010.08.17 by alex
 * AtmSimulator ,connect the ATM module
 */

#ifndef SHELL_ATM_SIMULATOR_H_
#define SHELL_ATM_SIMULATOR_H_
#pragma once

#include <iostream>
#include <string>
#include "shell/ShellCommand.h"

using namespace std;

class AtmSimulator : public ShellCommand {
public:
	AtmSimulator();

	void execute(int nparams, char **params);

	const string cmd_help();
	
};

#endif /* SHELL_ATM_SIMULATOR_H_ */