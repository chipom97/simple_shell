#include "shell.h"
/**
 * _PATHstrcmp - compares PATH with environ to find PATH value
 * @s1: pointer PATH string
 * @s2: pointer to environ string with actual value
 *
 * Return: 0 on success
 */
int _PATHstrcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s2[i] != '='; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}
