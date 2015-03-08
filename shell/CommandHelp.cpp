/*
 * Shell Simulator
 * 2010.08.16 by alex
 */

#include "shell/CommandHelp.h"

CommandHelp::CommandHelp() : ShellCommand("help")
{
}

void CommandHelp::execute(int nparams, char **params)
{
	
    cout << "List of builtin Shell commands:\r\n\r\n";

	shellMap::const_iterator i = commands.begin();
	for (; i != commands.end(); i++)
    {
		cout << (*i).first
			 << "--" 
			 << (*i).second->cmd_help()
		     << endl;
    }
   
}

const string CommandHelp::cmd_help()
{
	return "Print help message!";
}