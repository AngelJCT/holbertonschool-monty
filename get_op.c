#include "monty.h"
/**
 *get_op_func-function to select correct operator
 *@operator: pointer to operator
 *Return: no return value
 */
void (*get_op_func(char *operator))(stack_t **stack, unsigned int line_number)
{
	static instruction_t op[] = {
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
		if (strcmp(operator, op[index].opcode) == 0)
		{
			return (op[index].f);
		}
		index++;
	}
	return (NULL);
}
