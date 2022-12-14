#include "monty.h"
/**
 *free_dlist-function to free doubly linked list
 *@stack: pointer to struct list
 *Return: no return value
 */
void free_dlist(stack_t **stack)
{
	stack_t *current, *next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
	}
	current = next;
}
