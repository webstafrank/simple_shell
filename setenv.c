#include "shell.h"
/**
 * main - Entry point to test _setenv function
 *
 * Description: This program tests the _setenv function by attempting to set
 * an environment variable named "MY_VARIABLE" with the value "my_value".
 *
 * Return: Always 0 on success
 */

int main(void)
{
	char *name = "MY_VARIABLE";
	char *value = "my_value";

	/* Attempt to set the environment variable */
	if (_setenv(name, value, 1) == 0)

	printf("Variable set successfully\n");
	else
	printf("Error setting variable\n");

	return (0);
}
