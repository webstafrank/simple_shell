#include "shell.h"
#include <stdlib.h>
#include <string.h>
/**
 * _unsetenv - Removes a variable from the environment
 * @name: The name of the variable to remove
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	/* Check for invalid parameter */
	if (name == NULL || strchr(name, '=') != NULL)
	{
		return (-1);
	}
	int i = 0;
	int found = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			free(environ[i]);
			found = 1;

			break;
		}
		i++
	}
	if (found)
	{
		while (environ[i + 1] != NULL)
		{
			environ[i] = environ[i + 1];
			i++
		}

		char **new_environ = realloc(environ, i * sizeof(char *));
		if (new_environ == NULL)
		{
			return (-1); /* Memory allocation error */
		}

		environ = new_environ;
	}

	return (found ? (0) (:) (-1)); /* Variable not found or removed successfully */
}
