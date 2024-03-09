#include "shell.h"

/**
* create_child_process - check the code
* @args: arguments
*
* Return: (0) Success.
*/

extern char **environ;

void create_child_process(char **args)
{
int status;
pid_t pid;

pid = fork();
if (pid < 0)
{
perror("fork failed");
exit(1);
}
else if (pid == 0)
{
/* Child process */
execve(args[0], args, environ);
perror("execve failed");
exit(1);
}
else
{
/* Parent process */
waitpid(pid, &status, 0);
}
}
