#include "shell.h"
/**
 * separator - separator
 *@input: input
 * Return: true or false
*/
bool separator(char *input)
{
    char *token;
    char *sep_delimiter = ";";
    char *command;
    int token_count = 0;
    char *commands[256];

    token = strtok(input, sep_delimiter);
    while (token != NULL)
    {
        commands[token_count++] = token;
        token = strtok(NULL, sep_delimiter);
    }

    for (int i = 0; i < token_count; i++)
    {
        command = commands[i];
        char *arg[256];
        tokenize(command, arg, " \n");
        if (arg[0] == NULL || strcmp(arg[0], "") == 0)
            continue;
        if (strcmp(arg[0], "exit") == 0)
		return (true);
        if (strcmp(arg[0], "env") == 0)
        {
            env();
            continue;
        }

        int flag = findandexec(arg[0], "/usr/bin/", arg, 0);
        if (flag == 0)
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
            {
                findandexec(arg[0], "/usr/bin/", arg, 1);
            }
            else
            {
                waitpid(pid, NULL, 0);
            }
        }
    }
    return (false);
}
