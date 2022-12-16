#include "monty.h"
/**
 *free_dlist-function to free doubly linked list
 *@grid: pointer to array
 *Return: no return value
 */
void free_dlist(char **grid)
{
	int i = 0;

	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
