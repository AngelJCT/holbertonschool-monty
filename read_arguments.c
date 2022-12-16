#include "monty.h"
/**
 * read_arguments - checks if argument is string of numbers without any letters
 * @argument: string
 * Return: 1 if contains no characters and is only numbers, 0 if otherwise
 */
int read_arguments(char *argument)
{
	int i = 0, j = 0;

	while (argument[i] != '\0')
	{
		if (argument[i] >= 48 && argument[i] <= 57 && argument[i] != '-')
		{
			j = i + 1;
			while (argument[j] != '\0')
			{
				if (argument[j] < 48 || argument[j] > 57)
				{
					return (0);
				}
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}
