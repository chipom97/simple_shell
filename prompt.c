#include "shell.h"
/**
 * prompt - writes a prompt
 *
 * Return: 0 on sucess
 */
int prompt(void)
{
	char *prompt = "$ ";
	ssize_t writecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, prompt, 2);
		if (writecount == -1)
			exit(0);
	}
	return (0);
}
