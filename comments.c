#include "shell.h"
/**
 * comments - comments
 *@input: input
 *Return: command string
*/
char *comments(char *input)
{
	int i = 0, j = 0;
	char *comString;

	 comString = malloc(_strlen(input) + 1);
	if (comString == NULL)
	{
		perror("malloc");
		exit(1);
	}

	while (input[i] != '\0')
	{
		if (input[i] == '#' && (i == 0 || input[i - 1] == ' '))
			break;
		comString[j] = input[i];
		j++;
		i++;
	}
	comString[j] = '\0';
	return (comString);
}
