/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

#ifndef SHELL_HISTORY_H_
#define SHELL_HISTORY_H_
#pragma once

#include "base/Factory.h"
#include "filesystem/alex_fs.h"
#include "shell/HistoryObserver.h"
#include "shell/ShellCommand.h"

class HistoryObserver;

class History : public ShellCommand, 
					public Factory<History> {
public:
	History();
	History(HistoryObserver *history_observer);

	~History();

	void execute(int nparams, char **params);

	const string cmd_help();

	/**
	 * 通过Observer模式，由Shell中的getcommand方法触发Observer
	 */
	void log_history(const string history_name,
		             const string history_content);
	
	void get_history();

private:
	AlexFs *alexfs;

	HistoryObserver *history_observer;
	
	/* Full Path Name keep the history.img */
	char *full_path_name;

};
#endif /* SHELL_HISTORY_H_ */