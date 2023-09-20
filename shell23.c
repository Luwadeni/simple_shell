#include "ourshell.h"
/**
 * func_bring_line - function that assigns the line var for get_line
 * @lptr: Buffer function that store the input str
 * @buffer: str that is been called to line
 * @i: size of line
 * @k: size of buffer
 */
void func_bring_line(char **lptr, size_t *i, char *buffer, size_t k)
{

	if (*lptr == NULL)
	{
		if  (k > BUFSIZE)
			*i = k;

		else
			*i = BUFSIZE;
		*lptr = buffer;
	}
	else if (*i < k)
	{
		if (k > BUFSIZE)
			*i = k;
		else
			*i = BUFSIZE;
		*lptr = buffer;
	}
	else
	{
		func_strcpy(*lptr, buffer);
		free(buffer);
	}
}
/**
 * func_get_line - function that reads input
 * @lptr: buffer that stores the input
 * @i: size of lineptr
 * @stream: stream to read from
 * Return: bytes number
 */
ssize_t func_get_line(char **lptr, size_t *i, FILE *stream)
{
	int n;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		n = read(STDIN_FILENO, &t, 1);
		if (n == -1 || (n == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (n == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = func_realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	func_bring_line(lptr, i, buffer, input);
	retval = input;
	if (n != 0)
		input = 0;
	return (retval);
}
