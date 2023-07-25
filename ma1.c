#include "shell.h"
/**
 * main - main
 * Return: always 0 (Success)
 */

int main(int argc, char **argv)
{
	char *input = NULL, *arg[256], *token, *def_path = "/usr/bin/", *newString;
	size_t bufsiz = 0;
	ssize_t charsRead = 0;
	int status, flag = 0, i = 0;
	pid_t pid;

	while (true)
	{
		printf("M&N$ ");
		charsRead = getline(&input, &bufsiz, stdin);

		 if (cmp("#", input) > 0)
		 {
            		newString = comments(input);
            		strcpy(input, newString);
            		free(newString); // free memory allocated by comments()
		 }	
		tokenize(input, arg, " \n");

		if (charsRead == -1 || strcmp(arg[0], "exit") == 0)
			break;
		if (strcmp(arg[0], "env") == 0)
                {
                        env();
                        continue;
                }
		flag = findandexec(arg[0], def_path, arg, 0);
		if (flag == 0)
			continue;
		else
		{
		pid = fork();

		if (pid == -1)
		{
		perror("fork");
		return (1);
		}
		else if (pid == 0)
		{
			flag = findandexec(arg[0], def_path, arg, 1);
		}
		else
			waitpid(pid, &status, 0);
		}
	}
	free(input);
	return (0);
}
