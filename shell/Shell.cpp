/*
 *Shell Simulator
 *2010.08.09 by alex.
 */

#include "shell/Shell.h"

#include "base/Macro.h"
#include "shell/ShellCommand.h"

#ifdef OS_GNU
/**
 * Tab Completion Support.
 * Use the GNU readline library .How to install readline6.1 
 * just in the readme.txt.
 * We just add the embedded commands to the index commands.
 */ 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>
#endif

const string Shell::CopyRight = 
"Copyright (C) 2010 Alex Shell.\n\
Use help command get help. ";

#ifdef OS_GNU
/* Tab Completion for the embeded commands. */
struct shell_cmd {
        char *cmd;
};

#define MAX_CMD_COMMANDS 1024
static shell_cmd commands[MAX_CMD_COMMANDS] = {

};

char **command_completion (const char *text, int start, int end);
char *command_generator (const char *text, int state);
char *dummy_generator(const char *text, int state);

#endif


Shell::Shell()
{
	cout << CopyRight
		 << endl;

	/**
	 * Try/catch to capture dynamic memory error.
	 */
	try {
		/* Init the command. */
		m_help = new CommandHelp;         /* help */
		if (m_help == NULL)
		{
			throw NEW_OPERATOR_ERROR;
		}

		m_atm = new AtmSimulator;         /* atm */
		if (m_atm == NULL)
		{
			throw NEW_OPERATOR_ERROR;
		}

		m_echo = new echo::Echo;          /* echo */
		{
			throw NEW_OPERATOR_ERROR;
		}

		
	}

	catch(int &catch_error) {
		if (catch_error)
		{
			cout << "Fail to new the heap memory!"
				 << endl;
			exit(catch_error);
		}

		/* Factary Pattern */
		m_exit = ExitCommand::instance(); /* exit */
		m_wc = WordCount::instance();     /* wc */

		/**
		 * Singleton Pattern 
		 * CatCommand return the same instance.
		 */
		m_cat = CatCommand::instance();   /* cat */	
		m_cd = ChangeDirCommand::instance(); /* cd */

#ifdef OS_GNU
		m_ping = PingCommand::instance(); /* ping */
#endif 

		m_sort = new SortCommand();       /* sort */

		/**
		 * SmartPointer tactic.
		 */
		m_parse = new CommandParse;       /* parse */

	}

    /**
	 * 1.生成HistoryObserver的对象，对于History构造函数和
	 * m_history_observer观察者绑定，通过History构造函数
	 * 将m_history注册(订阅)到m_history_observer上，对于
	 * Observer模式主要负责解决一对多的消息传递，(订阅--->发布)
	 * 2.同时这种通过类对象指针传参方法，是一种所谓的回调(callback)
	 * 的思想，HistoryObserver将History类对象组合为私有成员，传参时
	 * 对成员赋值，适当情况下，HistoryObserver对象，通过私有History
	 * 对象指针，调用其接口，形成回调的过程。
	 */
	m_history_observer = new HistoryObserver();
	m_history = new History(m_history_observer);  /* history */

#ifdef OS_GNU

	/* Init the commands */
	shellMap tempMap;
	tempMap = ShellCommand::getCommand();
	int j = 0; 
	shellMap::const_iterator i = tempMap.begin();
	for (; i != tempMap.end(); i++)
        {
		if (j < MAX_CMD_COMMANDS - 1)
		{
			commands[j++].cmd = const_cast<char *>((*i).first.c_str());
		}
        }
	commands[j].cmd = NULL;

	/* Bind our completer. */
	rl_attempted_completion_function = command_completion;
#endif
	
}

Shell::~Shell()
{
	delete m_help;
	//delete m_parse;
	delete m_atm;
	delete m_echo;
	delete m_exit;
	delete m_wc;
	delete m_history;
	delete m_history_observer;

	delete m_sort;

}

int Shell::run()
{
    char *cmdStr;

    /* Read commands. */    
    while (true)
    {
	/* Print the prompt. */
	prompt();
	
	/* Wait for a command string. */
	cmdStr = getCommand();
	
	/* Execute the command. */
	execute(cmdStr);
    }
    return 1;
}

void Shell::execute(char *cmdline)
{
	char m_cmdline[MAX_COMMAND_LINE];
#ifdef OS_WIN
	strcpy_s(m_cmdline, cmdline);
#endif 
#ifdef OS_GNU
	strcpy(m_cmdline, cmdline);
#endif

	/* 
	 * argv[MAX_ARGV +1] ,处理在遇到输入达到最大参量时，
	 * 在parse()中，最后argv[argc] = NULL;不多分配一个
	 * 空间，则会在输入参量达到MAX_ARGV时出现execute()
	 * 执行完后，退出时出错，因为上面那个指针越界修改了
	 * 入口栈空间。
	 */
    char *argv[MAX_ARGV];

    int argc;
	ShellCommand *cmd;

	/* Attempt to extract arguments. */
	argc = parse(cmdline, argv, MAX_ARGV);

	/* 处理回车 */
	if (argc == 0)
	{
		return ;
	}

	//HANDLE hThread;
	//DWORD dwThreadId;
	//hThread = CreateThread( 
 //           NULL,              // default security attributes
 //           0,                 // use default stack size  
	//		history_obser,           // thread function 
 //           (PMYDATA) m_cmdline,           // argument to thread function 
 //           0,                 // use default creation flags 
 //           &dwThreadId );     // returns the thread identifier 

	/**
	 * HistoryObserver get_command() ,通知 notify();
	 * 这也是Observer模式的精华。
	 */
	m_history_observer->get_command(m_cmdline);
	m_history_observer->notify();

	/* 交给内嵌的命令执行 */
	string cmdStr = argv[0];
	if (checkCommand(cmdStr))
	{
		cmd = ShellCommand::byName(cmdStr);
		cmd->execute(argc, argv);
		cout << endl;
		return ;
	}

	

	/**
	 * 交给外部命令处理
	 * _execvp  文件名参数中如果没有\ 路径符号
	 * 则会自动将系统默认的环境变量作为路径。
	 * strcpy_s(file_name, "c:\\Windows\\System32\\");
	 * strcat_s(file_name, argv[0]);
	 */
#if defined(_WIN32)
	//HANDLE hThread;
	//DWORD dwThreadId;
	//hThread = CreateThread( 
 //           NULL,              // default security attributes
 //           0,                 // use default stack size  
	//		win_cmd,           // thread function 
 //           cmdline,           // argument to thread function 
 //           0,                 // use default creation flags 
 //           &dwThreadId );     // returns the thread identifier 
	
	//_beginthread(win_cmd, 0,(void *) cmdline);

	if (system(m_cmdline))
	{
		return ;
	}

#elif defined(__GNUC__)
	system(m_cmdline);
#endif


}

/**
 * WIndows version GetCommand() .
 */
#ifdef OS_WIN
char *Shell::getCommand()
{
    static char line[MAX_COMMAND_LINE];
	char *line_tmp = NULL;
	string m_line;
	cin.clear();
	cin.sync();
	getline(cin,m_line,'\n');

	/**
	 * 如果输入超过MAX_COMMAND_LINE个字节，舍弃后面的输入
	 */
	if (m_line.size() >= MAX_COMMAND_LINE)
	{
		m_line = m_line.substr(0, MAX_COMMAND_LINE - 1);
		m_line.push_back('\0');
	}

	line_tmp = const_cast<char *>(m_line.c_str());

	strcpy_s(line, line_tmp);

    return line;
}
#endif

/**
 * Linux Version GetCommand() 
 * Use GNU getline library, realize tab completion.
 */
#ifdef OS_GNU
char *Shell::getCommand()
{
    static char line[MAX_COMMAND_LINE];
	char *line_tmp;

	line_tmp = readline ("");
	
	add_history(line_tmp);
	strcpy(line, line_tmp);
	free(line_tmp);

	return line;
}
#endif

void Shell::prompt()
{
#ifdef OS_GNU
	cout << "shell:";
#endif

	char *buffer;

	// Get the current woring directory;
#ifdef OS_WIN
	if ((buffer = _getcwd(NULL, 0)) == NULL)
#endif

#ifdef OS_GNU
	if ((buffer = getcwd(NULL, 0)) == NULL)
#endif	
	{
		perror("getcwd error");
	}
	else
	{
		printf("%s", buffer);
		free(buffer);
	}
	cout << "$";
}

int Shell::checkCommand(std::string cmdline)
{
	shellMap checkMap;
	checkMap = ShellCommand::getCommand();
	if (checkMap.find(cmdline) != checkMap.end())
	{
		return true;
	}
	else
		return false;
}

int Shell::parse(char *cmdline, char **argv, int max_argv)
{
    int argc;

    for (argc = 0; argc < max_argv && *cmdline; argc++)
    {
	    while (*cmdline && *cmdline == ' ')
		{
			cmdline++;
		}

		argv[argc] = cmdline;
	
		while (*cmdline && *cmdline != ' ')
		{
			cmdline++;
		}
	
		if (*cmdline) 
		{
			*cmdline++ = '\0';
		}
    }
    argv[argc] = NULL;
    return argc;
}


#ifdef OS_GNU


char **command_completion (const char *text, int start, int end)
{
 	return rl_completion_matches(text, start == 0 ?
                                     command_generator : dummy_generator);
}

char *dummy_generator(const char *text, int state)
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



  while((name = commands[i].cmd))
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
#endif
