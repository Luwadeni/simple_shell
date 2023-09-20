#include "ourshell.h"
/**
 * func_get_len - function that gets the length of the number.
 * @n: the type int number.
 * Return: the length of the number.
 */
int func_get_len(int n)
{
	unsigned int n1;
	int lght = 1;

	if (n < 0)
	{
		lght++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		lght++;
		n1 = n1 / 10;
	}

	return (lght);
}
/**
 * func_itoa - function that changes int to string.
 * @n: the type int number
 * Return: a String.
 */
char *func_itoa(int n)
{
	unsigned int n1;
	int lght = func_get_len(n);
	char *buff_ptr;

	buff_ptr = malloc(sizeof(char) * (lght + 1));
	if (buff_ptr == 0)
		return (NULL);

	*(buff_ptr + lght) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buff_ptr[0] = '-';
	}
	else
	{
		n1 = n;
	}

	lght--;
	do {
		*(buff_ptr + lght) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lght--;
	} while (n1 > 0);

	return (buff_ptr);
}
/**
 * func_atoi - function that changes a string to an integer.
 * @s: the input string.
 * Return: an integer.
 */
int func_atoi(char *s)
{
	unsigned int tally = 0, size = 0, oi = 0, pn = 1, m = 1, r;

	while (*(s + tally) != '\0')
	{
		if (size > 0 && (*(s + tally) < '0' || *(s + tally) > '9'))
			break;

		if (*(s + tally) == '-')
			pn *= -1;

		if ((*(s + tally) >= '0') && (*(s + tally) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		tally++;
	}

	for (r = tally - size; r < tally; r++)
	{
		oi = oi + ((*(s + r) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
