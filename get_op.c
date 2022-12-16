#include "monty.h"
/**
 *get_op_func-function to select correct operator
 *@array: tokens on the command line
 *Return: no return value
 */
void (*get_op_func(char **array))(stack_t **, unsigned int, char *, FILE *)
{
	instruction_t op[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", pop_opcode},
		{"add", pop_opcode},
		{"nop", pop_opcode},
		{NULL, NULL}
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
