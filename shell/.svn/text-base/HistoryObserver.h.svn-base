/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

#ifndef SHELL_HISTORY_OBSERVER_H_
#define SHELL_HISTORY_OBSERVER_H_
#pragma once

#include <string>
#include "base/Observer.h"
#include "shell/History.h"

using namespace std;

class History;

class HistoryObserver : public Observer<History> {
public:

	HistoryObserver();
	~HistoryObserver();

	/**
	 * If get user command line ,then notify() the register class
	 * @param command_line  user input command line
	 */
	void get_command(string command_line);

	void notify();

private:

	string command_line;
	
};

#endif /* SHELL_HISTORY_OBSERVER_H_ */