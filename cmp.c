#include "shell.h"
/**
 * cmp - compares two strings
 * @s1: string1
 * @s2: string2
 * Return: -1 , 0 , 1 (less than, equal, bigger than)
 */
int cmp(char *s1, char *s2)
{
	int flag = 0, i = 0;

	while (s2[i] != '\0')
	{
		if (s2[i] == s1[0])
			flag++;
		i++;
	}

	return (flag);
}
