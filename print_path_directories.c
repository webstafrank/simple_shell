#include "shell.h"
#include <stdio.h>

/**
 * print_path_directories - Prints each directory in the PATH environment variable
 */
void print_path_directories(void)
{
	char *path = _getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}
