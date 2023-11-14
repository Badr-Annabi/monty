#include "monty.h"

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
	}
	va_end(args);

}
