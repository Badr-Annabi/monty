#include "monty.h"
stack_t *head = NULL;
/**
 * create_node - creates a new node
 *
 * @n: data to put in node
 *
 * Return: pointer to the new created node
 */
stack_t *create_node(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		print_error(5);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * free_nodes - frees nodes in the stack
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
