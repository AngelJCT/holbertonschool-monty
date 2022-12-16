#include "monty.h"
/**
 *get_op_func-function to select correct operator
 *@array: tokens on the command line
 *Return: no return value
 */
void (*get_op_func(char **array))(stack_t **, unsigned int, char *, FILE *)
{
	instruction_t op[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{NULL, unknown_func}
	};

	int index = 0;

	while (index < 8)
	{
		if (strcmp(array[0], op[index].opcode) == 0)
		{
			return (op[index].f);
		}
		index++;
		if (index == 7)
			return (op[index].f);
	}
	return (NULL);
}
