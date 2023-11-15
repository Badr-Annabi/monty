 #include "monty.h"

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: the stack
 *
 * @line_number: the line where div is given
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result, top_element;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error(11, line_number);
	(*stack) = (*stack)->next;
	top_element = (*stack)->prev->n;
	if (top_element == 0)
		print_error(12, line_number);
	result = (*stack)->n / top_element;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

