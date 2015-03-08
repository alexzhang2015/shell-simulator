/*
 * Shell Simulator
 * 2010.09.14 by alex
 */

#include "shell/ChangeDirCommand.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "base/Macro.h"
#include "base/alex_string.h"

#ifdef OS_WIN
#include <direct.h>
#endif

#ifdef OS_GNU
#include <unistd.h>
#endif


ChangeDirCommand::ChangeDirCommand() : ShellCommand("cd")
{
}

void ChangeDirCommand::execute(int nparams, char **params)
{

	if (nparams == 1)
	{
#ifdef OS_WIN
		char *buffer;

		/*
		 * In Windows Get the current woring directory;
		 */

		if ((buffer = _getcwd(NULL, 0)) == NULL)
		{
			perror("_getcwd error");
		}
		else
		{
			printf( "%s", buffer);
			free(buffer);
		}
	
#endif

	/**
	 * In Linux cd to the home directory.
	 */
#ifdef OS_GNU
		char *home = getenv("HOME");
	    char *full_path_name = new char[100];
	    str_cpy(full_path_name, home);
	    chdir(full_path_name);

		delete full_path_name;
#endif
	}

	else if (nparams > 1)
	{
#ifdef OS_WIN
		if (_chdir(params[1]))
#endif

#ifdef OS_GNU
        if (chdir(params[1]))
#endif
		{
		  switch (errno)
		  {
		  case ENOENT:
			 printf( "Unable to locate the directory: %s\n", params[1]);
			 break;
		  case EINVAL:
			 printf( "Invalid buffer.\n");
			 break;
		  default:
			 printf( "Unknown error.\n");
		  }
		}
		else
		{
		}
	}

}

const string ChangeDirCommand::cmd_help()
{
	return "Change Direction Command!";
}