#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 *
 * @stack: stack
 *
 * @line_number: line number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int top_element;

	if (stack == NULL || (*stack) == NULL)
		print_error(16, line_number);
	top_element = (*stack)->n;

	if (top_element < 0 || top_element > 127)
		print_error(15, line_number);
	putchar(top_element);
	putchar(10);
}
