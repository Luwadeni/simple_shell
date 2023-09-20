#include "ourshell.h"
/**
 * func_get_sigint - function that handles prompt
 * @sig: Signal handler
 */
void func_get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
/**
 * func_read_line - function that reads the input string
 * @iff: it is the return value of getline function
 * Return: input string
 */
char *func_read_line(int *iff)
{
	char *input = NULL;
	size_t bufsize = 0;

	*iff = getline(&input, &bufsize, stdin);

	return (input);
}
