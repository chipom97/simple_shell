#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 80
#define MAX_ARGS 10

/**
 * main - Entry point of the program
 *
 * Return: Always returns (0).
 */
int main(void)
{
	char line[MAX_LINE_LENGTH];
	char *args[MAX_ARGS];
	int status;
	int i;
	pid_t pid;

	while (1)
	{
		printf("Yo!: ");
		fgets(line, MAX_LINE_LENGTH, stdin);
		i = 0;
		args[i] = strtok(line, " \n");
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, " \n");
		}
		args[i] = NULL;
		if (strcmp(args[0], "cd") == 0)
		{
			chdir(args[1]);
			continue;
		}
		else if (strcmp(args[0], "exit") == 0)
		{
			exit(0);
		}
		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			exit(1);
		}
		else if (pid == 0)
		{
			execvp(args[0], args);
			perror("execvp failed");
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
