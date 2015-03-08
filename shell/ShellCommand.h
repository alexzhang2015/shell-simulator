/*
 * Shell Simulator
 * 2010.08.09 by alex
 * 2010.08.16 by alex
 */

#ifndef SHELL_SHELLCOMMAND_H_
#define SHELL_SHELLCOMMAND_H_
#pragma once

#include <map>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class ShellCommand;

typedef map<string,ShellCommand *> shellMap;

class ShellCommand{
public:

	/**
	 * Constructor function.
	 * @param name Unique name of the command.
	 */
	ShellCommand();
	ShellCommand(const string name);

	/**
	 * Destructor function.
	 */
	~ ShellCommand();

	/**
	 * Execute the command.
	 * @param nparams Number of parameters given.
	 * @param params Array of parameters.
	 * @return Error code or zero on success.
	 */
	virtual void execute(int nparams, char **params) = 0;

	/**
	 * Get the help string for this command.
	 * @return Pointer to character string describing what the command does.
	 */
	virtual const string cmd_help() = 0;

	/**
	 *Look up a command via it's name.
	 * @param name Unique name of the command to find.
	 * @return Pointer to a ShellCommand object if found, ZERO otherwise.
	 */
	static ShellCommand *byName(string m_name);
	
	static shellMap getCommand();

protected:
	
	/** Unique name of the command. */
	string name;

	/** All known ShellCommands. */
	static shellMap commands;
};


#endif /* SHELL_SHELLCOMMAND_H_ */