/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

#ifndef SHELL_WORD_COUNT_H_
#define SHELL_WORD_COUNT_H_
#pragma once

#include "base/Factory.h"
#include "shell/ShellCommand.h"

class WordCount : public ShellCommand, 
					public Factory<WordCount> {
public:
	explicit WordCount();
	~WordCount();

	void execute(int nparams, char **params);

	const string cmd_help();

	void usage();

	int line_count(int nparams, char **params);
	int word_count(int nparams, char **params);
	int char_count(int nparams, char **params);

};
#endif /* SHELL_WORD_COUNT_H_ */