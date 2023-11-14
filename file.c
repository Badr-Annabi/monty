#include "monty.h"

/**
 * call_function - calls a specific function.
 * @op: opcode.
 * @value: numeric value.
 * @line_number: line number for the instruction.
 * @format: format equal 0 if we are in a stack, and 1 if we entered a queue.
 */
void call_function(char *op, char *value, int line_number, int format)
{
	int i, j, flag = 1;
	stack_t *node;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{NULL, NULL}
	};
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (op[0] == '#')
			return;
		if (strcmp(op, "push") == 0)
		{
			if (value != NULL && value[0] == '-')
			{
				value = value + 1;
				flag = -1;
			}
			if (value == NULL)
			{
				print_error(4, line_number);
				exit(EXIT_FAILURE);
			}

			for (j = 0; value[j] != '\0'; j++)
			{
				if (isdigit(value[i]) == 0)
				{
					print_error(1, line_number);
					exit(EXIT_FAILURE);
				}
			}
			node = create_node(atoi(value) * flag);
			if (format == 0)
				func_list[i].f(&node, line_number);
			if (format == 1)
				add_to_queue(&node, line_number);
		}

		else
			func_list[i].f(&head, line_number);
	}
}
