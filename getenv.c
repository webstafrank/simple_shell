#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * _getenv - Custom implementation of getenv function
 * @name: The name of the environment variable to retrieve
 *
 * Return: The value of the environment variable or NULL if not found
 */
extern char **environ;

char *_getenv(const char *name)
{
	/* Iterate through environment variables */
	for (char **env = environ; *env != NULL; env++)
	{
		char *current_var = *env;

	/* Checks if the current environment variable matches the desired name */
	if (strstr(current_var, name) == current_var && current_var[strlen(name)] == '=')
	{
		/* Return the value of the environment variable */
		return current_var + strlen(name) + 1;
	}
	}

		/* If variable is not found, return NULL */
		return NULL;
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	const char *variable_name = "PATH";
	char *value = _getenv(variable_name);

	if (value != NULL)
	{
		printf("%s=%s\n", variable_name, value);
	}
	else
	{
		printf("Environment variable '%s' not found.\n", variable_name);
	}

	return 0;
}
