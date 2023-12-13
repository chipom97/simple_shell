#include "shell.h"

/**
 * execute_command - Execute a command using execve
 * @command: The command to execute
 * @argv: Array of command-line arguments
 */
void execute_command(char *command, char *argv[])
{
pid_t pid = fork();

if (pid == -1)
{
perror("Error forking process");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(command, argv, NULL) == -1)
{
perror("Error executing command");
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
}

/**
 * read_command - Read a command from the user
 * @buffer: Buffer to store the command
 */
void read_command(char *buffer)
{
size_t len;
if (fgets(buffer, sizeof(buffer), stdin) == NULL)
{
if (feof(stdin))
{
printf("\nExiting shell\n");
exit(EXIT_SUCCESS);
}

perror("Error reading command");
exit(EXIT_FAILURE);
}

len = strlen(buffer);
if (len > 0 && buffer[len - 1] == '\n')
buffer[len - 1] = '\0';
}

/**
 * main - Entry point for the simple shell
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Exit status
 */
int main(int argc, char *argv[])
{
char buffer[1024];
(void)argc;

while (1)
{
printf("($) ");

read_command(buffer);

if (strcmp(buffer, "exit") == 0)
{
printf("Exiting shell\n");
break;
}

execute_command(buffer, argv);
}

return (0);
}
