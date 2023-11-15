#include "monty.h"

/**
 * tt - tt
 */
void tt(void);
void tt(void)
{}
/**
 * print_error - prints an error depending on the choice
 *
 * @choice: the choice of message error
 */
void print_error(int choice, ...)
{
	va_list args;
	char *op;
	int ln;

	va_start(args, choice);
	switch (choice)
	{
		case 1:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		case 2:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 3:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char*));
			break;
		case 4:
			ln = va_arg(args, int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, op);
			break;
		case 5:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't swap, stack too short\n", va_arg(args, int));
			break;
		case 9:
			fprintf(stderr, "L%d: can't add, stack too short\n", va_arg(args, int));
			break;
		case 10:
			fprintf(stderr, "L%d: can't sub, stack too short\n", va_arg(args, int));
			break;
		case 11:
			fprintf(stderr, "L%d: can't div, stack too short\n", va_arg(args, int));
			break;
		case 12:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
			break;
		case 13:
			fprintf(stderr, "L%d: can't mul, stack too short\n", va_arg(args, int));
			break;
		case 14:
			fprintf(stderr, "L%d: can't mod, stack too short\n", va_arg(args, int));
			break;
		case 15:
			fprintf(stderr, "L%d: can't pchar , value out of range\n", va_arg(args, int));
			break;
		case 16:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", va_arg(args, int));
			break;
	}
	va_end(args);
	free_nodes();
	exit(EXIT_FAILURE);

}
