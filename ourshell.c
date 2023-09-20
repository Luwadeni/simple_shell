#include "ourshell.h"
/**
 * freee_data - functionn that frees data struct
 * @data_struct: data struct
 * Return: NULL
 **********************************/
void freee_data(project_shell *data_struct)
{
unsigned int w = 0;
while (data_struct->_environ[w])
{
free(data_struct->_environ[w]);
w++;
}

free(data_struct->_environ);
free(data_struct->pid);
}
/**
 * sett_data- function that initialize data struct
 * @data_struct: data
 * @av: argument vector
 * Return: NULL
 **********************************/
void sett_data(project_shell *data_struct, char **av)
{
unsigned int num = 0;

data_struct->av = av;
data_struct->input = NULL;
data_struct->args = NULL;
data_struct->status = 0;
data_struct->counter = 1;

for (num = 0; environ[num]; ++);

data_struct->_environ = malloc(sizeof(char *) * (num + 1));

for (num = 0; environ[num]; num++)
{
data_struct->_environ[num] = func_strdup(environ[num]);
}

data_struct->_environ[num] = NULL;
data_struct->pid = func_itoa(getpid());
}
/**
 * main - the entry or intialization point
 * @ac: function for argument count
 * @av: the argument vector
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	project_shell data_struct;
	(void) ac;

	signal(SIGINT, func_get_sigint);
	sett_data(&data_struct, av);
	looper(&data_struct);
	freee_data(&data_struct);
	if (data_struct.status < 0)
		return (255);
	return (data_struct.status);
}
