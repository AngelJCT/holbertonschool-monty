#include "monty.h"
/**
 *main-function for entry point
 *@argc: argument count
 *@argv: array of arguments
 *Return: integer
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t buf = 0;
	char *operators = NULL;
	stack_t *stack_struct = NULL;
	static unsigned int line_number;
	char *new_line = "\n";

	line_number = 0;
	if (argc != 2)
		exit(EXIT_FAILURE);
	if (argv[1] == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&operators, &buf, fd) != -1)
	{
		if (strcmp(operators, new_line) == 0)
			continue;
		if (read_line(operators) == 0)
			continue;
		line_number++;
		array = tokenization(operators, " \n");
		get_op_func(array)(&stack_struct, line_number, operators, fd);
		free_dlist(array);
		free(operators);
		array = NULL;
		operators = NULL;
		buf = 0;
	}
	free_stack(stack_struct);
	free(operators);
	fclose(fd);
	exit(0);
}
