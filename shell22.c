#include "ourshell.h"
/**
 * func_get_help - function that retrieves help messages
 * @dtsh: data structure
 * Return: Return 0
*/
int func_get_help(project_shell *dtsh)
{

	if (dtsh->args[1] == 0)
		aux_help_general();
	else if (func_strcmp(dtsh->args[1], "setenv") == 0)
		aux_help_setenv();
	else if (func_strcmp(dtsh->args[1], "env") == 0)
		aux_help_env();
	else if (func_strcmp(dtsh->args[1], "unsetenv") == 0)
		aux_help_unsetenv();
	else if (func_strcmp(dtsh->args[1], "help") == 0)
		aux_help();
	else if (func_strcmp(dtsh->args[1], "exit") == 0)
		aux_help_exit();
	else if (func_strcmp(dtsh->args[1], "cd") == 0)
		aux_help_cd();
	else if (func_strcmp(dtsh->args[1], "alias") == 0)
		aux_help_alias();
	else
		write(STDERR_FILENO, dtsh->args[0],
		      func_strlen(dtsh->args[0]));

	dtsh->status = 0;
	return (1);
}
