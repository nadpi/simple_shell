#include "shell.h"
/**
 * comments - comments
 *@input: input
 *Return: command string
*/
char *comments(char *input)
{
	int i = 0;
	char *comString;

	 comString = malloc(_strlen(input) + 1);
	if (comString == NULL)
	{
		perror("malloc");
		exit(1);
	}

	while (input[i] != '#')
	{
		comString[i] = input[i];
		i++;
	}
	comString[i++] = '\0';
	return (comString);
}
