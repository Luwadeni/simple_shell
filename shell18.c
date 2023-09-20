#include "ourshell.h"
/**
 * func_exec_line - that finds builtins and commands
 * @dtsh: data for arguments
 * Return: 1 on success.
 */
int func_exec_line(project_shell *dtsh)
{
	int (*builtin)(project_shell *dtsh);

	if (dtsh->args[0] == NULL)
		return (1);

	builtin = func_get_builtin(dtsh->args[0]);

	if (builtin != NULL)
		return (builtin(dtsh));

	return (func_cmd_exec(dtsh));
}
