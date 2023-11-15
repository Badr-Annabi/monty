#include "monty.h"

/**
 * _pint - prints the value at the top of the stack,
 * followed by a new line.
 * @stack: the stack that we work on.
 * @line_number: it containes the line number of the opcode.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack) == NULL)
	{
		print_error(6, line_number);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: the stack that we work on.
 * @line_number : it containes the line number of the opcode.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
		print_error(8, line_number);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}


/**
 * _pop - removes the top element of the stack.
 * @stack: stack that we re working on.
 * @line_number: line number of the opcode.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		print_error(7, line_number);
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

