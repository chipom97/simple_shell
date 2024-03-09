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
chdir(args[1]);
}
else if (strcmp(args[0], "exit") == 0)
{
exit(0);
}
else if (strcmp(args[0], "/bin/ls") == 0)
{
handle_ls_command(args);
}
}
