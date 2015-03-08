# Shell Simulator 
# 2010.09.06 by alex

from SCons.Script import *

env = Environment(ENV = os.environ)
env = Environment( parse_flags = '-Latm -Lfilesystem -Lbase -Lthird_party/sqlite -Lthird_party/tinyxml -lATM -lAlexFs -lBASE -lSQLITE -lTINYXML -lpthread -ldl -lreadline -I. -g')

env.StaticLibrary('atm/ATM', ['atm.cpp', 'account_info.cpp', 'card.cpp', 'transaction.cpp', 
                    'deposit_transaction.cpp', 'inquiry_transaction.cpp', 
					'session.cpp', 'user.cpp', 'withdraw_transaction.cpp' ], srcdir = 'atm')

env.StaticLibrary('filesystem/AlexFs', ['super_block.cpp', 'alex_fs.cpp' ], srcdir = 'filesystem')

env.StaticLibrary('base/BASE', ['atoi.cpp', 'md5.cpp', 'IsDigit.cpp', 'str_cpy.cpp', 'str_cat.cpp'], srcdir = 'base')

env.StaticLibrary('third_party/sqlite/SQLITE', ['shell.c', 'sqlite3.c'], srcdir = 'third_party/sqlite')

env.StaticLibrary('third_party/tinyxml/TINYXML', ['tinystr.cpp', 'xmltest.cpp', 'tinyxml.cpp', 'tinyxmlparser.cpp', 'tinyxmlerror.cpp'], srcdir = 'third_party/tinyxml')

env.Program('Debug/alex',['AtmSimulator.cpp', 'ExitCommand.cpp' , 'Echo.cpp',	   'QuickSort.cpp'    , 'Sort.cpp'
 ,'CatCommand.cpp'    ,'History.cpp'  ,'MergeSort.cpp'  ,'ShellCommand.cpp'  ,'SortScheduler.cpp'
 ,'CommandHelp.cpp'   ,'HistoryObserver.cpp'  ,'Shell.cpp'   ,'ShellSort.cpp'      , 'BubbleSort.cpp',
 'SortCommand.cpp','SortStrategy.cpp' ,'CommandParse.cpp' , 'PingCommand.cpp', 'ChangeDirCommand.cpp'
,'main.cpp', 'WordCount.cpp' ], srcdir = 'shell')
