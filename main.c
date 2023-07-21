#include "shell.h"
/**
 * main - main
 * Return: always 0 (Success)
 */
int main(void)
{
	char *input = NULL;
	size_t bufsiz = 0;
	ssize_t charsRead = 0;
	char *args[256];
	int i = 0;
	char *token;
	pid_t pid;
	int status;

	while (true)
	{
		pid = fork();
		token = strtok(input, " \n");
		while (token != NULL) {
			args[i++] = token;
			token = strtok(NULL, " \n");
		}
		args[i] = NULL;

		if (pid == -1)
		{
		perror("fork");
		return (1);
		}
		else if (pid == 0)
		{
		execve(args[0], args, NULL);
		perror("execve");
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
