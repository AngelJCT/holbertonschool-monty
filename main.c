#include "monty.h"
/**
 *main-function for entry point
 *@argc: argument count
 *@argv: array of arguments
 *Return: Always 0 success
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t buf;
	int fileread, num = 0, line_number = 0;
	unsigned int i = 0;
	char *operation = NULL;
	stack_t **stack_struct;
	void (*op_get)(stack_t **, unsigned int);

	if (argc != 2)
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
	num = atoi(array[1]);
	while ((fileread = getline(&operation, &buf, fd)) != -1)
	{
		line_number++;
		array = tokenization(operation, " \n");
		op_get = get_op_func(array[0]);
		op_get(stack_struct, i);
	}
	free_dlist(stack_struct);
	fclose(fd);
	return (0);
}
