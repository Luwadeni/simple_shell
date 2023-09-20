#include "ourshell.h"
/**
 * e_env - function for the error info for env in get_env.
 * @dtsh: data
 * Return: error message
 */
char *e_env(project_shell *dtsh)
{
	int length;
	char *errors;
	char *v_s;
	char *msg;

	v_s = func_itoa(dtsh->counter);
	msg = ": Unable to add/remove from environment\n";
	length = func_strlen(dtsh->av[0]) + func_strlen(v_s);
	length += func_strlen(dtsh->args[0]) + func_strlen(msg) + 4;
	errors = malloc(sizeof(char) * (length + 1));
	if (errors == 0)
	{
		free(errors);
		free(v_s);
		return (NULL);
	}

	func_strcpy(errors, dtsh->av[0]);
	func_strcat(errors, ": ");
	func_strcat(errors, v_s);
	func_strcat(errors, ": ");
	func_strcat(errors, dtsh->args[0]);
	func_strcat(errors, msg);
	func_strcat(errors, "\0");
	free(v_s);

	return (errors);
}
/**
 * e_path_126 - function for error info for path and failure denied permission.
 * @dtsh: data
 * Return: error string.
 */
char *e_path_126(project_shell *dtsh)
{
	int length;
	char *v_s;
	char *errors;

	v_s = func_itoa(dtsh->counter);
	length = func_strlen(dtsh->av[0]) + func_strlen(v_s);
	length += func_strlen(dtsh->args[0]) + 24;
	errors = malloc(sizeof(char) * (length + 1));
	if (errors == 0)
	{
		free(errors);
		free(v_s);
		return (NULL);
	}
	func_strcpy(errors, dtsh->av[0]);
	func_strcat(errors, ": ");
	func_strcat(errors, v_s);
	func_strcat(errors, ": ");
	func_strcat(errors, dtsh->args[0]);
	func_strcat(errors, ": Permission denied\n");
	func_strcat(errors, "\0");
	free(v_s);

	return (errors);
}
