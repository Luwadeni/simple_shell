#include "ourshell.h"
/**
 * func_without_comment - function that deletes comments from the input
 * @in: input string input
 * Return: input
 */
char *func_without_comment(char *in)
{
	int z, z_to;

	z_to = 0;
	for (z = 0; in[z]; z++)
	{
		if (in[z] == '#')
		{
			if (z == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[z - 1] == ' ' || in[z - 1] == '\t' || in[z - 1] == ';')
				z_to = z;
		}
	}

	if (z_to != 0)
	{
		in = func_realloc(in, z, z_to + 1);
		in[z_to] = '\0';
	}

	return (in);
}
/**
 * looper - function for loop of shell
 * @dtsh: data
 * Return: NULL
 */
void looper(project_shell *dtsh)
{
	int loop, iff;
	char *input;

	for (loop = 1; loop == 1;)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = func_read_line(&iff);
		if (iff != -1)
		{
			input = func_without_comment(input);
			if (input == NULL)
				continue;

			if (c_x_e(dtsh, input) == 1)
			{
				dtsh->status = 2;
				free(input);
				continue;
			}
			input = var_replace(input, dtsh);
			loop = func_split_commands(dtsh, input);
			dtsh->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
