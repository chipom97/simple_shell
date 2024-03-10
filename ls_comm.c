#include "shell.h"

/**
 * handle_ls_command - Executes the ls command.
 *
 * Return: (void)
 */
extern char **environ;
void handle_ls_command(char **args)
{
pid_t pid;
int status;
/*(void)args;*/
/* Create child process */
pid = fork();
if (pid < 0)
{
/* Error handling for fork failure */
perror("fork failed");
exit(1);
}
else if (pid == 0)
{
/* Child process */
execve("/bin/ls", args, environ);
/* If execve fails, print error message */
perror("execve failed");
exit(1);
}
else
{
/* Parent process */
if (waitpid(pid, &status, 0) == -1)
{
/* Error handling for waitpid failure */
perror("waitpid failed");
exit(1);
}
}
}
