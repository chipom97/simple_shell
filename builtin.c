#include "shell.h"

/**
* handle_builtin - check the code
* @args: arguments
*
* Return: (0) Success.
*/
void handle_builtin(char **args)
{
if (strcmp(args[0], "cd") == 0) 
{
if (args[1] != NULL) 
{
if (chdir(args[1]) != 0) 
{
perror("cd failed");
}
} 
else 
{
fprintf(stderr, "cd: missing argument\n");
}
} 
else if (strcmp(args[0], "exit") == 0) 
{
exit(0);
}
/* Other built-in cmmands here */
}
