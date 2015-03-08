/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

#include "shell/WordCount.h"

#include <fstream>
#if defined(__GNUC__)
#include <string.h>
#endif

WordCount::WordCount() : ShellCommand("wc")
{
}

WordCount::~WordCount()
{
}

void WordCount::execute(int nparams, char **params)
{
	string tmp;
	int m_line = 0;
	int m_word = 0;
	int m_char = 0;

	if (nparams < 3)
	{
		usage();
		return ;
	}
	for (int i = 2; i < nparams; i++)
	{
		ifstream ifs(params[i]);
		if (ifs.is_open() && strcmp(params[1], "-f") == 0)
		{
			ifs.close();
			
			cout << setw(10)
				 << "line: "
				 << line_count(i, params)
				 << '\t';
			m_line += line_count(i, params);
			
			cout << setw(10)
				 << "word: "
				 << word_count(i, params)
				 << '\t';
			m_word += word_count(i, params);
		
			cout << setw(10)
				 << "char: "
				 << char_count(i, params)
				 << '\t';
			m_char += char_count(i, params);

			cout << setw(10)
				 << params[i]
				 << endl;
					
		}

		else if (strcmp(params[1], "-f") != 0)
		{
			usage();
		}
		else 
		{
			cout << "Can't find the file:"
				 << params[i]
				 << endl;
		}
	}

	/**
	 * 文件超过2个，计算所以文件的wc信息。 
	 */
	if (nparams > 3)
	{
	
		cout << setw(10)
			 << "line: "
			 << m_line
			 << '\t';
		
		cout << setw(10)
			 << "word: "
			 << m_word
			 << '\t';
	
		cout << setw(10)
			 << "char: "
			 << m_char
			 << '\t';

		cout << setw(10)
			 << "total"
			 << endl;
	}
}

void WordCount::usage()
{
	cout << "usage : wc -f filename ."
		 << endl;
}

const string WordCount::cmd_help()
{
	return "Count the words and lines of file.";
}

/**
 * 计算line行数。
 */
int WordCount::line_count(int nparams, char **params)
{
	int line_count = 0;
	string tmp;
	ifstream ifs(params[nparams]);
	while (!ifs.eof())
	{
		getline(ifs, tmp, '\n');
		line_count++;
	}
		
	ifs.close();
	return line_count;

}

/**
 * 计算word单词数。
 */
int WordCount::word_count(int nparams, char **params)
{
	int word_count = 0;
	string tmp;
	ifstream ifs(params[nparams]);
	while (!ifs.eof())
	{
		getline(ifs, tmp, ' ');
		if (tmp.find('\n') != string::npos && *(tmp.end() - 1) != '\n')
		{
			word_count++;
		}
		word_count++;
	}
	ifs.close();
	return word_count;
}

/**
 * 计算char字符数。
 */
int WordCount::char_count(int nparams, char **params)
{
	int char_count = 0;
	string tmp;
	ifstream ifs(params[nparams]);
	while (!ifs.eof())
	{
		getline(ifs, tmp, '\n');
		char_count += tmp.size(); 
	}
	ifs.close();
	return char_count;
}