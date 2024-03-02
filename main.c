#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
	{
	char *path = "/bin/ls";  // Replace this with the path to your executable for testing

	/* Test the printenv function */
	printf("Test 1: printenv\n");
	printenv();
	printf("\n");

	/* Test the env_vs_environ function */
	printf("Test 2: env_vs_environ\n");
	env_vs_environ();
	printf("\n");

	/* Test the _getenv function */
	printf("Test 3: _getenv\n");
	char *var_value = _getenv("SHELL");
	if (var_value != NULL)
	printf("Value of SHELL: %s\n", var_value);
	else

        printf("Variable not found\n");
	printf("\n");

	/* Test the print_path_directories function */
	printf("Test 4: print_path_directories\n");
	print_path_directories();
	printf("\n");

	/* Test the _setenv function */
	printf("Test 5: _setenv\n");
	_setenv("MY_VARIABLE", "my_value", 1); /* Change as needed */
	printenv();  /* Print environment to see if the variable was set */
	printf("\n");

	/* Test the _unsetenv function */
	printf("Test 6: _unsetenv\n");
	_unsetenv("MY_VARIABLE");
	printenv();  // Print environment to see if the variable was unset
	printf("\n");

	/* Test the execution of a command */
	printf("Test 7: Command Execution\n");
	if (access(path, X_OK) == 0)

	{
	char *argv[] = {path, NULL};
	if (fork() == 0)
	{
	execve(path, argv, NULL);
	}
	else
        {
	wait(NULL);
	}

	}
	else
	{
perror("Error accessing executable");
	}

return 0;
}

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char *input;
	size_t len = 0;
	ssize_t read;

	do {
	/* Display shell prompt */
	write(STDOUT_FILENO, "($) ", 4);

	/* Read user input */
	read = getline(&input, &len, stdin);

	if (read == -1)
	{
	perror("Error reading input");
	break;
	}
	/* Check if the input is not EOF (Ctrl+D) */
	if (read > 1)
	{
	/* Remove trailing newline character */
	input[read - 1] = '\0';

	/* Execute the command */
	execute_command(input);
	}
	} while (read != -1);

	/* Free allocated memory */
	free(input);

	return (0);
}
