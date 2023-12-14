	#include <string.h>
	#include <stdlib.h>
	#include <sys/stat.h>

	char **mystrtok(const char *delim, char *line);
	/**
	 * _which - Find the full path of a command in the PATH environment variable.
	 * @env: An array of environment variables.
	 * @command: The command to search for.
	 *
	 * Return: The full path of the command if found, or NULL if not found.
	 */
	char *_which(char **env, char *command)
	{
		unsigned int i = 0;
		char **paths = NULL, *buffer = NULL;
		char *paths_copy;
		size_t length = 0;
		struct stat statbuf;

		while (env[i++] != NULL)
		{
			if (strncmp(env[i], "PATH", 4) == 0)
				break;
		}
		paths_copy = strdup(env[i]);
		paths = mystrtok(":=", paths_copy);
		free(paths_copy);

		if (paths)
		{
			for (i = 0; paths[i]; i++)
			{
				length = strlen(paths[i]) + strlen(command) + 2;
				buffer = malloc(length);
				if (buffer)
				{
					strcpy(buffer, paths[i]);
					strcat(buffer, "/");
					strcat(buffer, command);
					if (stat(buffer, &statbuf) == 0)
					{
						while (paths[i])
							free(paths[i++]);
						free(paths);
						return (buffer);
					}
					free(buffer), free(paths[i]);
				}
			}
			free(paths);
		}
		return (NULL);
	}
