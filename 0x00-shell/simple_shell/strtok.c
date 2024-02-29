#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

char **splitString(char *str) {

    char **words = malloc(MAX_WORDS * sizeof(char *));
    if (words == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = NULL;
    }


    int i = 0;
    while (*str != '\0' && i < MAX_WORDS - 1) {

        while (*str == ' ') {
            str++;
        }

        char *end = str;
        while (*end != ' ' && *end != '\0') {
            end++;
        }

        int wordLength = end - str;
        words[i] = malloc((wordLength + 1) * sizeof(char));
        if (words[i] == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strncpy(words[i], str, wordLength);
        words[i][wordLength] = '\0';
        i++;

        str = end;
    }

    return words;
}

int main(void) {
    char input[] = "This task was coplecated";

    char **resultOfToken = splitString(input);
    printf("I am not using strtok:\n");
    for (int i = 0; resultOfToken[i] != NULL; i++) {
        printf("%s\n", resultOfToken[i]);
        free(resultOfToken[i]);
    }
    free(resultOfToken);

    return 0;
}
