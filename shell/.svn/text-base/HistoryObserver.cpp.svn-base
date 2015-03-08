/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

#include "shell/HistoryObserver.h"

HistoryObserver::HistoryObserver()
{
}

HistoryObserver::~HistoryObserver()
{
}

void HistoryObserver::get_command(std::string command_line)
{
	this->command_line = command_line;
}

void HistoryObserver::notify()
{

	list<History *>::iterator it;
	it = list_t.begin();
	for (; it != list_t.end(); it++)
	{
		(*it)->log_history("history" , this->command_line);
	}
}