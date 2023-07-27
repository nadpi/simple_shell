#include "shell.h"
bool separator(char *input)
{
    char *sep_delimiter = ";";
    char *token = strtok(input, sep_delimiter);

    while (token != NULL)
    {
        char *arg[256] = {NULL};
        tokenize(token, arg, " \n");

        if (arg[0] != NULL)
        {
            if (strcmp(arg[0], "exit") == 0)
                return true;
            else if (strcmp(arg[0], "env") == 0)
            {
                env();
            }
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
                    exit(1);
                }
                else
                {
                    waitpid(pid, NULL, 0);
                }
            }
        }

        token = strtok(NULL, sep_delimiter);
    }

    return false;
}

