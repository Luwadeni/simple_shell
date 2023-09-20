#include "ourshell.h"
/**
 * func_cmp_env_name - function that compares env variables names wit name passed
 * @nenv: environment variable name
 * @name: name passed
 * Return: 0 if are not equal. Another value if they are.
 */
int func_cmp_env_name(const char *nenv, const char *name)
{
	int k;

	for (k = 0; nenv[k] != '='; k++)
	{
		if (nenv[k] != name[k])
		{
			return (0);
		}
	}

	return (k + 1);
}
/**
 * func_getenv - function to get an environment variable
 * @name: environment variable name
 * @_environ: environment variable
 * Return: the value of envir variabe else NULL
 */
char *func_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int z, mov;

	ptr_env = NULL;
	mov = 0;

	for (z = 0; _environ[z]; z++)
	{
		mov = func_cmp_env_name(_environ[z], name);
		if (mov)
		{
			ptr_env = _environ[z];
			break;
		}
	}

	return (ptr_env + mov);
}
/**
 * func_env - function that prints the evironment variables
 * @dtsh: data
 * Return: 1 on success.
 */
int func_env(project_shell *dtsh)
{
	int a, b;

	/* for loop for agumentation */
	for (a = 0; dtsh->_environ[a]; a++)
	{

		for (b = 0; dtsh->_environ[a][b]; b++)
			;

		write(STDOUT_FILENO, dtsh->_environ[a], b);
		write(STDOUT_FILENO, "\n", 1);
	}
	dtsh->status = 0;

	return (1);
}
