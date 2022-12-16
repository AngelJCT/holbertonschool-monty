#include "monty.h"
/**
 * unknown_func - throws an error if function is not found
 * @stack: stack
 * @line_number: number of line
 * @operators: pointer to line
 * @fd: opened file
 */
void unknown_func(stack_t **stack, unsigned int line_number, char *operators, FILE *fd)
{
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, array[0]);
	free(operators);
	free_dlist(array);
	free_stack(*stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}

