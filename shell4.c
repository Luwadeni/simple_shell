#include "ourshell.h"
/**
 * func_help - function; infomation for builtin help.
 * Return: NULL
 */
void aux_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";/*help builti-in */

	write(STDOUT_FILENO, help, func_strlen(help));
	help = "\tDisplay information about builtin commands.\n ";/*help fun */
	write(STDOUT_FILENO, help, func_strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, func_strlen(help));
}
/**
 * func_help_alias - function data info for builtin alias.
 * Return: NULL
 */
void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";/*for alias function */

	write(STDOUT_FILENO, help, func_strlen(help));
	help = "\tDefine or display aliases.\n ";/*defines alias function */
	write(STDOUT_FILENO, help, func_strlen(help));
}
/**
 * func_help_cd - function help data for builtin cd.
 * Return: NULL
 */
void aux_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, func_strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, func_strlen(help));
}
