#include "shell.h"
/**
 * main - main
 * Return: always 0 (Success)
 */

int main(int argc, char **argv)
{
	int z = 0;
	char *input = NULL;
	size_t bufsiz = 0;
	ssize_t charsRead = 0;
	char *arg[256];
	int i = 0;
	char *token;
	pid_t pid;
	int status;
	char *def_path = "/usr/bin/"; 

	while (true)
	{
		printf("M&N$ ");
		charsRead = getline(&input, &bufsiz, stdin);

		if (charsRead == -1)
			break;

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
		return (1);
		}
		else if (pid == 0)
		{	
			tokenize(input, arg);

			if (arg[0] == NULL)
			continue;

			if (cmp("/",arg[0]) > 0)
			{
			execve(arg[0], arg, environ);
			perror("./shell");
			}
			else if (cmp("/", arg[0]) == 0)
			{
				findandexec(arg[0],def_path, arg);
			}
		}
		else
			waitpid(pid, &status, 0);
	}
	free(input);
	return (0);
}
