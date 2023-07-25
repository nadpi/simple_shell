#include "shell.h"
/**
 * separator - separator
 *@input: input
 * Return: true or false
*/
bool separator(char *input)
{
	char *token, *sep_delimiter = ";", *command;
	int i, token_count = 0;
	char *commands[256], *arg[256];

	token = strtok(input, sep_delimiter);
	while (token != NULL)
	{
		commands[token_count++] = token;
		token = strtok(NULL, sep_delimiter);
	}
	for (i = 0; i < token_count; i++)
	{
		command = commands[i];
		tokenize(command, arg, " \n");
		if (arg[0] == NULL || _strcmp(arg[0], "") == 0)
			continue;
		if (_strcmp(arg[0], "exit") == 0)
			return (true);
		if (_strcmp(arg[0], "env") == 0)
		{
			env();
			continue;
		}
		if ((findandexec(arg[0], "/usr/bin/", arg, 0)) == 0)
			continue;
		else
		{
			pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
			findandexec(arg[0], "/usr/bin/", arg, 1);
		else
			waitpid(pid, NULL, 0);
		}
	}
	return (false);
}
