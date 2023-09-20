#include "ourshell.h"
/**
 * func_check_env - function;that checks if the typed variable is an env variable
 * @first: head of linked list
 * @in: input string input
 * @data: data structure
 * Return: NULL
 */
void func_check_env(r_var **first, char *in, project_shell *data)
{
	int row, chr, e, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (e = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = func_strlen(_envr[row] + chr + 1);
				func_add_rvar_node(first, e, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[e] == _envr[row][chr])
				e++;
			else
				break;
		}
	}

	for (e = 0; in[e]; e++)
	{
		if (in[e] == ' ' || in[e] == '\t' || in[e] == ';' || in[e] == '\n')
			break;
	}

	func_add_rvar_node(first, e, NULL, 0);
}
/**
 * func_check_vars - function thst check if the typed variable is $$ or $?
 * @first: head of the linked list
 * @in: input string input
 * @st: Shell last status
 * @data: data structure
 * Return: NULL
 */
int func_check_vars(r_var **first, char *in, char *st, project_shell *data)
{
	int e, lst, lpd;

	lst = func_strlen(st);
	lpd = func_strlen(data->pid);

	for (e = 0; in[e]; e++)
	{
		if (in[e] == '$')
		{
			if (in[e + 1] == '?')
				func_add_rvar_node(first, 2, st, lst), e++;
			else if (in[e + 1] == '$')
				func_add_rvar_node(first, 2, data->pid, lpd), e++;
			else if (in[e + 1] == '\n')
				func_add_rvar_node(first, 0, NULL, 0);
			else if (in[e + 1] == '\0')
				func_add_rvar_node(first, 0, NULL, 0);
			else if (in[e + 1] == ' ')
				func_add_rvar_node(first, 0, NULL, 0);
			else if (in[e + 1] == '\t')
				func_add_rvar_node(first, 0, NULL, 0);
			else if (in[e + 1] == ';')
				func_add_rvar_node(first, 0, NULL, 0);
			else
				func_check_env(first, in + e, data);
		}
	}

	return (e);
}
/**
 * replace_inputs - function thst replaces string into variables
 * @head: head of the linked list
 * @input: input string inut
 * @new_input: new input string
 * @nlen: new length
 * Return: the replaced string
 */
char *replace_inputs(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *position;
	int e, f, g;

	position = *head;
	e = f = 0;
	while (f < nlen)
	{
		if (input[f] == '$')
		{
			if (!(position->len_var) && !(position->len_val))
			{
				new_input[e] = input[f];
				f++;
			}
			else if (position->len_var && !(position->len_val))
			{
				for (g = 0; g < position->len_var; g++)
					f++;
				e--;
			}
			else
			{
				for (g = 0; g < position->len_val; g++)
				{
					new_input[e] = position->val[g];
					e++;
				}
				f += (position->len_var);
				e--;
			}
			position = position->link;
		}
		else
		{
			new_input[e] = input[f];
			f++;
		}
	}

	return (new_input);
}
/**
 * var_replace - function that calls functions to replace string with vars
 * @input: input string input
 * @dtsh: data struct
 * Return: the replaced string
 */
char *var_replace(char *input, project_shell *dtsh)
{
	r_var *first, *position;
	char *status, *new_input;
	int olen, nlen;

	status = func_itoa(dtsh->status);
	first = NULL;

	olen = func_check_vars(&first, input, status, dtsh);

	if (first == NULL)
	{
		free(status);
		return (input);
	}

	position = first;
	nlen = 0;

	while (position != NULL)
	{
		nlen += (position->len_val - position->len_var);
		position = position->link;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replace_inputs(&first, input, new_input, nlen);

	free(input);
	free(status);
	func_free_rvar_list(&first);

	return (new_input);
}
