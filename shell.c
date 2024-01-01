#include "shell.h"

/**
 * main - Entry point of the program
 * gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
 * Return: Always 0 (Success)
 */

int main(void)
{
char *command;
while (1)
{
display_prompt();
command = read_command();

if (strncasecmp(command, "exit", 4) == 0)
{
printf("Exiting the shell. Goodbye!\n");
free(command);
break;
}

if (feof(stdin))
{
puts("Received end-of-file. Exiting the shell. Goodbye!");
free(command);
break;
}

if (access(command, X_OK) == -1)
{
fprintf(stderr, "Error: Command '%s' not found.\n", command);
}

else
{
printf("You entered: %s\n", command);
}
free(command);
}

return (0);
}
