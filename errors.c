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

	}
	va_end(args);

}
