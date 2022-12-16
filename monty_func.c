#include "monty.h"
char **array = NULL;
/**
 *push_opcode-function to push into the stack
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *@operators: pointer to line
 *@fd: file opened
 */
void push_opcode(stack_t **stack, unsigned int line_number, char *operators, FILE *fd)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (array[1] == NULL || read_arguments(array[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(operators);
		free_dlist(array);
		free(newNode);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	newNode->n = atoi(array[1]);
	newNode->next = *stack;
	newNode->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}
/**
 *pall_opcode-function to print all operator
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *@operators: pointer to line
 *@fd: file opened
 */
void pall_opcode(stack_t **stack, unsigned int line_number, char *operators, FILE *fd)
{
	stack_t *h = *stack;
	(void)operators;
	(void)fd;
	(void)line_number;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 *pint_opcode-function to print the head node
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *@operators: pointer to line
 *@fd: file opened
 */
void pint_opcode(stack_t **stack, unsigned int line_number, char *operators, FILE *fd)
{
	stack_t *h = *stack;

		if (h != NULL)
			printf("%d\n", h->n);

		else if (h == NULL)
		{
			fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
			free(operators);
			free_dlist(array);
			free_stack(*stack);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
}
