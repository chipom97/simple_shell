#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024


/**
 * execute_command - Execute the given command with the provided arguments
 * @command: The command to execute
 * @args: The arguments for the command
 *
 * This function forks a new process and executes the given command
 * It waits for the child process to complete before returning.
 */
void execute_command(char *command, char *args[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{

/* Child process */
		if (execvp(command, args) < 0)
		{
			perror("Exec failed");
			exit(EXIT_FAILURE);
		}
	} else
	{

/* Parent process */
		waitpid(pid, &status, 0);
	}
}

/**
 * main - Entry point of the program
 *
 * Return: Always returns (0).
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_INPUT_SIZE];
	char *token;

	while (1)
	{

/* Display prompt and get user input */
		printf("$ ");
		fgets(input, sizeof(input), stdin);

/* Remove newline character from input */
		input[strcspn(input, "\n")] = '\0';

		/* Exit if the user input is 'exit' */
		if (strcmp(input, "exit") == 0)
		{
			break;
		}


		/* Tokenize the input into command and arguments */

		token = strtok(input, " ");
		int i;

		i = 0;
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;


/* Execute the command */
		execute_command(args[0], args);
	}
	return (0);
}
