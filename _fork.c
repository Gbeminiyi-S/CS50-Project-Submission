#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * myfork - Function to create a child process and execute a specified program.
 *
 * @argv: Array of strings containing the arguments to be passed to the
 * program.
 * @av: Array of strings containing the program name and arguments.
 * @environ: Environment variables
 * @EXITSTATUS: pointer to the exit status
 **/
void myfork(char **argv, char **av, char **environ, int *EXITSTATUS)
{
	pid_t child_pid;
	int status, exit_status;

	child_pid = fork();
	if (child_pid == -1)
		return;
	else if (child_pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
			perror(av[0]);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
			{
				*EXITSTATUS = 2;
			}
		}
	}
}
