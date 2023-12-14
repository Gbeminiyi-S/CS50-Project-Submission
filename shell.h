#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>

char *lineptr = NULL;
int EXITSTATUS = 0;
int _putchar(char c);
void myfork(char **argv, char **av, char **environ, int *EXITSTATUS);
void print_env(char **environ);
void free_argv(char **argv, char *lineptr);
char *_which(char **env, char *command);
char **mystrtok(const char *delim, char *line);

#endif
