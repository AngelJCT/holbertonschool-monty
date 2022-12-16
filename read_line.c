#include "monty.h"
/**
 * read_line - checks if line is empty
 * @operators: pointer to line
 * Return: 0 if line is empty, 1 if line is not empty
 */
int read_line(char *operators)
{
	int i = 0;

	while (operators[i] != '\0')
	{
		if (operators[i] >= 97 && operators[i] <= 122)
		{
			return (1);
		}
		if (operators[i] >= 65 && operators[i] <= 90)
		{
			return (1);
		}
		i++;
	}

	return (0);
}
