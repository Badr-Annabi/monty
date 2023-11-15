#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 *
 * @stack: the stack
 *
 * @line_number: the line number getting the opcode
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
		print_error(9, line_number);
	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

