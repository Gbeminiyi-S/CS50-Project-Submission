#include <string.h>
#include <stdlib.h>

/**
 * mystrtok - tokenizes a line
 * @delim: delimiter to use
 * @line: line to tokenize
 *
 * Return: array of token, else NULL
 */
char **mystrtok(const char *delim, char *line)
{
	char *token = NULL;
	char **tokens = malloc(sizeof(char *) * 1024);
	int i = 0;

	if (!tokens)
		return (NULL);

	token = strtok(line, delim);
	if (token == NULL)
	{
		free(tokens), token = NULL;
		free(line), line = NULL;
		return (NULL);
	}

	while (token)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}

	tokens[i] = NULL;
	return (tokens);
}
