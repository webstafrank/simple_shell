#include "main.h"
/**
 * main -  
 */
int main(int ac, char **av)
{
	int v;
	int sum = 0;

	for (v = 0; v < ac; v++)
	{
		printf("argv[%d] = %s\n", v, av[v]);
		sum += atoi(av[v]);
	}
	return (0);
}
