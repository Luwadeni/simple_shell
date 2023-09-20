#include "ourshell.h"
/**
 * repeat_chars - counts the number of times a char is repeated.
 * @input: string for input
 * @z: indextation
 * Return: number if reapeated chars
 */
int repeat_chars(char *input, int z)
{
	if (*(input - 1) == *input)
		return (repeat_chars(input - 1, z + 1));

	return (z);
}
/**
 * func_e_s_p - function that locates syntax errors
 * @input: input string iput
 * @z: indextation
 * @lt: last character read
 * Return: error index or 0 when no errors
 */
int func_e_s_p(char *input, int z, char lt)
{
	int c;

	c = 0;
	if (*input == '\0')
		return (0);

	/* if loop for 1st argument */
	if (*input == ' ' || *input == '\t')
		return (func_e_s_p(input + 1, z + 1, lt));

	if (*input == ';')
		if (lt == '|' || lt == '&' || lt == ';')
			return (z);

	if (*input == '|')
	{
		if (lt == ';' || lt == '&')
			return (z);

		if (lt == '|')
		{
			c = repeat_chars(input, 0);
			if (c == 0 || c > 1)
				return (z);
		}
	}

	if (*input == '&')
	{
		if (lt == ';' || lt == '|')
			return (z);

		if (lt == '&')
		{
			c = repeat_chars(input, 0);
			if (c == 0 || c > 1)
				return (z);
		}
	}

	return (func_e_s_p(input + 1, z + 1, *input));
}
/**
 * func_first_char - finds index of the first char
 * @input: input string
 * @z: index
 * Return: 1 if error, else 0
 */
int func_first_char(char *input, int *z)
{
	for (*z = 0; input[*z]; *z += 1)
	{
		if (input[*z] == ' ' || input[*z] == '\t')
			continue;

		if (input[*z] == ';' || input[*z] == '|' || input[*z] == '&')
			return (-1);

		break;
	}

	return (0);
}
/**
 * p_x_e - function that prints when a syntax error is found
 * @dtsh: data structure
 * @input: input string input
 * @z: indextation of the error nsgs
 * @bool: functio to control msg error
 * Return: NULL
 */
void p_x_e(project_shell *dtsh, char *input, int z, int bool)
{
	char *msg, *msg2, *msg3, *e, *counter;
	int length;

	if (input[z] == ';')
	{
		if (bool == 0)
			msg = (input[z + 1] == ';' ? ";;" : ";");
		else
			msg = (input[z - 1] == ';' ? ";;" : ";");
	}

	if (input[z] == '|')
		msg = (input[z + 1] == '|' ? "||" : "|");

	if (input[z] == '&')
		msg = (input[z + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = func_itoa(dtsh->counter);
	length = func_strlen(dtsh->av[0]) + func_strlen(counter);
	length += func_strlen(msg) + func_strlen(msg2) + func_strlen(msg3) + 2;

	e = malloc(sizeof(char) * (length + 1));
	if (e == 0)
	{
		free(counter);
		return;
	}
	func_strcpy(e, dtsh->av[0]);
	func_strcat(e, ": ");
	func_strcat(e, counter);
	func_strcat(e, msg2);
	func_strcat(e, msg);
	func_strcat(e, msg3);
	func_strcat(e, "\0");

	write(STDERR_FILENO, e, length);
	free(e);
	free(counter);
}

/**
 * c_x_e - intermediate function to
 * find and print a syntax error
 * @dtsh: data structure
 * @input: input string
 * Return: 1 if there is an error, 0 otherwise
 */
int c_x_e(project_shell *dtsh, char *input)
{
	int num = 0;
	int f_c = 0;
	int q = 0;

	f_c = func_first_char(input, &num);
	if (f_c == -1)
	{
		p_x_e(dtsh, input, num, 0);
		return (1);
	}

	q = func_e_s_p(input + num, 0, *(input + num));
	if (q != 0)
	{
		p_x_e(dtsh, input, num + q, 1);
		return (1);
	}

	return (0);
}
