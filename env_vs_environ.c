#include "shell.h"
/**
 * main - Entry point to test addresses of env and environ
 *
 * @ac: Number of command line arguments
 * @av: Array of command line arguments
 * @env: Array of environment variables
 *
 * Description: This program tests and prints the addresses of the env and
 * environ variables to check if they are the same or different.
 *
 * Return: Always 0 on success
 */
int main(int ac, char **av, char **env)
	{

	(void)ac; /* Unused parameter */
	(void)av;/* Unused parameter */

	/* Print addresses of env and environ variables */
	printf("Address of env: %p\n", (void *)env);
	printf("Address of environ: %p\n", (void *)environ);

	return (0);
}
