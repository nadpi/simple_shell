#include "shell.h"
/**
 * tokenize - tokenize
 * @input: input
 * @arg: array of arguments
 * @del: delimiter
 * Return: arg
 */
int tokenize(char *input, char **arg, char *del)
{
	char *token;
	int i = 0, flag = 0;
/*
	if (cmp(";", input) == 0)
	{
		flag = 1;
		sep(input, arg, flag);
	}
	else if (cmp("&&", input) == 0)
	{
		flag = 2;
		sep(input, arg, flag);
	}
	else if (cmp("||", input) == 0)
	{
		flag = 3;
		sep(input, arg, flag);
	}*/
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
/*	return (flag);*/
}
