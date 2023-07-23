#include "shell.h"
/**
 * findandexec - find and execute 
 * @path: path
 * @command: command 
 * @arg: arg
 * Return: always 0
 */
void findandexec (char *command, char *path, char **arg)
{
	char *cleanpath = malloc(strlen(path) + strlen(command) + 1);
	if (cleanpath == NULL)
	{
		perror("malloc");
		return;
	}

	strcpy(cleanpath, path);
	strcat(cleanpath, command);

	if (access(cleanpath, X_OK) == 0)
	{
		execve(cleanpath, arg, environ);
		perror("execve");
		free(cleanpath);
		exit(1);
	}
	else
	{
		fprintf(stderr, "%s: command not found\n", command);
	}

	free(cleanpath);
}
