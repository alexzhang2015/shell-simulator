/**
 *Shell Simulator
 *2010.08.09 by alex.
 */

#include "shell/ShellCommand.h"

shellMap ShellCommand::commands;

ShellCommand::ShellCommand()
{
}

ShellCommand::ShellCommand(string name)
{
	this->name = name;
	commands[this->name] = this;
}

ShellCommand::~ShellCommand()
{
}

ShellCommand *ShellCommand::byName(string m_name)
{
    string str = m_name;
    return commands[str];
}

shellMap ShellCommand::getCommand()
{
	return commands;
}