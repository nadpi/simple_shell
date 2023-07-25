#include "shell.h"
/**
 * tokenize - tokenize
 * @input: input
 * @arg: array of arguments
 * Return: arg
 */
void tokenize(char *input, char **arg)
{
	char *token;
	int i = 0;

	token = strtok(input, " \n");
	while (token != NULL)
	{
		arg[i++] = token;
		token = strtok(NULL, " \n");
	}
	arg[i] = NULL;
}
