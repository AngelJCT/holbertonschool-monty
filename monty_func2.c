#include "monty.h"
/**
 *pop_opcode-function to remove top element from stack
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *@operators: pointer to line
 *@fd: file opened
 *Return: no return for this function
 */
void pop_opcode(stack_t **stack, unsigned int line_number, char *operators, FILE *fd)
{
	stack_t *h = *stack;

	if (h != NULL)
	{
		*stack = (*stack)->next;
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
		free(h);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(operators);
		free_dlist(array);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
}
/**
 *swap_opcode-function to swap the top elements of the stack
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *@operators: pointer to line
 *@fd: file opened
 *Return: no return for this function
 */
void swap_opcode(stack_t **stack, unsigned int line_number, char *operators, FILE *fd)
{
	stack_t *h = *stack, *body;
	int hv, bv;

	if (h != NULL)
	{
		body = (*stack)->next;
	}

	if (h != NULL && body != NULL)
	{
		hv = h->n;
		bv = body->n;
		h->n = bv;
		body->n = hv;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(operators);
		free_dlist(array);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
}
/**
 *add_opcode-function to sum the two top elements of the stack
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *@operators: pointer to line
 *@fd: file opened
 *Return: no return value
 */
void add_opcode(stack_t **stack, unsigned int line_number, char *operators, FILE *fd)
{
	stack_t *head = *stack;
	stack_t *body;

	if (head != NULL)
	{
		body = (*stack)->next;
	}

	if (head != NULL && body != NULL)
	{
		body->n = body->n + head->n;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(head);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(operators);
		free_dlist(array);
		free_stack(*stack);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
}
/**
 *nop_opcode-function to do nothing(literal, nothing)
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *@operators: pointer to line
 *@fd: file opened
 *Return: no return for thid function
 */
void nop_opcode(stack_t **stack, unsigned int line_number, char *operators, FILE *fd)
{
	(void)stack;
	(void)line_number;
	(void)operators;
	(void)fd;
}
