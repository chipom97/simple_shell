#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * read_command - Reads a command from the user.
 *
 * Return: The entered command.
 */

char *read_command(void)
{
char *command = NULL;
size_t bufsize = 0;
if (getline(&command, &bufsize, stdin) == -1)
{
perror("getline");
exit(EXIT_FAILURE);
}
command[strcspn(command, "\n")] = '\0';
return (command);
}
