#include "monty.h"

void t(void);
/**
 * t - t
 *
 */
void t(void)
{
}
/**
 * call_function - calls a specific function.
 * @op: opcode.
 * @value: numeric value.
 * @line_number: line number for the instruction.
 * @format: format equal 0 if we are in a stack, and 1 if we entered a queue.
 * Return: 0 if stack or 1 if queue
 */
int call_function(char *op, char *value, int line_number, int format)
{
	int i, j, flag = 1, found = 0;
	stack_t *node;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_all},
		{"pint", _pint},
		{"swap", _swap},
		{"pop", _pop},
		{"nop", nop},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL}
	};
	if (op[0] == '#')
		return (format);
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(op, func_list[i].opcode) == 0)
		{
			found = 1;
			if (strcmp(op, "push") == 0)
			{
				if (value != NULL && value[0] == '-')
				{
					value = value + 1;
					flag = -1;
				}
				if (value == NULL)
					print_error(1, line_number);
				for (j = 0; value[j] != '\0'; j++)
				{
					if (isdigit(value[j]) == 0)
						print_error(1, line_number);
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
		else if (strcmp(op, "stack") == 0)
		{
			found = 1;
			format = 0;
			return (format);
		}
		else if (strcmp(op, "queue") == 0)
		{
			found = 1;
			format = 1;
			return (format);
		}
	}
	if (!found)
		print_error(4, line_number, op);
	return (format);
}
