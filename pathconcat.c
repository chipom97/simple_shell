#include "shell.h"
/**
 * _concat - concats user string with PATH member string and token
 * @tmp: static array to store concatenated string
 * @av: pointer to array of user strings
 * @tok: pointer to PATH token
 *
 * Return: 0 on success
 */
char *_concat(char *tmp, char **av, char *tok)
{
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(tok) + _strlen(av[0]) + 2;
	_strcat(tmp, tok);
	_strcat(tmp, "/");
	_strcat(tmp, av[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}
