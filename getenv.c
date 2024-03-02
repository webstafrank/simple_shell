#include "shell.h"
#include <string.h>

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{

			return (environ[i] + len + 1);
		}
		i++
	}

	/* Return NULL if the variable is not found */
	return (NULL);
}
