/* 
 * Shell Simulator 
 * 2010.08.16 by alex
 */

#include "shell/CommandParse.h"

CommandParse::CommandParse() : ShellCommand("parse")
{
}

void CommandParse::execute(int nparams, char **params)
{
	if (nparams == 1)
	{
		cout << "Usage : parse argv[1] argv[2] ..."
			 << endl;
		return ;
	}
	cout << "command parameters:\n";
	for (int i= 1; i < nparams; i++)
	{
		cout << params[i]
		     << '\n';
	}
}

const string CommandParse::cmd_help()
{
	return "Parse the input command line !";
}