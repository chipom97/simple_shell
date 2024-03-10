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
/* Wait for child process to complete */
if (waitpid(pid, &status, 0) == -1)
{
/* Error handling for waitpid failure */
perror("waitpid failed");
exit(1);
}
}
}
