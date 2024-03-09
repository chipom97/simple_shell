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

initialize_shell();

/* Allocate memory for line */
line = malloc(MAX_LINE_LENGTH * sizeof(char));
if (line == NULL) {
perror("Failed to allocate memory for line");
exit(1);
}


/* Main shell loop */
while (1)
{
printf("HI:) ");
fgets(line, MAX_LINE_LENGTH, stdin);
tokenize_input(line, args);
if (args[0] != NULL)
{
handle_builtin(args);
create_child_process(args);
}
}

/* Free dynamically allocated memory */
free(line);
return (0);
}
