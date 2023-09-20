#include "ourshell.h"
/**
 * func_exit_shell - function that makes it possible to;exits the shell
 * @dtsh: data
 * Return: 0 on success.
 */
int func_exit_shell(project_shell *dtsh)
{
	unsigned int u;
	int _dig;
	int strlen_n;
	int big_number;

	if (dtsh->args[1] != NULL)
	{
		u = func_atoi(dtsh->args[1]);
		_dig = func_isdigit(dtsh->args[1]);
		strlen_n = func_strlen(dtsh->args[1]);
		big_number = u > (unsigned int)INT_MAX;
		if (!_dig || strlen_n > 10 || big_number)
		{
			func_get_error(dtsh, 2);
			dtsh->status = 2;
			return (1);
		}
		dtsh->status = (u % 256);
	}
	return (0);
}
