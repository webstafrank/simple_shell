#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

/**
 * splitStringNoStrtok - Splits a string into words without using strtok
 * @str: The input string to be split
 *
 * Return: An array of strings representing the words
 */
char **splitStringNoStrtok(char *str)
{
	char **words = malloc(MAX_WORDS * sizeof(char *));

	if (words == NULL)
	{
		perror("malloc");

		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < MAX_WORDS; i++)
		words[i] = NULL;

	int i = 0;

	while (*str != '\0' && i < MAX_WORDS - 1)
	{
		while (*str == ' ')
			str++;

		char *end = str;

		while (*end != ' ' && *end != '\0')
			end++;

		int wordLength = end - str;

		words[i] = malloc((wordLength + 1) * sizeof(char));

		if (words[i] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		strncpy(words[i], str, wordLength);
		words[i][wordLength] = '\0';
		i++;
	str = end;
	}
	return (words);
}
/**
 * main - Entry point of the program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char input[] = "Hello Peer does it split?";
	char **resultNoStrtok = splitStringNoStrtok(input);

	printf("Without strtok:\n");

	for (int i = 0; resultNoStrtok[i] != NULL; i++)
	{
		printf("%s\n", resultNoStrtok[i]);
		free(resultNoStrtok[i]);
	}

	free(resultNoStrtok);

	return (0);
}

