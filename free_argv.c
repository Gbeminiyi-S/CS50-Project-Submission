 #include <stdlib.h>

/**
 * free_argv - frees an array
 *
 * @argv: array
 * @lineptr: pointer to the line
 *
 */
void free_argv(char **argv, char *lineptr)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
		free(argv[i]), argv[i] = NULL;
	}
	free(argv), argv = NULL;
	free(lineptr);
}
