#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * execute_ls - Executes the 'ls' command to list files and directories.
 *
 * This function uses the 'ls' command to display information about files and
 * directories in the current working directory. It utilizes the system() funct
 * to execute the command.
 *
 * Return: Returns 0 successful execution of 'ls' command, otherwise returns
 * an error code.
 */
int execute_ls(void)
{
	/* Implementation of 'ls' command execution using system() function */
	int result = system("ls");

	/* Check the result of the 'ls' command execution */
	if (result == -1)
	{
		/* Handle error if system() call fails */
		perror("Failed to execute 'ls'");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
/**
 * main - Entry point of the program.
 *
 * This function serves as the starting point for the program execution.
 * It calls the execute_ls function to display the contents of the current dir.
 *
 * Return: 0 on success.
 */
int main(void)
{
    /* Call execute_ls function to display directory contents */
	execute_ls();

	return (0);
}

