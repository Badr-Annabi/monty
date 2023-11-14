#include "monty.h"

/**
 * print_error - prints an error depending on the choice
 *
 * @choice: the choice of message error
 */
void print_error(int choice, ...)
{
	va_list args;

	va_start(args, choice);
	switch (choice)
	{
		case 1:
			fprintf(stderr, "L%d: usage: push integer", va_arg(args, int));
			break;
        case 2:
            fprintf(stderr, "USAGE: monty file");
            break;
        case 3:
            fprintf(stderr, "Error: Can't open file %s", va_arg(args, char*));
            break;
        case 4:
            fprintf(stderr,"L%d: unknown instruction %s", va_arg(args, char*));
            break;
        case 5:
            fprintf(stderr, "Error: malloc failed");
            break;
	}
	va_end(args);

}
