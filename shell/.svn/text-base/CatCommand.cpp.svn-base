/*
 * Shell Simulator
 * 2010.08.19 by alex
 */

#include "shell/CatCommand.h"

#include <fstream>

CatCommand::CatCommand() : ShellCommand("cat")
{
}

CatCommand::~CatCommand()
{
}

void CatCommand::execute(int nparams, char **params)
{
	if (nparams < 2)
	{
		usage();
		return ;
	}
	
	ifstream ifs(params[1]);
	if (ifs.is_open())
	{
		string line_content;
		while (!ifs.eof())
		{
			getline(ifs, line_content);
			cout << line_content
				 << '\n';
		}
		ifs.close();
	}
	else
	{
		cout << "cat: "
			 << params[1]
		 	<< ": No such file.";
	}
}

const string CatCommand::cmd_help()
{
	return "Concatenate files and print on the standard output.";
}

void CatCommand::usage()
{
	cout << "cat filename .";
}