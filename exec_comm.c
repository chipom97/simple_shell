#include "shell.h"

/**
* execute_command - Function to execute external commands
* @args: arguments
* 
* Return: (0) Success.
*/

void execute_command(char **args) 
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
if (execve(args[0], args, environ) == -1) 
{
/* If execvp fails, print error message */
perror("execvp failed");
exit(1);
}
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
