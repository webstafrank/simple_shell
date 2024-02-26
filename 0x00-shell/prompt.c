#include "main.h"

int main(void)
{
	size_t j =0;
	char *text = NULL;

	text = malloc(sizeof(char) * 10);
	printf("$ ");
	getline(&text, &j, stdin);
	printf("size of text buffer : %ld\n", j);

	free(text);
	return (0);
}

