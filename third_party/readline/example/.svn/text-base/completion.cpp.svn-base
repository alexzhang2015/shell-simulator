#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>	
#include <iostream>

using namespace std;

#include <readline/readline.h>
#include <readline/history.h>

char **fileman_completion (const char *text, int start, int end);
char *command_generator (const char *text, int state);
char * wpa_cli_dummy_gen(const char *text, int state);

  /* Return the next name which partially matches from the command list. */
  vector<string> command;
 
  vector<string>::const_iterator it;

struct wpa_cli_cmd {
        char *cmd;
        
};

static struct wpa_cli_cmd wpa_cli_commands[] = {
        { "status"  },
        { "ping"  },
        { "mib"  },
        { "help"  },
        { "interface"  },
        { "level" },
        { "license" },
        { NULL }
};

int main()
{

rl_attempted_completion_function =  fileman_completion;
 command.push_back("alex");
  command.push_back("jacl");
    static char line[100];
	char *line_tmp;

	line_tmp = readline ("");

	strcpy(line, line_tmp);
	free(line_tmp);
      cout << line ;
}

char **fileman_completion (const char *text, int start, int end)
{
 return rl_completion_matches(text, start == 0 ?
                                     command_generator : wpa_cli_dummy_gen);
}

char * wpa_cli_dummy_gen(const char *text, int state)
{
        return NULL;
}

char *command_generator (const char *text, int state)
{
  static int i, len;
  char *name;

  /* If this is a new word to complete, initialize now.  This includes
     saving the length of TEXT for efficiency, and initializing the index
     variable to 0. */
  if (!state)
    {
      i = 0;
      len = strlen (text);
    }

	

	while((name = wpa_cli_commands[i].cmd))
  {
  i++;
	
      if (strncmp (name, text, len) == 0)
      {
                 return strdup(name);
      }
  }

  /* If no names matched, then return NULL. */
  return NULL;
}
