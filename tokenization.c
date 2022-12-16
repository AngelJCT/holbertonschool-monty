#include "monty.h"
/**
 *tokenization-function to tokenize arguments
 *@operation: pointer to input operation
 *@delimiter: pointer to delimiters
 *Return: arguments tokenized
 */
char **tokenization(char *operation, char *delimiter)
{
	int i = 0;
	char *token = NULL, **tokens = NULL;

	tokens = malloc(sizeof(char *) * 16);
	if (tokens == NULL)
		return (NULL);

	token = strtok(operation, delimiter);
	while (token != NULL)
	{
		tokens[i] = malloc(strlen(token) + 1 * sizeof(char));
		if (tokens[i] == NULL)
			return (NULL);
		strcpy(tokens[i], token);
		i++;
		token = NULL;
		token = strtok(NULL, delimiter);
	}
	tokens[i] = NULL;

	return (tokens);
}
