#include "shell.h"
/**
 * _splitPATH - counts the number of PATH members
 * @str: pointer to string to count
 *
 * Return: number of PATH members
 */
int _splitPATH(char *str)
{
	int i, searchflag = 1, wordcount = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ':' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		if (str[i + 1] == ':')
		{
			searchflag = 1;
		}
	}
	return (wordcount);
}
