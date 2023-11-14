#include "monty.h"

/**
 * add_to_stck- pushes an element to the stack
 * 
 * @stck: the doubly link list containing the stack
 * 
 * @linum: the line in the file
*/
stack_t add_to_stck(stack_t **stck, __attribute__((unused)) unsigned int linum)
{
    
}

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
                print_error(6);
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

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
		print_error(8);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}




