#ifndef SHELL_H
#define SHELL_H

/* Include guard to prevent multiple inclusion */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

/* Function prototypes */

int _putchar(char c);

void printenv(void);
void env_vs_environ(void);
char *_getenv(const char *name);
void print_path_directories(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif /* SHELL_H */
