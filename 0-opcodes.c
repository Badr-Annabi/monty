#include "monty.h"

/**
 * add_to_stack- pushes an element to the stack
 *
 * @node: the head of doubly link list containing the stack
 *
 * @line_num: the line in the file
 */
void add_to_stack(stack_t **node, unsigned int line_num)
{
	stack_t *tmp;
	(void) line_num;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	tmp = head;
	head = *node;
	head->next = tmp;
	tmp->prev = head;

}
/**
 * add_to_queue - dadds a node to the queue
 *
 * @node: pointer to the node to add
 *
 * @line_number: line number of the opcode
 */
void add_to_queue(stack_t **node, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
	}
	(*node)->prev = temp;
	temp->next = *node;
}
