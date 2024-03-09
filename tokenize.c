#include "shell.h"
#define MAX_ARGS 10

/**
* tokenize_input - check the code
* @line: line
* @args: arguments
* Return: (0) Success.
*/
void tokenize_input(char *line, char **args)
{
int i;

i = 0;
args[i] = strtok(line, " \n");
while (args[i] != NULL)
{
i++;
args[i] = strtok(NULL, " \n");
}
args[i] = NULL;
}
