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

	if ((top_element < 0 || top_element > 127)
		print_error(15, line_number);
	printf("%c\n", top_element);
}
/**
 * rotl - rotates the stack to the top
 * The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 * @stack: the stack
 * @line_number: the line number of rotl opcode
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *iterator, *second_element;

	(void) line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	iterator = *stack;
	second_element = (*stack)->next;
	while (iterator->next != NULL)
		iterator = iterator->next;
	second_element->prev = NULL;
	(*stack)->next = NULL;
	iterator->next = *stack;
	(*stack)->prev = iterator;
	*stack = second_element;

}
