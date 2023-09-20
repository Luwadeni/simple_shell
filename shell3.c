#include "ourshell.h"
/**
 * aux_help_env - function;for help info for builtin env.
 */
void aux_help_env(void)
{
	char *help = "env: env [option] [name=value] [cmd_str [args]]\n\t";

	write(STDOUT_FILENO, help, func_strlen(help));
	help = "Print the environment of the shell.\n";
	write(STDOUT_FILENO, help, func_strlen(help));
}
/**
 * aux_help_setenv - function for help info for builtin setenv.
 */
void aux_help_setenv(void)
{
	char *help = "setenv: setenv (const char *name, const char *value, ";

	write(STDOUT_FILENO, help, func_strlen(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, func_strlen(help));
	help = "Add a new definition to the environment.\n";
	write(STDOUT_FILENO, help, func_strlen(help));
}
/**
 * aux_help_unsetenv - function forhelp info for builtin unsetenv.
 * Return: NULL
 */
void aux_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, func_strlen(help));
	help = "Remove an entry completely from the environment.\n";
	write(STDOUT_FILENO, help, func_strlen(help));
}
/**
 * aux_help_general - fuction for entry point for help info for help builtin.
 * Return: NULL
 */
void aux_help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, func_strlen(help));
	help = "These cmd_strs are defined internally. Type 'help' to see the list";
	write(STDOUT_FILENO, help, func_strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, func_strlen(help));
	help = "alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, func_strlen(help));
	help = "[dir]\nexit: exit [n]\n env: env [option] [name=value] [cmd_str ";
	write(STDOUT_FILENO, help, func_strlen(help));
	help = "[args]]\nsetenv: setenv [variable] [value]\nunsetenv: ";
	write(STDOUT_FILENO, help, func_strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, func_strlen(help));
}
/**
 * aux_help_exit - function for help info for builtin exit.
 * Return: NULL
 */
void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";/*help function msg */

	write(STDOUT_FILENO, help, func_strlen(help));
	help = "Exits the shell with a status of N. If N is omitted, the exit";
	write(STDOUT_FILENO, help, func_strlen(help));
	help = "status is that of the last cmd_str executed.\n";
	write(STDOUT_FILENO, help, func_strlen(help));
}
