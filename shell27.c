#include "ourshell.h"
/**
 * func_swap_char - function that swaps
 * @input: input string input
 * @bool: type of swap
 * Return: the swapped string
 */
char *func_swap_char(char *input, int bool)
{
	int z;

	if (bool == 0)
	{
		z = 0;
		while (input[z])
		{
			if (input[z] == '|')
			{
				if (input[z + 1] != '|')
				input[z] = 16;
			}
			else
				z++;
		}
		if (input[z] == '&')
		{
			if (input[z + 1] != '&')
			input[z] = 12;
		}
		else
			z++;
	    z++;
	}
	else
    	{
		z = 0;
		while (input[z])
		{
			input[z] = (input[z] == 16 ? '|' : input[z]);
			input[z] = (input[z] == 12 ? '&' : input[z]);
			z++;
		}
	}
	return input;
}
/**
 * func_add_nodes - function that adds separators and command lines in the lists
 * @hhs: head of separator list
 * @hhl: head of command lines list
 * @input: input string input
 */
void func_add_nodes(sep_list **hhs, line_list **hhl, char *input)
{
	int z;
	char *line;

	input = func_swap_char(input, 0);

	for (z = 0; input[z]; z++)
	{
		if (input[z] == ';')
			func_add_sep_node_end(hhs, input[z]);

		if (input[z] == '|' || input[z] == '&')
		{
			func_add_sep_node_end(hhs, input[z]);
			z++;
		}
	}

	line = func_strtok(input, ";|&");
	do {
	line = func_swap_char(line, 1);
	func_add_line_node_end(hhl, line);
	line = func_strtok(NULL, ";|&");
    } while (line != NULL);
}
/**
 * func_go_link - function that goes to the link command line stored
 * @bb_a: separator list
 * @bb_b: command line list
 * @dtst: data struct
 */
void func_go_link(sep_list **bb_a, line_list **bb_b, project_shell *dtst)
{
    int loop_sep;
    sep_list *ls_s;
    line_list *ls_l;

    loop_sep = 1;
    ls_s = *bb_a;
    ls_l = *bb_b;

    while (ls_s != NULL && loop_sep)
    {
	if (dtst->status == 0)
	{
	    if (ls_s->separator == '&' || ls_s->separator == ';')
		loop_sep = 0;
	    if (ls_s->separator == '|')
		ls_l = ls_l->link, ls_s = ls_s->link;
	}
	else
	{
	    if (ls_s->separator == '|' || ls_s->separator == ';')
		loop_sep = 0;
	    if (ls_s->separator == '&')
		ls_l = ls_l->link, ls_s = ls_s->link;
	}
	if (ls_s != NULL && !loop_sep)
	    ls_s = ls_s->link;
    }

    *bb_a = ls_s;
    *bb_b = ls_l;
}
/**
 * func_split_commands - function that splits command lines according to the separators
 * @dtst: data struct
 * @input: input strin input
 * Return: 0 to exit, 1 to continue
 */
int func_split_commands(project_shell *dtst, char *input)
{
	sep_list *hhs, *bb_a;
	line_list *hhl, *bb_b;
	int loop;

	hhs = NULL;
	hhl = NULL;

	func_add_nodes(&hhs, &hhl, input);

    bb_a = hhs;
    bb_b = hhl;

    while (bb_b != NULL)
    {
	dtst->input = bb_b->line;
	dtst->args = func_split_line(dtst->input);
	loop = func_exec_line(dtst);
	free(dtst->args);

	if (loop == 0)
	    break;

	func_go_link(&bb_a, &bb_b, dtst);

	if (bb_b != NULL)
	    bb_b = bb_b->link;
    }

    func_free_sep_list(&hhs);
    func_free_line_list(&hhl);

    if (loop == 0)
	return 0;
    return 1;
}
/**
 * func_split_line - function for the token the input string
 * @input: input string inlut
 * Return: string splitted.
 */
char **func_split_line(char *input)
{
    size_t b;
    size_t z;
    char **tokens;
    char *token;

    b = TOK_BUFSIZE;
    tokens = malloc(sizeof(char *) * b);
    if (tokens == NULL)
    {
	write(STDERR_FILENO, ": allocation error\n", 18);
	exit(EXIT_FAILURE);
    }

    token = func_strtok(input, TOK_DELIM);
    tokens[0] = token;

    for (z = 1; token != NULL; z++)
    {
	if (z == b)
	{
	    b += TOK_BUFSIZE;
	    tokens = func_reallocdp(tokens, z, sizeof(char *) * b);
	    if (tokens == NULL)
	    {
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	    }
	}
	token = func_strtok(NULL, TOK_DELIM);
	tokens[z] = token;
    }

    return tokens;
}
