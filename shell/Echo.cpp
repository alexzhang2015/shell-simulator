/*
 * Shell Simulator
 * 2010.08.17 by alex
 * Echo Command.
 */

#include "shell/Echo.h"
#if defined(__GNUC__)
#include <string.h>
#endif

namespace echo {

	Echo::Echo() : ShellCommand("echo")
	{
	}

	Echo::~Echo()
	{
	}

	void Echo::execute(int nparams, char **params)
	{
	    int i, newline = 1, args = 1;

		for (i = 1; i < nparams; i++)
		{
		
			/**
			 * echo -n xxx ,don't output a newline .
			 */
			if (args == 1 && strcmp(params[i], "-n") == 0)
			{
				newline = 0;
				continue;
			}
			args = 0;
			cout << params[i]
			     << " ";
		}
		if (newline)
		cout << '\n';
	}

	const string Echo::cmd_help()
	{
		return "Echo the input paraments !";
	}

} /* namespace echo */