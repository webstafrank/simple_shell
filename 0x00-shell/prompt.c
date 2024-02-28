#include "main.h"
/**
 * main - prints prompt
 *
 * return - always zero
 */
int main(void)
{
	size_t j = 0;
	char *text = NULL;

	printf("$ ");
	getline(&text, &j, stdin);
	printf("%s", text);
	
	free(text);
	return (0);
}
