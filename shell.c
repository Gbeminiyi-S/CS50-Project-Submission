#include "shell.h"

/**
 * sigintHandler - Handles the SIGINT signal (Ctrl+C)
 * @sig: The signal number (not used in the function)
 *
 * Frees the dynamically allocated memory for 'lineptr' and
 * terminates the program.
 */
void sigintHandler(int sig)
{
	(void) sig;
	free(lineptr),
	lineptr = NULL;
	_putchar('\n');
	exit(0);
}

/**
 * mygetline - Reads a line of input from stdin
 *
 * Reads a line of input from stdin and stores it in the 'lineptr' variable
 * Dynamically allocates memory for 'lineptr' to accommodate the input line
 */
void mygetline(void)
{
	size_t n = 0;
	ssize_t nread;

	nread = getline(&lineptr, &n, stdin);
	if (nread == -1)
	{
		free(lineptr);
		lineptr = NULL;
		exit(0);
	}

	lineptr[nread - 1] = '\0';
}

/**
 * print_env - Print the current environment variables
 * @environ: Environment variables
 **/
void print_env(char **environ)
{
	int i = 0, j = 0;
	char *var = NULL;

	while (environ[i] != NULL)
	{
		var = environ[i];
		j = 0;

		while (var[j] != '\0')
		{
			_putchar(var[j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}

/**
 * perform_exit - carries out the exit command
 *
 * @argv: array
 * @av: argument vectors
 */
void perform_exit(char **argv, char **av)
{
	int EXITVALUE;

	if (argv[1] != NULL)
	{
		if (atoi(argv[1]) > 0)
		{
			EXITVALUE = atoi(argv[1]), free_argv(argv, lineptr), exit(EXITVALUE);
		}
		else
		{
			fprintf(stderr, "%s: 1: exit: Illegal number: %s\n", av[0], argv[1]);
			free_argv(argv, lineptr), exit(2);
		}
	}
	free_argv(argv, lineptr);
	exit(EXITSTATUS);
}


/**
 * main - Entry point of the program
 *
 * @ac: argument count (unused)
 * @av: argument vector
 * @environ: environment variables
 *
 * Return: 0 on successful completion
 */
int main(int ac, char **av, char **environ)
{
	char *prompt = "simple_shell$ ", *full_path = NULL, **argv = NULL;
	int i;
	struct stat statbuf;

	(void) ac, signal(SIGINT, sigintHandler);
	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			i = 0;
			while (prompt[i])
				_putchar(prompt[i++]);
		}
		mygetline(), argv = mystrtok(" ", lineptr);
		if (argv != NULL)
		{
			if (strcmp(argv[0], "exit") == 0)
				perform_exit(argv, av);
			else if (strcmp(argv[0], "env") == 0)
				print_env(environ);
			else
			{
				if (stat(argv[0], &statbuf) == 0)
					myfork(argv, av, environ, &EXITSTATUS);
				else
				{
					full_path = _which(environ, argv[0]);
					if (full_path != NULL)
					{
						free(argv[0]), argv[0] = full_path;
						myfork(argv, av, environ, &EXITSTATUS);
					}
					else
						perror(av[0]);
				}
			}
			free_argv(argv, lineptr);
		}
	}
	return (0);
}
