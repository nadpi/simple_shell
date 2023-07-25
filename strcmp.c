#include "shell.h"
/**
 * _strcmp - compares two strings.
 *@s1: first string.
 *@s2: second string.
 * Return: the ASCII difference between the letters where the
 * difference between the 2 strings first occured.
*/
int _strcmp(char *s1, char *s2)
{

	while (*s1 != '\0')
	{
		if (*s1 != *s2)
		{
			break;
		}
		s1++;
		s2++;
	}

return (*s1 - *s2);
}
