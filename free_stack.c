#include "monty.h"
/**
 * free_stack - frees a doubly linked list
 * @h: pointer to head
 */
void free_stack(stack_t *h)
{
	stack_t *temp;

	while (h != NULL)
	{
		temp = h;
		h = temp->next;
		free(temp);
	}
}
