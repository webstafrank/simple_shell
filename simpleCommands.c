#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 10

/**
 *
 * display_prompt: Function to display the shell prompt
 * 
 * execute_command -Function to execute a command in a child process
 * and Parent process
 *
 * parse_input: Function to parse user input into command and arguments
 *
 *Main: Is the main function for the shell execution
 *
 *
 * Description: the code executes simple command o the shell e.g '$', 'pid and ppid'
 *Attempt to execute the command only if it exists in the PATH
 *Return output SUCCESS, Error havin been unsuccessfulll
 **/
void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

void execute_command(char *command, char *args[]) {
	pid_t child_pid, wait_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0) {

	if (execvp(command, args) == -1) {
	perror("Error executing command");
		exit(EXIT_FAILURE);
	}
	} else if (child_pid < 0) {
	perror("Fork error");
	} else {
		do {
		wait_pid = waitpid(child_pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	
	}(void)wait_pid;
}


int parse_input(char *input, char *args[]) {
	int arg_count = 0;
	char *token = strtok(input, " \t\n");

	while (token != NULL && arg_count < MAX_ARGS - 1) {
	args[arg_count] = token;
	arg_count++;
	token = strtok(NULL, " \t\n");
	}

	args[arg_count] = NULL;

	return (arg_count);
}

int main(void) {
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARGS];

	while (1)
	{
		display_prompt();

	if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
	{

	printf("\nExiting shell...\n");
	break;
	}

	input[strcspn(input, "\n")] = '\0';

	if (strlen(input) == 0) 
	{

	continue;
	}

	int arg_count = parse_input(input, args);
		if (arg_count > 0)
		{

		if (access(args[0], X_OK) == 0)
		{
		execute_command(args[0], args);
		}
		else
		{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		}
	}
	}

	return (0);
}
