#include "shell.h"
/**
 * findandexec - find and execute
 * @path: path
 * @command: command
 * @arg: arg
 * @option: option
 * Return: always 0
 */
int findandexec(char *command, char *path, char **arg, int option)
{
	char *cleanpath;
	int flag = 1;

	if (arg[0] == NULL)
	{
		flag = 2;
		return (flag);
	}
	if (cmp("/", arg[0]) > 0 && option == 1)
	{
		execve(arg[0], arg, NULL);
		perror("./shell");
	}
	else if (cmp("/", arg[0]) == 0)
	{
		cleanpath = malloc(_strlen(path) + _strlen(command) + 2);
	if (cleanpath == NULL)
	{
		perror("malloc");
		exit(1);
	}
	_strcpy(cleanpath, path);
	_strcat(cleanpath, command);
	if (access(cleanpath, X_OK) == 0)
	{
		if (option == 1)
		{
		execve(cleanpath, arg, NULL);
		exit(2);
		}
		flag = 1;
	}
	else
	{
		fprintf(stderr, "%s: command not found\n", command);
		flag = 2;
	}
		free(cleanpath);
	}
	return (flag);
}
