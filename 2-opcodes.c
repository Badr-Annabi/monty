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

/**
 * _sub -  subtracts the top element of the stack
 * from the second top element of the stack
 *
 * @stack: the stack
 *
 * @line_number: the line number getting the opcode
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
		print_error(10, line_number);
	(*stack) = (*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _mul -  multiplies the second top element
 * of the stack with the top element of the stack.
 *
 * @stack: the stack
 *
 * @line_number: the line number getting the opcode
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
		print_error(13, line_number);
	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _mod - computes the rest of the division
 * of the second top element of the stack
 * by the top element of the stack.
 *
 * @stack: the stack
 *
 * @line_number: the line where div is given
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int result, top_element;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_error(14, line_number);
	(*stack) = (*stack)->next;
	top_element = (*stack)->prev->n;
	if (top_element == 0)
		print_error(14, line_number);
	result = (*stack)->n % top_element;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

