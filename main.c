#include "shell.h"
/**
 * main - main function
 * Return: Always 0 (Success)
*/
int main(void)
{
	char *input = NULL, *newString;
	size_t bufsiz = 0;
	ssize_t charsRead = 0;
	bool breakloop = false;

	while (true)
	{
		printf("$ ");
		charsRead = getline(&input, &bufsiz, stdin);

		if (charsRead == -1)
			break;
		if (cmp("#", input) > 0)
		{
			newString = comments(input);
			strcpy(input, newString);
			free(newString);
		}

		if (separator(input))
		{
			breakloop = true;
		}

		if (breakloop == true)
			break;

	}

	free(input);
	return (0);
}
