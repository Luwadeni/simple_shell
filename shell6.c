#include "ourshell.h"
/**
 * func_add_rvar_node - function that add up a variable
 * @head: head of linked list.
 * @lvar: variable length
 * @val: variable value
 * @lval: length of the value.
 * Return: head.
 */
r_var *func_add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->link = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = new;
	}

	return (*head);
}
/**
 * func_free_rvar_list - function that frees up an r_var list
 * @head: head of linked list.
 * Return: NULL
 */
void func_free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->link;
			free(temp);
		}
		*head = NULL;
	}
}
