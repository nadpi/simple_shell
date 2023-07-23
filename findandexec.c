#include "shell.h"
/**
 * findandexec - find and execute 
 * @path: path
 * @command: command 
 * Return: always 0
 */
void findandexec (char *command, char *path)
{
	printf("si;pojf;opia");
	char **cleanpath = malloc(strlen(command) + strlen(path) + 1);
	while (command != NULL)
	{
		if (cleanpath == NULL)
		{
			perror("malloc");
			break;
		}

		*cleanpath = strcat(path,command);
		printf("%s",*cleanpath);
		if (access(cleanpath[0],X_OK) == 0)
		{
			execve(cleanpath[0], cleanpath, environ);
			perror("execve");
			break;
		}
		free(cleanpath);
	}
}
