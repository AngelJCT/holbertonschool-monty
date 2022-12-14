#include "monty.h"
/**
 *pop_opcode-function to remove top element from stack
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *Return: no return for this function
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *pop;

	head = *stack;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (head->next == NULL)
	{
		pop = head;
		head = NULL;
		free(pop);
	}
	else
	{
		pop = head;
		head = NULL;
		free(pop);
	}
	*stack = head;
}
/**
 *swap_opcode-function to swap the top elements of the stack
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *Return: no return for this function
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *swap_nodes;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	swap_nodes = (*stack)->next;
	(*stack)->prev = swap_nodes;
	(*stack)->next = swap_nodes->next;
	swap_nodes->prev = NULL;
	swap_nodes->next = *stack;
	*stack = swap_nodes;
}
/**
 *add_opcode-function to sum the two top elements of the stack
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *Return: no return value
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 *nop_opcode-function to do nothing
 *@stack: pointer to struct
 *@line_number: number of line of opcode
 *Return: no return for thid function
 */
void nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
