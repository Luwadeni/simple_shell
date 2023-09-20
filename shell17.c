#include "ourshell.h"
/**
 * func_copy_info - function that copies info to create a new env or alias
 * @name: env name or alias name
 * @value: returns value of env or alia
 * Return: to new value of env or alias.
 */
char *func_copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = func_strlen(name);
	len_value = func_strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	/* copies string */
	func_strcpy(new, name);
	func_strcat(new, "=");
	func_strcat(new, value);
	func_strcat(new, "\0");

	return (new);
}
/**
 * func_set_env - function that sets an environment variable
 * @name: environment variable name
 * @value: environment variable value
 * @dtsh: data structure info
 * Return: NULL
 */
void func_set_env(char *name, char *value, project_shell *dtsh)
{
	int z;
	char *var_env, *name_env;

	for (z = 0; dtsh->_environ[z]; z++)
	{
		var_env = func_strdup(dtsh->_environ[z]);
		name_env = func_strtok(var_env, "=");
		if (func_strcmp(name_env, name) == 0)
		{
			free(dtsh->_environ[z]);
			dtsh->_environ[z] = func_copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	dtsh->_environ = func_reallocdp(dtsh->_environ, z, sizeof(char *) * (z + 2));
	dtsh->_environ[z] = func_copy_info(name, value);
	dtsh->_environ[z + 1] = NULL;
}
/**
 * func_setenv - function that compares env variables names
 * @dtsh: data for env name and value
 * Return: 1 on success.
 */
int func_setenv(project_shell *dtsh)
{

	if (dtsh->args[1] == NULL || dtsh->args[2] == NULL)
	{
		func_get_error(dtsh, -1);
		return (1);
	}

	func_set_env(dtsh->args[1], dtsh->args[2], dtsh);

	return (1);
}
/**
 * func_unsetenv - function that deletes environment variable
 * @dtsh: data
 * Return: 1 on success.
 */
int func_unsetenv(project_shell *dtsh)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int q, r, s;

	if (dtsh->args[1] == NULL)
	{
		func_get_error(dtsh, -1);
		return (1);
	}
	s = -1;
	for (q = 0; dtsh->_environ[q]; q++)
	{
		var_env = func_strdup(dtsh->_environ[q]);
		name_env = func_strtok(var_env, "=");
		if (func_strcmp(name_env, dtsh->args[1]) == 0)
		{
			s = q;
		}
		free(var_env);
	}
	if (s == -1)
	{
		func_get_error(dtsh, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (q));
	for (q = r = 0; dtsh->_environ[q]; q++)
	{
		if (q != s)
		{
			realloc_environ[r] = dtsh->_environ[q];
			r++;
		}
	}
	realloc_environ[r] = NULL;
	free(dtsh->_environ[s]);
	free(dtsh->_environ);
	dtsh->_environ = realloc_environ;
	return (1);
}
