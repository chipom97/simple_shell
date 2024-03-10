#include "shell.h"
#define MAX_LINE_LENGTH 80
#define MAX_ARGS 10

/**
* main - check the code
*
* Return: (0) Success.
*/

/* Declaration of the environ variable */
extern char **environ;

int main(void)
{
/* Declare variables at the beginning */
char *line;
char *args[MAX_ARGS];
size_t len = 0;

initialize_shell();

/* Allocate memory for line */
line = malloc(MAX_LINE_LENGTH * sizeof(char));
if (line == NULL)
{
perror("Failed to allocate memory for line");
exit(1);
}

/* Main shell loop */
while (1) 
{
printf("HI:) ");
fflush(stdout);

/* Read input line */
if (getline(&line, &len, stdin) == -1) 
{
perror("getline failed");
exit(1);
}

/* Tokenize input and execute command */
tokenize_input(line, args);
if (args[0] != NULL) 
{
handle_builtin(args);
execute_command(args);
}
}

/* Free dynamically allocated memory */
free(line);
return (0);
}
