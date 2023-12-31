#include "monty.h"

/**
 * main - main function
 *
 * @argc: argumnts count
 *
 * @argv: argument vector
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error(2);
	}
	parse_line(argv[1]);
	free_nodes();
	return (0);
}

/**
 * parse_line - gets and parses a line from a file
 *
 * @filename: th given file
 *
 * Return:  0 if stack /  1 if queue
 */
int parse_line(char *filename)
{
	FILE *fd;
	char *buffer = NULL, *opcode, *value, *delim = "\n ";
	size_t len = 0;
	unsigned int line_number, format = 0;


	fd = fopen(filename, "r");
	if (filename == NULL || fd == NULL)
		print_error(3, filename);
	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		if (buffer == NULL)
			print_error(5);

		opcode = strtok(buffer, delim);
		if (opcode == NULL)
			continue;
		value = strtok(NULL, delim);

		format = call_function(opcode, value, line_number, format);
	}
	fclose(fd);
	free(buffer);
	return (format);
}
