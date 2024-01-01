#include "shell.h"
/**
 * _env - prints the environ
 *
 * Return: 0 on success
 */
int _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}
