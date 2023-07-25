#include "shell.h"
/**
 * tokenize - tokenize
 * @input: input
 * @arg: array of arguments
 * @del: delimiter
 * Return: arg
 */
void tokenize(char *input, char **arg, char *del)
{
	char *token;
	int i = 0;

	token = strtok(input, del);
	while (token != NULL)
	{
		arg[i++] = token;
		token = strtok(NULL, del);
	}
	arg[i] = NULL;
	if (i == 0)
	{
		arg[0] = "";
		arg[1] = NULL;
	}
}
