#include "ourshell.h"
/**
 * func_cd_shell - changes current dir to a different dir
 * @dtsh: data
 * Return: 1 on success
 */
int func_cd_shell(project_shell *dtsh)
{
	char *d;
	int x, y, z;

	d = dtsh->args[1];

	if (d != NULL)
	{
		x = func_strcmp("$HOME", d);
		y = func_strcmp("~", d);
		z = func_strcmp("--", d);
	}

	/* second if loop */
	if (d == NULL || !x || !y || !z)
	{
		func_cd_to_home(dtsh);
		return (1);
	}

	if (func_strcmp("-", d) == 0)
	{
		func_cd_previous(dtsh);
		return (1);
	}

	/* final if loop;arguments */
	if (func_strcmp(".", d) == 0 || func_strcmp("..", d) == 0)
	{
		func_cd_dot(dtsh);
		return (1);
	}

	/* infomation arguments */
	func_cd_dot(dtsh);

	return (1);
}
