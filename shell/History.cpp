/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

#include "shell/History.h"

#include "base/Macro.h"
#include "base/alex_string.h"

#if defined(__GNUC__)
#include <string.h>
#include <stdlib.h>
#endif

History::History() : ShellCommand("history")
{

}

History::History(HistoryObserver *history_observer) : ShellCommand("history")
{
	history_observer->attach(this);
	this->history_observer = history_observer;

	/**
	 * Set Windows history.img directory.
	 */
#ifdef OS_WIN
	char *homedrive;
	size_t requiredSize;
    getenv_s( &requiredSize, NULL, 0, "homedrive");
	homedrive = (char*) malloc(requiredSize * sizeof(char));
	getenv_s( &requiredSize, homedrive, requiredSize, "homedrive" );

	char *homepath = new char[50];
    getenv_s( &requiredSize, NULL, 0, "homepath");
	homepath = (char*) malloc(requiredSize * sizeof(char));
	getenv_s( &requiredSize, homepath, requiredSize, "homepath" );

	full_path_name = new char[100];

	str_cpy(full_path_name, homedrive);
    str_cat(full_path_name, homepath);
	str_cat(full_path_name, "\\history.img");
	
	delete homedrive;
	delete homepath;

	
#endif

	/**
	 * Set Linux history.img directory.
	 */
#ifdef OS_GNU
	char *home = getenv("HOME");
	full_path_name = new char[100];
	str_cpy(full_path_name, home);
	str_cat(full_path_name, "/history.img");
#endif

	alexfs = new AlexFs(full_path_name);

}

History::~History()
{
	history_observer->detach(this);
	delete alexfs;
	delete full_path_name;
}

void History::execute(int nparams, char **params)
{
	if (nparams == 2 && strcmp(params[1], "-ra") == 0)
	{
		try {
			bool err;
			err = alexfs->delete_file("history");
			if (err)
			{
				throw SUCCESS;
			}
			else
			{
				throw FAILURE;
			}
		}
		catch(int &err) {
			if (!err)
			{
				cout << "Delete history file failure!"
					 << endl;
				exit(err);
			}

		}
	}
	this->get_history();
}

const string History::cmd_help()
{
	return "Print the shell history.";
}

void History::log_history(const string history_name,
						  const string history_content)
{
	try {
		bool err;
		err = alexfs->write_file(history_name, history_content);
		if (err)
		{
			throw SUCCESS;
		}
		else
		{
			throw FAILURE;
		}
	}
	catch(int &err)
	{
		if (!err)
		{
		cout << "Log history error!"
			 << endl;
		exit(err);
		}
	}
}

void History::get_history()
{
	alexfs->read_all_file();	
}