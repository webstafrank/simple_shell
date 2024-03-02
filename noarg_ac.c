#include "main.h"
/**
 * main -  printds av without ac
 *
 * return: 0
 */
int main(int ac, char **av)
{
	int p;
	
	while (*av != NULL)
	{
		printf("argv = %s\n", *av);
		av++;
	}
	return (0);
}
