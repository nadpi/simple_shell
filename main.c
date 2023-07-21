#include "shell.h"
/**
 * main - main
 * Return: always 0 (Success)
 */

int main(int argc, char **argv)
{
	char *input = NULL;
	size_t bufsiz = 0;
	ssize_t charsRead = 0;
	char *arg[256];
	int i = 0;
	char *token;
	pid_t pid;
	int status;

	while (true)
	{
		pid = fork();

		if (pid == -1)
		{
		perror("./shell");
		return (1);
		}
		else if (pid == 0)
		{
		token = strtok(input, " \n");
		while (token != NULL)
		{
			arg[i++] = token;
			token = strtok(NULL, " \n");
		}
		arg[i] = NULL;
			execve(arg[0], arg, environ);
		perror("./shell");
		return (1);
		}
		else
		{
		waitpid(pid, &status, 0);
		printf("$ ");
		charsRead = getline(&input, &bufsiz, stdin);
		}
	}
	return (0);
}
