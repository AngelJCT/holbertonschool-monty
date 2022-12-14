#include "monty.h"
/**
 *push_opcode-function to push into the stack
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *newNode;
	(void)line_number;

	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	newNode->n = n;
	*stack = newNode;
	newNode->prev = NULL;
}
/**
 *pall_opcode-function to print all operator
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp = *stack;
	while (stack != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 *pint_opcode-function to print the head node
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 */
void pint_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	(void)line_number;

	if (pointer == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", pointer->n);
}
