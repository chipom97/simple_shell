#include "shell.h"

/**
 * handle_ls_command - Executes the ls command.
 *
 * Return: (void)
 */
extern char **environ;
void handle_ls_command(void)
{
pid_t pid;
int status;

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
char *ls_args[] = {"/bin/ls", NULL};
execve(ls_args[0], ls_args, environ);
/* If execve fails, print error message */
perror("ls command execution failed");
exit(1);
}
else
{
/* Parent process */
if (waitpid(pid, &status, 0) == -1)
{
perror("waitpid failed");
exit(1);
}
}
}
