#include "ourshell.h"
/**
 * func_get_error - calls the error according the builtin, syntax or permission
 * @dtsh: data structure that contains arguments
 * @ueval: error value
 * Return: error
 */
int func_get_error(project_shell *dtsh, int ueval)
{
	char *error;

	switch (ueval)
	{
	case -1:
		error = e_env(dtsh);
		break;
	case 126:
		error = e_path_126(dtsh);
		break;
	case 127:
		error = e_not_f(dtsh);
		break;
	case 2:
		if (func_strcmp("exit", dtsh->args[0]) == 0)
			error = e_exit_s(dtsh);
		else if (func_strcmp("cd", dtsh->args[0]) == 0)
			error = e_get_cd(dtsh);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, func_strlen(error));
		free(error);
	}

	dtsh->status = ueval;
	return (ueval);
}
