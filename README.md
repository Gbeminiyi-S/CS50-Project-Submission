# Simple Shell Project

#### Video Demo: https://youtu.be/lGtsZsGHHr4

#### Description:

## Introduction
This project implements a simple shell program that allows users to interact with the system by entering commands. The shell supports basic functionalities such as executing commands, handling signals (Ctrl+C), displaying environment variables, and exiting the shell.

## Table of Contents
1. [Code Overview](#code-overview)
2. [Signal Handling](#signal-handling)
3. [Input Reading](#input-reading)
4. [Command Execution](#command-execution)
5. [Built-in Commands](#built-in-commands)
6. [Usage](#usage)

## Code Overview
The main program (`main`) sets up the shell environment, continuously reads user input, and processes the entered commands. The code includes functions for handling signals, reading input, executing commands, and implementing built-in functionalities.

## Signal Handling
The `sigintHandler` function handles the SIGINT signal (Ctrl+C). It frees dynamically allocated memory for the input line and terminates the program gracefully.

## Input Reading
The `mygetline` function reads a line of input from stdin, dynamically allocates memory for the input line, and stores it in the `lineptr` variable.

## Command Execution
The main loop in the `main` function reads user input, tokenizes it into command and arguments, and executes the corresponding command. If the entered command is not found in the system's PATH, it attempts to locate the command and execute it.

## Built-in Commands
The shell supports the following built-in commands:
- `exit`: Exits the shell with an optional exit status.
- `env`: Displays the current environment variables.

## Usage
To use the shell, compile the code and run the executable. The shell will display a prompt (`simple_shell$ `), and you can enter commands interactively.

```bash
gcc -o simple_shell shell.h *.c
./simple_shell
```

## File Descriptions

### 1. _fork.c
This file (`_fork.c`) contains the implementation of the `myfork` function, which is responsible for creating a child process and executing a specified program. It utilizes the `fork` system call to spawn a new process and `execve` to replace the child process's image with the specified program.

### 2. _putchar.c
The file (`_putchar.c`) includes the `_putchar` function, which writes a character to the standard output (`stdout`). This function is commonly used for printing characters and is utilized throughout the project for output operations.

### 3. _strtok.c
This file (`_strtok.c`) implements the `mystrtok` function, a custom version of the `strtok` function. It tokenizes a given line based on a specified delimiter and returns an array of tokens. Memory is dynamically allocated for the tokens.

### 4. _which.c
The file (`_which.c`) contains the `_which` function, responsible for finding the full path of a command in the `PATH` environment variable. It searches through the directories specified in the `PATH` variable to locate the command. If found, it returns the full path; otherwise, it returns `NULL`.

### 5. free_argv.c
The file (`free_argv.c`) provides the `free_argv` function, which is designed to free memory allocated for an array of strings. This function is used to release memory associated with the array of tokens created during tokenization.

### 6. shell.c
The main implementation file (`shell.c`) contains the entry point (`main` function) of the simple shell program. It includes functions for handling signals (`sigintHandler`), reading input (`mygetline`), executing built-in commands (`print_env`, `perform_exit`), and processing user commands in the main loop.

### 7. shell.h
The header file (`shell.h`) includes function declarations, global variables, and necessary includes for the project. It serves as an interface for other source files to access common elements and functionalities. The header guards (`#ifndef SHELL_H` and `#define SHELL_H`) prevent multiple inclusion of the same header.
