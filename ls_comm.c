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
/*char *ls_args[] = {"/bin/ls", NULL};*/
execve(args[0], args, environ);
/* If execve fails, print error message */
perror("execve failed");
exit(1);
}
else
{
/* Parent process */
waitpid(pid, &status, 0);
}
}
